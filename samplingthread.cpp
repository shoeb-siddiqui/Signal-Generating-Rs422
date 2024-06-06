
#include "samplingthread.h"

#include<QDebug>
#include<QPoint>
#include<qwt_math.h>
#if QT_VERSION < 0x040600
#define qFastSin(x) :: sin(x)
#endif

samplingthread::samplingthread(QObject *parent) : QwtSamplingThread(parent)
{


}

samplingthread::~samplingthread()
{

}

void samplingthread::waveformfunc(double timeStamp)
{
    input.setX(timeStamp);
    input.setY(votages);
    inputvector.append(input);
    output.setX(timeStamp);

}

void samplingthread::waveformfunc1()
{
    output.setY(votages1);
    outputvector.append(output);
}

void samplingthread::sample(double elapsed)
{
    switch (wave) {
    case 1:

        votages = SINEWAVE(elapsed,1.0,false,1.0,5,0.0);
        waveformfunc(elapsed);
        break;


    case 2:

        votages = STEPAUTO(elapsed,250/1000.0,2.0);
        waveformfunc(elapsed);
        break;

    case 3:

        votages = STEPMANUAL(elapsed,5.0);
        waveformfunc(elapsed);
        break;


    case 4:



        waveformfunc(elapsed);
        break;

    case 5:

        votages = TRIANGLE(elapsed,1.0,false,1.0,5,0.0);
        waveformfunc(elapsed);
        break;


    case 6:

        votages = SAWTOOTH(elapsed,1.0,false,1.0,5,0.0);
        waveformfunc(elapsed);
        break;

    case 7:

        votages = SQUARE(elapsed,1.0,true,1.0,1,0.0);
        waveformfunc(elapsed);
        break;

    case 8:

        votages = pSTEPAUTO(elapsed,500.0/1000.0,1.0);
        waveformfunc(elapsed);
        break;

    case 9:

        votages = nSTEPAUTO(elapsed,500.0/1000.0,1.0);
        waveformfunc(elapsed);
        break;

    default:
        break;
    }

}

long double samplingthread::SINEWAVE(double timeStamp, double frequency, bool continuous, double amplitude, int cycle, double Bias)
{

    const double period = 1.0/frequency;
    double DATA = Bias;
    if(frequency > 0.0)
    {
        if((continuous) || !(cycle*period < timeStamp))
        {
            const long double x = ::fmod(timeStamp,period);
            DATA = Bias + (amplitude * sin(x/period*2*M_PI));  // for getting volatage of single wave
            return DATA;

        }
        else if(cycle*period < timeStamp || cycle*period+.01 > timeStamp)
            return DATA;
    }

    return DATA;
}

double samplingthread::STEPAUTO(double timeStamp, double Duration, double Voltage)
{
    double DATA = 0;
    if(timeStamp <= Duration)
    {
        DATA = 0;
    }

    else if(timeStamp <= 2*Duration)
    {
        DATA = Voltage;
    }

    else if(timeStamp <= 3*Duration)
    {
        DATA = 0;
    }

    else if(timeStamp <= 4*Duration)
    {
        DATA = -Voltage;
    }

    else if(timeStamp <= 5*Duration)
    {
        DATA = 0;
    }

    if(timeStamp <= 5*Duration)
    {
        return DATA;
    }

    return DATA;

}

double samplingthread::STEPMANUAL(double timeStamp, double Voltage)
{

    double DATA = 0;
    DATA = Voltage;
    return DATA;

}

double samplingthread::StallForcetest(double timeStamp, double amplitude, double frequency)
{
    double time;
    time = 1/frequency;
    if(timeStamp<=time/2)
    {
        return amplitude;
    }

    else if(timeStamp <= time)
    {
        return -amplitude;
    }
    else
    {
        return 0;
    }

}

double samplingthread::pSTEPAUTO(double timeStamp, double Duration, double Voltage)
{
    double DATA = 0;
    if(timeStamp <= Duration)
    {
        DATA = 0;

    }
    else if(timeStamp <= 2*Duration)
    {
        DATA = Voltage;
    }
    else if(timeStamp <= 3*Duration)
    {
        DATA = 0;
    }

    return DATA;
}

double samplingthread::nSTEPAUTO(double timeStamp, double Duration, double Voltage)
{
    double DATA = 0;
    if(timeStamp <= 3*Duration)
    {
        DATA = 0;
    }

    else if(timeStamp <= 4*Duration)
    {
        DATA = -Voltage;
    }


    else if(timeStamp <= 5*Duration)
    {
        DATA = 0;
    }

    if(timeStamp <= 5*Duration)
    {
        return DATA;
    }

    return DATA;

}

double samplingthread::RAMP(double timeStamp, double amplitude, double Voltage, double Duration, double sample, double value)
{
    static double sample_count = sample;
    static double voltage_count = Voltage;
    static double value_count = value;
    if(sample_count >= 0)
    {
        if(sample_count > 3* (amplitude/voltage_count))
        {
            if(!(timeStamp <= Duration))
            {
                value_count += voltage_count;
                --(sample_count);
            }

            if(timeStamp <= Duration)
            {
                value_count = 0;
            }
        }

        else if(sample_count > (amplitude/voltage_count))
        {
            if(!(timeStamp < Duration))
            {
                value_count -= voltage_count;
                --(sample_count);
            }
            else if(sample_count > 0)
            {
                if(!(timeStamp < Duration))
                {
                    value_count += voltage_count;
                    --(sample_count);
                }
            }

            return value_count;
        }

        else
            return 0;
    }
}

double samplingthread::TRIANGLE(double timeStamp, double frequency, bool continuous, double amplitude, int cycle, double Bias)
{

    const double period = 1/frequency;
    double DATA = Bias;
    if(frequency > 0.0)
    {
        if((continuous) || !(cycle * period < timeStamp))
        {
            const long double x= ::fmod(timeStamp,period);
            double sinvalue = 1 * sin(x/period * 2* M_PI);
            DATA = ((2*amplitude)/M_PI*asin(sinvalue))+Bias;
            return DATA;

        }

        else if(cycle * period < timeStamp ||cycle*period+.01 > timeStamp)
            return DATA;
    }

    return DATA;

}

double samplingthread::SAWTOOTH(double timeStamp, double frequency, bool continuous, double amplitude, int cycle, double Bias)
{

    const double period = 1/frequency;
    double DATA = Bias;
    if(frequency > 0.0)
    {
        if((continuous)||!(cycle * period < timeStamp))
        {
            const long double x= ::fmod(timeStamp,period);
            DATA = Bias + (amplitude*(x-floor(x)));
            return DATA;
        }
        else if(cycle * period < timeStamp||cycle * period +.01>timeStamp)
            return DATA;
    }

    return DATA;

}

double samplingthread::SQUARE(double timeStamp, double frequency, bool continuous, double amplitude, int cycle, double Bias)
{
    const double period = 1.0/frequency;
    double DATA = Bias;
    if(frequency > 0.0)
    {
        if((continuous) ||! (cycle * period < timeStamp))
        {

            const long double x = ::fmod(timeStamp,period);
            double a = (1*sin(x/period*2*M_PI));
            if(a>=0)
            {
                DATA = amplitude + Bias;
            }

            else
            {
                DATA = -(amplitude +  Bias);
            }

            return DATA;


        }

        else if(cycle * period < timeStamp||cycle*period + .01>timeStamp)
            return DATA;

    }
    return DATA;
}





