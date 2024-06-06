#include "plot.h"

Plot::Plot(QWidget *parent) : QwtPlot(parent)
{
psymbol = new QwtSymbol(QwtSymbol::XCross,QBrush(Qt::yellow),QPen(Qt::red,1),QSize(4,4));

createcurve();

command_Seriesdata = new QwtPointSeriesData;

grid = new QwtPlotGrid;
grid->setMajorPen(QPen(Qt::blue,1,Qt::DotLine));
grid->attach(this);

QwtPlotCanvas *canvas1 = new QwtPlotCanvas();
canvas1->setLineWidth(1);
canvas1->setFrameStyle(QFrame::Box|QFrame::Plain);
canvas1->setBorderRadius(1);

this->setCanvasBackground(QColor(Qt::white));
zoom = new QwtPlotZoomer(canvas());
zoom->setRubberBandPen((QPen)Qt::black);
zoom->setTrackerPen((QPen)Qt::black);

( void )new QwtPlotMagnifier(canvas1);

}

void Plot::createcurve()
{
    cmdcurve = new QwtPlotCurve("INPUTCMD");
    cmdcurve->setPen(QPen(Qt::red,2));
    cmdcurve->attach(this);
    insertLegend(new QwtLegend(),QwtPlot::BottomLegend);
    cmdcurve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
    cmdcurve->setLegendIconSize(QSize(15,10));

}


void Plot::setcurvedata(QVector<QPointF> &input)
{
    command_Seriesdata->setSamples(input);
    cmdcurve->setData(command_Seriesdata);
    this->replot();
}
