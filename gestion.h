#ifndef GESTION_H
#define GESTION_H
#include <QDialog>
#include <QSqlQueryModel>
#include <QAbstractItemView>
#include"employe.h"
#include "shift.h"
#include "smtp.h"
#include <QFileDialog>
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include <QMediaPlayer>
#include "QSound"
#include "avions.h"
#include "constructeur.h"
#include "fournisseur.h"
#include "prodect.h"
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
#include "gerer_vols.h"
#include "destination.h"
#include "clients.h"
#include "promotions.h"
#include "parkingcode.h"
#include "abonnementcode.h"
#include <QSqlTableModel>
#include "anglais.h"
#include "arduino.h"
using namespace QtCharts;
namespace Ui{
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();


private slots:
    //employe/shift slots
    void on_pushButton_clicked();

    void on_ok_clicked();

void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_ok_shift_clicked();


    void on_comboBox_employe_activated(const QString &arg1);

    void on_comboBox_ajoutID_activated(const QString &arg1);

    void on_comboBox_ajoutshift_activated(const QString &arg1);

    void on_comboBox_modemploye_activated(const QString &arg1);

    void on_comboBox_employe_activated(int index);

    void on_shift_sup_activated(const QString &arg1);

    void on_shif_mod_activated(const QString &arg1);

    void on_comboBox_ajoutshift_2_activated(const QString &arg1);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_5_clicked();

    void on_shif_mod_activated(int index);


    void on_recherche_employe_textChanged(const QString &arg1);



    void on_recherche_shift_textChanged(const QString &arg1);

    void on_tri_shift_activated(int index);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_tri_shift_3_activated(int index);

    void sendMail();
    void mailSent(QString);
    void browse();



   void makePolt();
   void on_pushButton_4_clicked();

   void on_pushButton_6_clicked();
   void on_verticalSlider_sliderMoved(int position);

   //avions/cons slots :
   void on_ajouter_constructeur_clicked();

   void on_supprimer_constructeur_clicked();

   void on_suppavions_clicked();

   void on_ajouter_av_clicked();

   void on_id_constructeur_activated(const QString &arg1);

   void on_id_constructeur_3_activated(const QString &arg1);

   void on_modifier_av_clicked();

   void on_modifier_constructeur_clicked();

   void on_chercher_constructeur_textChanged(const QString &arg1);

   void on_chercher_avion_textChanged(const QString &arg1);


   void on_trier_selon_id_clicked();
   void on_trier_selon_id_desc_clicked();

   void on_trier_selon_etat_clicked();
   void on_trier_selon_etat_desc_clicked();

   void on_trier_selon_id_constructeur_clicked();
   void on_trier_selon_id_constructeur_desc_clicked();



   void on_pushButton_tri_id_const_clicked();
   void on_pushButton_tri_id_const_desc_clicked();

   void on_pushButton_tri_nom_const_clicked();
   void on_pushButton_tri_nom_const_desc_clicked();

   void on_pushButton_tri_mail_const_clicked();
   void on_pushButton_tri_mail_const_desc_clicked();
   void on_comboBox_mod_av_activated(const QString &arg1);

   void on_comboBox_id_const_modi_activated(const QString &arg1);

   void on_comboBox_mod_av_currentTextChanged(const QString &arg1);

   void on_comboBox_id_const_modi_currentTextChanged(const QString &arg1);



    void on_enpanne_clicked(bool checked);

    void on_fonctionnel_clicked(bool checked);


    void on_checkBox_toggled(bool checked);
    void on_checkBox_2_toggled(bool checked);
    void on_checkBox_3_toggled(bool checked);
    void initialiser();
    void initialiser_modifier();
    void initialiser_supp();
    void refresh();
    void on_checkBox_id_avion_toggled(bool checked);
    void on_checkBox_etat_avion_toggled(bool checked);
    void on_checkBox_id_const_avion_toggled(bool checked);
    void makePolt2();
    void sendMail_constructeur();

