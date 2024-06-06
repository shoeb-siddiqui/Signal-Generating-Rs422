#ifndef SAMPLINGTHREAD_H
#define SAMPLINGTHREAD_H

#include<qwt_sampling_thread.h>
#include<QPoint>
#include<stdio.h>
#include<QFile>
#include<QVector>



class samplingthread : public QwtSamplingThread
{

    Q_OBJECT
public:
    samplingthread(QObject *parent=NULL);
    QPointF input;
    QVector<QPointF> inputvector;
    QPointF output,CRC;
    QVector<QPointF> outputvector,CRCvector;
    qreal votages;
    ~samplingthread();
    int wave;


    void waveformfunc(double timeStamp);
protected:
    virtual void sample(double elapsed);
private:
long double SINEWAVE(double timeStamp,double frequency,bool continuous,double amplitude,int cycle,double Bias);
double STEPAUTO(double timeStamp,double Duration,double Voltage);
double STEPMANUAL(double timeStamp,double Voltage);
double StallForcetest(double timeStamp,double amplitude,double frequency);
double pSTEPAUTO(double timeStamp,double Duration,double Voltage);
double nSTEPAUTO(double timeStamp,double Duration,double Voltage);
double RAMP(double timeStamp,double amplitude,double Voltage,double Duration,double sample,double value);
double TRIANGLE(double timeStamp,double frequency,bool continuous,double amplitude,int cycle,double Bias);
double SAWTOOTH(double timeStamp,double frequency,bool continuous,double amplitude,int cycle,double Bias);
double SQUARE(double timeStamp,double frequency,bool continuous,double amplitude,int cycle,double Bias);
};

#endif // SAMPLINGTHREAD_H
