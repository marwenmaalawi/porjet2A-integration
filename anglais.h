#ifndef ANGLAIS_H
#define ANGLAIS_H
#include <QDialog>
#include "clients.h"
#include"promotions.h"
#include <QDialog>
#include <QSqlQueryModel>
#include <QAbstractItemView>
#include "smtp.h"
#include <QFileDialog>
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include <QMediaPlayer>
#include "QSound"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QMap>
#include <QVector>
#include <QtCharts/QLineSeries>
#include <QtWidgets>
#include <QSystemTrayIcon>
#include <QSqlTableModel>
using namespace QtCharts;



namespace Ui {
class anglais;
}

class anglais :public QDialog
{
     Q_OBJECT

public:
    explicit anglais(QWidget *parent = nullptr);
    ~anglais();


    private slots:

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_ajouter_promotion_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_supprimer_promotion_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_chercher_client_cursorPositionChanged();

    void on_lineEdit_id_3_cursorPositionChanged();

    void on_pushButton_6_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);


    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();
    void makepolt_client();
    void sendMail_promo();

    void on_comboBox_id_mail_activated(const QString &arg1);

    void on_sendBtn_promo_clicked();

private:
    Ui::anglais *ui;
    Clients tmpclient;
    Promotions tmppromo;
};

#endif // ANGLAIS_H