    //gestion produit fournisseur :

    void makePlot_fournisseur();

    void on_Ajouter_produit_clicked();

    void on_supprimer_produit_clicked();

    void on_ajouter_fournisseur_clicked();

    void on_supprimer_fournisseur_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_modidfournisseur_activated(const QString &arg1);

    void on_modifierfournisseur_clicked();


    void on_comboBox_modidproduit_activated(const QString &arg1);

    void on_comboBoxmodidproduitfournisseur_activated(const QString &arg1);

    void on_modifierproduit_clicked();


    void on_Recherche_fournisseur_clicked();
    void sendMail_fournisseur();

    //vols et destionation :
    void on_AJOUTER_VOLS_clicked();

    void on_comboBox_ID_DEST_activated(const QString &arg1);

    void on_AJOUTER_DESTINATION_clicked();

    void on_supprimer_dest_clicked();


    void on_supprimervols_clicked();

    void on_comboBox_status_activated(const QString &arg1);


    void on_comboBox_ID_DEST_mod_activated(const QString &arg1);



    void on_comboBox_ID_DEST_mod_vol_activated(const QString &arg1);

    void on_comboBox_status_mod_activated(const QString &arg1);


    void on_comboBox_N_VOL_mod_activated(const QString &arg1);

    void on_mod_dest_clicked();

    void on_mod_vol_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);
    void makePolt_dest();

   // client promo :
    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_ajouter_promotion_clicked();



    void on_supprimer_promotion_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();





    void on_lineEdit_chercher_client_cursorPositionChanged();








    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_numpasseport_activated(const QString &arg1);

    void on_comboBox_id_promo_mod_activated(const QString &arg1);


    void on_comboBox_num_passeport_mod_activated(const QString &arg1);



    void on_lineEdit_chercher_promo_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_id_mail_activated(const QString &arg1);

    void on_pushButtontrinom_clicked();
    void sendMail_promo();

   void makepolt_client();

    void on_pushButton_tri_promo_clicked();


    void on_pushButton_10_clicked();
    //parking abonn:
    void on_pushButton_RP_clicked();

    void on_pushButton_NBE_clicked();

    void on_pushButton_NBP_clicked();

    void on_ajouterparking_clicked();

    void on_supp_park_clicked();

    void on_modifier_parking_clicked();

    void stat();
    void on_pushButton_R_clicked();

    void sendMail_abon();

    void on_ajouter_abon_clicked();

    void on_supp_abon_clicked();

    void on_midifer_abon_clicked();


    void on_sendBtn_abon_clicked();

    void on_versionanglais_clicked();

    void on_comboBox_mod_client_activated(const QString &arg1);

    void on_comboBox_suppclients_activated(const QString &arg1);


    void on_comboBox_supp_promo_activated(const QString &arg1);

    void on_sitee_clicked();

    void on_checkBox_son_on_toggled(bool checked);

    void on_checkBox_so_off_toggled(bool checkedd);

    void on_checkBox_notification_on_toggled(bool checked);

    void on_checkBox_notification_off_toggled(bool checked);



private:
    //employe shift
    Ui::gestion *ui;
    employe tmpemploye;
    shift tmpsh;
    int selected=-1;
    int mod_selected=-1;
    QString NEW_date,NEW_shifft;
    QStringList files;
    QMediaPlayer  *music =new QMediaPlayer() ;
   //avions constructeur :
    avions tmpavions;
    constructeur tmpconstructeur;
    QString etat;
    int k=0,son=1,notificationn=1;
    // fourniseur produit :
    prodect tmpproduit ;
    fournisseur tmpfournisseur;
    // vols et  dest
    gerer_vols tmpvols;
    destination tmpdest;
    // client promo :
    Clients tmpclient;
    Promotions tmppromo;
    //parking abonnement ::
    parkingCode tmpparking;
    abonnementCode  tmpabonnement;
    Arduino a;

};

#endif // GESTION_H
