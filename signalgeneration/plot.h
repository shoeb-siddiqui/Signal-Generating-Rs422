#ifndef PLOT_H
#define PLOT_H

#include <QObject>
#include <qvector.h>
#include <QPointF>
#include <QPen>
#include <QDebug>
#include "qwt.h"
#include "qwt_plot.h"
#include "qwt_plot_item.h"
#include "qwt_plot_curve.h"
#include "qwt_legend.h"
#include "qwt_plot_grid.h"
#include "qwt_series_data.h"
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>
#include<qwt_symbol.h>
#include<qwt_text.h>



class Plot : public QwtPlot
{
    Q_OBJECT
public:
    explicit Plot(QWidget *parent = 0);


QwtPlotCurve *cmdcurve;
QwtPlotGrid *grid;
QwtText *text;
QwtPlotZoomer *zoom;
QwtSymbol *psymbol,*csymbol;
void createcurve();

QwtPointSeriesData *command_Seriesdata;
QPen pen;

void setcurvedata(QVector<QPointF> &input);



};

#endif // PLOT_H
