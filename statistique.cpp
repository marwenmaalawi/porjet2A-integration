#include "statistique.h"
#include "ui_statistique.h"
#include"QSqlRecord"
#include"QSqlQuery"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    this->setWindowTitle("statistiques");
    makePolt();
}

statistique::~statistique()
{
    delete ui;
}

void statistique::makePolt()
{
    //connection c;
     //c.creatconnection();



       ///////////////////////////////////////////////////////////////////////
       // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlotfournisseur->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlotfournisseur->xAxis, ui->customPlotfournisseur->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("Repartition des fournisseus");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;

          QSqlQuery q;
          int i=0;
          q.exec("select ADRESSE_MAIL from FOURNISSEURS ");
          while (q.next()) {
              QString adresse= q.value(0).toString();
              i++;
              ticks<<i;
              labels <<adresse;
          }
          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlotfournisseur->xAxis->setTicker(textTicker);
          ui->customPlotfournisseur->xAxis->setTickLabelRotation(60);
          ui->customPlotfournisseur->xAxis->setSubTicks(false);
          ui->customPlotfournisseur->xAxis->setTickLength(0, 4);
          ui->customPlotfournisseur->xAxis->setRange(0, 8);
          ui->customPlotfournisseur->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlotfournisseur->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlotfournisseur->xAxis->grid()->setVisible(true);
          ui->customPlotfournisseur->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlotfournisseur->xAxis->setTickLabelColor(Qt::white);
          ui->customPlotfournisseur->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlotfournisseur->yAxis->setRange(0,10);
          ui->customPlotfournisseur->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlotfournisseur->yAxis->setLabel("Statistiques");
          ui->customPlotfournisseur->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlotfournisseur->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlotfournisseur->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlotfournisseur->yAxis->grid()->setSubGridVisible(true);
          ui->customPlotfournisseur->yAxis->setTickLabelColor(Qt::white);
          ui->customPlotfournisseur->yAxis->setLabelColor(Qt::white);
          ui->customPlotfournisseur->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlotfournisseur->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select NOM_FOURNISSEUR from FOURNISSEURS ");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlotfournisseur->legend->setVisible(true);
          ui->customPlotfournisseur->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlotfournisseur->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlotfournisseur->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlotfournisseur->legend->setFont(legendFont);
          ui->customPlotfournisseur->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);






}
