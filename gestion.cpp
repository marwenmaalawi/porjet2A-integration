
#include "gestion.h"
#include "employe.h"
#include "ui_gestion.h"
#include <QDebug>
#include "QAbstractItemModel"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/qprintdialog.h>
#include <QAbstractPrintDialog>
#include <qprinter.h>
#include "qcustomplot.h"

#include "QMessageBox"
gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    //employe,shift refresh ..
makePolt();
    ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
 connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
 music->setMedia(QUrl("C:/Users/esprit/Desktop/True Detective - Intro Opening Song - Theme (The Handsome Family - Far From Any Road) + LYRICS.mp3"));
 //onstructeur/ avions refresh

makePolt2();

 ui->tab_avions->setModel(tmpavions.afficher_avions());
 ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
 ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
 ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
 ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());
 ui->comboBox_id_const_modi->setModel(tmpconstructeur.afficher_constructeurlist());

 ui->comboBox_id_supp->setModel(tmpavions.afficher_avionslist());
 ui->comboBox_id_supp_const->setModel(tmpconstructeur.getIdModel());

 ui->comboBox_mail->setModel(tmpconstructeur.getMailModel());

 connect(ui->sendBtn_cons, SIGNAL(clicked()),this, SLOT(sendMail_constructeur()));
 connect(ui->exitBtn_cons, SIGNAL(clicked()),this, SLOT(close()));

 //produit fournisseur refresh
 ui->tab_produit->setModel(tmpproduit.afficher_produit());
 ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
  ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());

makePlot_fournisseur();

connect(ui->sendBtn_fournisseur, SIGNAL(clicked()),this, SLOT(sendMail_fournisseur()));
    connect(ui->exitBtn_fournisseur, SIGNAL(clicked()),this, SLOT(close()));
//vols destination refresh
   makePolt_dest();
    ui->tab_vols->setModel(tmpvols.afficher_vol());
    ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
    ui->tab_dest->setModel(tmpdest.afficher_dest());
    ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
     ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
     ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

//CLIENT promotion refresh
     ui->tableView_affiche_client->setModel(tmpclient.afficher());
     ui->tab_promotions->setModel(tmppromo.afficher());
  ui->comboBox_numpasseport->setModel(tmpclient.afficher_listclient());
  ui->comboBox_num_passeport_mod->setModel(tmpclient.afficher_listclient());
  ui->comboBox_id_mail->setModel(tmppromo.afficher_listpromo());
  ui->comboBox_id_promo_mod->setModel(tmppromo.afficher_listpromo());
  connect(ui->sendBtn_promo, SIGNAL(clicked()),this, SLOT(sendMail_promo()));
   ui->comboBox_mod_client->setModel(tmpclient.afficher_listclient());
   ui->comboBox_suppclients->setModel(tmpclient.afficher_listclient())  ;
   ui->comboBox_supp_promo->setModel(tmppromo.afficher_listpromo());
           makepolt_client();
 //parking abonement refresh
 ui->tab_afficher_client_park->setModel(tmpparking.afficher());
ui->comboBox_3_park->addItem("1");

ui->comboBox_3_park->addItem("2");
ui->comboBox_3_park->addItem("3");

ui->comboBox_3_park->addItem("4");
 ui->lineEditcin_park->setStyleSheet("color: red;");
 ui->lineEditprenom_park->setStyleSheet("color: red;");
stat();
 ui->tab_afficher_client->setModel(tmpabonnement.afficher());

}
gestion::~gestion()
{
    delete ui;
}
//gestion employe/shift :

void gestion::on_pushButton_clicked()
{ QString ID_EMPLOYE=ui->lineEdit_ID_EMPLOYE->text();
 QString NOM=ui->lineEdit_NOM->text();
 QString PRENOM=ui->lineEdit_PRENOM->text();
 QString ASSIDUITE=ui->lineEdit_ASSIDUITE->text();
 QString AVANTAGE=ui->lineEdit_AVANTAGE->text();
 int SOLDE_DE_CONGE=ui->lineEdit_SOLDE_DE_CONGE->text().toInt();
 int SALAIRE=ui->lineEdit_SALAIRE->text().toInt() ;
 int ABSENCE=ui->lineEdit_ABSENCE->text().toInt();
 int RANG=ui->lineEdit_RANG->text().toInt() ;
 employe  e(ID_EMPLOYE,ASSIDUITE,AVANTAGE,SOLDE_DE_CONGE, ABSENCE,SALAIRE,RANG,NOM,PRENOM);
if (SOLDE_DE_CONGE+ABSENCE==30)
{ if (SALAIRE>500)
    {bool test=e.ajouter_employe();
if (test)
{   ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
 makePolt();
 QMessageBox::information(nullptr,QObject::tr("ajouter employe"),
   QObject::tr("employe ajoute.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
    QObject::tr("id existe deja  !.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);}
else QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                            QObject::tr("salaire ne peut pas etre inferieur de 500 dinar   !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

else

QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
    QObject::tr("SOLDE DE CONGE NE PEUT PAS DEPPASSER 30 JOURS  !.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion::on_ok_clicked()
{
    if(selected!=-1){
    bool test=tmpemploye.supprimer_employe(tmpemploye.get_ID_EMPLOYE());
    if(test)
    {

        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     makePolt();
     QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("employe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
 }else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                            QObject::tr("merci de choisir un ID !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestion::on_pushButton_2_clicked()
  {
    QString NOM=ui->lineEdit_NOM_2->text();
    QString PRENOM=ui->lineEdit_PRENOM_2->text();
    QString ASSIDUITE=ui->lineEdit_ASSIDUITE_2->text();
    QString AVANTAGE=ui->lineEdit_AVANTAGE_2->text();
    int SOLDE_DE_CONGE=ui->lineEdit_SOLDE_DE_CONGE_2->text().toInt();
    int SALAIRE=ui->lineEdit_SALAIRE_2->text().toInt() ;
    int ABSENCE=ui->lineEdit_ABSENCE_2->text().toInt();
    int RANG=ui->lineEdit_RANG_2->text().toInt() ;
    employe  e(tmpemploye.get_ID_EMPLOYE(),ASSIDUITE,AVANTAGE,SOLDE_DE_CONGE, ABSENCE,SALAIRE,RANG,NOM,PRENOM);
   if((tmpemploye.get_ID_EMPLOYE()=="")||(NOM=="")||(PRENOM=="")||(ASSIDUITE=="")||(AVANTAGE=="")||(ui->lineEdit_SOLDE_DE_CONGE_2->text()=="")||(ui->lineEdit_SALAIRE_2->text()=="")||(ui->lineEdit_ABSENCE_2->text()=="")||(ui->lineEdit_RANG_2)->text()=="")
{QMessageBox::information(nullptr,QObject::tr("verifier champs"),
                          QObject::tr("merci de remplir tous les champs \n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
   }
    else{       bool test=e.modifier_employe();
   if (test==true)
   {

       ui->tab_employe->setModel(tmpemploye.afficher_employe());
    ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
    ui->tab_shift->setModel(tmpsh.afficher_shift());
    ui->comboBox_employe->setModel(tmpemploye.afficher_list());
    ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
    ui->shift_sup->setModel(tmpsh.afficher_list());
    ui->shif_mod->setModel(tmpsh.afficher_list());
    makePolt();
    QMessageBox::information(nullptr,QObject::tr("modifier employe"),
      QObject::tr("employe modifier.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else{
   QMessageBox::critical(nullptr, QObject::tr("modifier employe"),
       QObject::tr("merci de verifiez l'id !.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   }
}



void gestion::on_pushButton_3_clicked()
{
bool test=tmpsh.ajouter_shift();
if (test)
{

    ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
 makePolt();
 QMessageBox::information(nullptr,QObject::tr("ajouter employe"),
   QObject::tr("l'employe a ete bien affecte .\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{QMessageBox::critical(nullptr, QObject::tr("Ajouter employe"),
    QObject::tr("l'employe est deja affecter a ce shift  !.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void gestion::on_comboBox_ajoutID_activated(const QString &arg1)
{
    tmpsh.set_ID_EMPLOYE(arg1);

}
void gestion::on_dateEdit_dateChanged(const QDate &date)
{
    tmpsh.set_DATEDUJOUR(date.toString());
}

void gestion::on_comboBox_ajoutshift_activated(const QString &arg1)
{tmpsh.set_SHIFFT(arg1);}



void gestion::on_ok_shift_clicked()
{


    bool test=tmpsh.supprimer_shift();
        if (test)
    {

        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     makePolt();
     QMessageBox::information(nullptr, QObject::tr("Supprimer shift"),
                    QObject::tr("shift supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("Supprimer shift"),
                    QObject::tr("merci de selectionner un shift   !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}



void gestion::on_comboBox_employe_activated(const QString &arg1)
{
     tmpemploye.set_ID_EMPLOYE(arg1);
}







void gestion::on_comboBox_modemploye_activated(const QString &arg1)
{
    tmpemploye.set_ID_EMPLOYE(arg1);
    tmpemploye.chercher();
    ui->lineEdit_NOM_2->setText(tmpemploye.get_NOM());
    ui->lineEdit_PRENOM_2->setText(tmpemploye.get_PRENOM());
    ui->lineEdit_ASSIDUITE_2->setText(tmpemploye.get_ASSIDUITE());
    ui->lineEdit_AVANTAGE_2->setText(tmpemploye.get_AVANTAGES());
    ui->lineEdit_SOLDE_DE_CONGE_2->setText(QString ::number(tmpemploye.get_SOLDE_DE_CONGE()));
    ui->lineEdit_SALAIRE_2->setText(QString::number(tmpemploye.get_SALAIRE()));
    ui->lineEdit_ABSENCE_2->setText(QString::number(tmpemploye.get_ABSENCE()));
    ui->lineEdit_RANG_2->setText(QString::number(tmpemploye.get_RANG())) ;

}

void gestion::on_comboBox_employe_activated(int index)
{
selected=index;
}

void gestion::on_shift_sup_activated(const QString &arg1)
{
    tmpsh.generate_data(arg1);
}

void gestion::on_shif_mod_activated(const QString &arg1)
{
    tmpsh.generate_data(arg1);
    ui->lineEdit_shift->setText(tmpsh.get_SHIFFT());
    ui->lineEdit_date->setText(tmpsh.get_DATEDUJOUR());
}

void gestion::on_comboBox_ajoutshift_2_activated(const QString &arg1)
{
    NEW_shifft=arg1;
}

void gestion::on_dateEdit_2_userDateChanged(const QDate &date)
{
    NEW_date=date.toString();
}

void gestion::on_pushButton_5_clicked()
{
    if(mod_selected!=-1){
    if(NEW_shifft==""){
        NEW_shifft=tmpsh.get_SHIFFT();
    }
    if(NEW_date==""){
        NEW_date=tmpsh.get_DATEDUJOUR();
    }
    if(tmpsh.modifier_shift(NEW_date,NEW_shifft)){
        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     makePolt();
     QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                    QObject::tr("shift modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }else{
        QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                       QObject::tr("shift déja existe.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }else{
        QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                       QObject::tr("merci de choisir un ID .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void gestion::on_shif_mod_activated(int index)
{
    mod_selected=index;
}


void gestion::on_recherche_employe_textChanged(const QString &arg1)
{
    ui->tab_employe->setModel(tmpemploye.chercher_employe(arg1));
}


void gestion::on_recherche_shift_textChanged(const QString &arg1)
{
    ui->tab_shift->setModel(tmpsh.chercher_shift(arg1));

}

void gestion::on_tri_shift_activated(int index)
{if (index==0){ui->tab_shift->setModel(tmpsh.afficher_shift());}
 if(index==1) {ui->tab_shift->setModel(tmpsh.afficher_trishift("datedujour"));}
 if(index==2) {ui->tab_shift->setModel(tmpsh.afficher_trishift("shifft"));}
if(index==3) {ui->tab_shift->setModel(tmpsh.afficher_trishift("id_employe"));}


}

void gestion::on_comboBox_activated(int index)
{if (index==0){ui->tab_employe->setModel(tmpemploye.afficher_employe());}
 if (index==1){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("id_employe"));}
 if (index==2){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("assiduite"));}
 if (index==3){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("avantages"));}
 if (index==4){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("solde_de_conge"));}
 if (index==5){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("absence"));}
 if (index==6){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("salaire"));}
 if (index==7){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("rang"));}
 if (index==8){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("nom"));}
 if (index==8){ui->tab_employe->setModel(tmpemploye.afficher_triemploye("prenom"));}


}

void gestion::on_comboBox_2_activated(int index)
{if (index==0){ui->tab_employe->setModel(tmpemploye.afficher_employe());}
    if (index==1){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("id_employe"));}
    if (index==2){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("assiduite"));}
    if (index==3){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("avantages"));}
    if (index==4){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("solde_de_conge"));}
    if (index==5){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("absence"));}
    if (index==6){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("salaire"));}
    if (index==7){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("rang"));}
    if (index==8){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("nom"));}
    if (index==8){ui->tab_employe->setModel(tmpemploye.afficher_triemployeDEC("prenom"));}


}

void gestion::on_tri_shift_3_activated(int index)
{if (index==0){ui->tab_shift->setModel(tmpsh.afficher_shift());}
    if(index==1) {ui->tab_shift->setModel(tmpsh.afficher_trishiftDEC("datedujour"));}
    if(index==2) {ui->tab_shift->setModel(tmpsh.afficher_trishiftDEC("shifft"));}
   if(index==3) {ui->tab_shift->setModel(tmpsh.afficher_trishiftDEC("id_employe"));}

}


void gestion::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void gestion::sendMail()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("dombe.airline@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("dombe.airline@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

}

void gestion::mailSent(QString status)
{
    if (status=="message")
    {QMessageBox::information( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );}
}
void gestion::makePolt()
{


       ///////////////////////////////////////////////////////////////////////
       // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("Salaires");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;

          QSqlQuery q=tmpemploye.afficher_prenom();
          int i=0;
          while (q.next()) {
              QString adresse= q.value(0).toString();
              i++;
              ticks<<i;
              labels <<adresse;
          }
          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot->xAxis->setTicker(textTicker);
          ui->customPlot->xAxis->setTickLabelRotation(60);
          ui->customPlot->xAxis->setLabel("Prenom");
          QFont F("ITALIC",14,10);
          ui->customPlot->xAxis->setLabelFont(F);
          ui->customPlot->xAxis->setSubTicks(false);
          ui->customPlot->xAxis->setTickLength(0, 4);
          ui->customPlot->xAxis->setRange(0, 8);
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->xAxis->grid()->setVisible(true);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot->yAxis->setRange(0,3000);
          ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot->yAxis->setLabel("Salaire");

          ui->customPlot->yAxis->setLabelFont(F);
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setLabelColor(Qt::white);
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1=tmpemploye.afficher_salaire();
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot->legend->setVisible(true);
          ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot->legend->setFont(legendFont);
          ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);









}

void gestion::on_pushButton_4_clicked()
{
    music->play();
}

void gestion::on_pushButton_6_clicked()
{
    music->pause();
}


void gestion::on_verticalSlider_sliderMoved(int position)
{
    music->setVolume(position);
}
//gestion avions/constructeur :

void gestion::initialiser()
{
    ui->lineEdit_idavion->clear();
    //ui->lineEdit_etat->clear();

    ui->lineEdit_idconstructeur->clear();
    ui->lineEdit_nomconstructeur->clear();
    ui->lineEdit_mailcostructeur->clear();
}

void gestion::initialiser_modifier()
{
    ui->lineEdit_etat_3->clear();
    ui->lineEdit_nom_const_mod->clear();
    ui->lineEdit_mail_const_mod->clear();
}

void gestion::initialiser_supp()
{
    ui->comboBox_id_supp->clear();
    ui->comboBox_id_supp_const->clear();
    ui->comboBox_mail->clear();
}

void gestion::refresh()
{
    ui->tab_avions->setModel(tmpavions.afficher_avions());
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
    ui->id_constructeur->setModel(tmpavions.afficher_avions());
    ui->id_constructeur_3->setModel(tmpavions.afficher_avions());
    ui->comboBox_mod_av->setModel(tmpavions.afficher_avions());
    ui->comboBox_id_const_modi->setModel(tmpconstructeur.afficher_constructeurlist());
}
void gestion::on_ajouter_constructeur_clicked()
{
    QSound::play("C:/Users/CNTE/Downloads/Mouse.wav");
    QString id = ui->lineEdit_idconstructeur->text();
    QString nom= ui->lineEdit_nomconstructeur->text();
    QString mail= ui->lineEdit_mailcostructeur->text();

    constructeur e(id,nom,mail);
    if(e.verif_email(e.get_mail())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter constructeur"),
                    QObject::tr("verifier Mail !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }else if(e.verif_id(e.get_id())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter constructeur"),
                    QObject::tr(" Id doit contenir 8 chiffres !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }else if(e.verif_nom(e.get_nom())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter constructeur"),
                    QObject::tr(" Nom doit contenir 20 caractéres !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
  bool test=e.ajouter_constructeur();
  if(test)
{QString okd="";
      constructeur ok;
      ok.notification_ajout_constructeur(okd);
      ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
      refresh();
      initialiser();

      //refresh
      ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->comboBox_id_const_modi->setModel(tmpconstructeur.afficher_constructeurlist());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un constructeur"),
                  QObject::tr("constructeur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un constructeur"),
                  QObject::tr("constructeur existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

}void gestion::on_supprimer_constructeur_clicked()
{

    QString id = ui->comboBox_id_supp_const->currentText();
    bool test=tmpconstructeur.supprimer_constructeur(id);
    if(test)
    {ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
        refresh();
        initialiser_supp();
        //refresh
        ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_id_const_modi->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_id_supp_const->setModel(tmpconstructeur.getIdModel());

        ui->comboBox_mail->setModel(tmpconstructeur.getMailModel());


        QMessageBox::information(nullptr, QObject::tr("Supprimer constructeur"),
                    QObject::tr("constructeur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer constructeur"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void gestion::on_suppavions_clicked()
{

    QString id = ui->comboBox_id_supp->currentText();
    bool test=tmpavions.supprimer_avions(id);
    if(test)
    {
        ui->tab_avions->setModel(tmpavions.afficher_avions());
        ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());
        ui->comboBox_id_supp->setModel(tmpavions.getIdModel());
        refresh();

 initialiser_supp();
        //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer avions"),
                    QObject::tr("avion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer avions"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_ajouter_av_clicked()
{
    QSound::play("C:/Users/CNTE/Downloads/Mouse.wav");
    QString okd="";
          avions ok;
          ok.notification_ajout_avion(okd);
    QString id = ui->lineEdit_idavion->text();
    QString etat1= etat;
    avions a(id,etat1,tmpavions.get_ID_CONSTRUCTEUR());

    if(a.verif_id_avions(a.get_id())==false){
            QMessageBox::critical(nullptr, QObject::tr("Ajouter avion"),
                        QObject::tr(" Id doit contenir 8 chiffres !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }else {

    bool test=a.ajouter_avions();
    if(test)
    {
      ui->tab_avions->setModel(tmpavions.afficher_avions());//refresh
      refresh();
      initialiser();
      ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());
      ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un avions"),
                  QObject::tr("avion ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un avions"),
                  QObject::tr("avion existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void gestion::on_id_constructeur_activated(const QString &arg1)
{
    tmpavions.set_ID_CONSTRUCTEUR(arg1);

}

void gestion::on_id_constructeur_3_activated(const QString &arg1)
{
    tmpavions.set_ID_CONSTRUCTEUR(arg1);
}

void gestion::on_comboBox_mod_av_activated(const QString &arg1)
{
    tmpavions.set_id(arg1);
}

void gestion::on_modifier_av_clicked()
{

    tmpavions.set_etat(ui->lineEdit_etat_3->text());
    bool test=tmpavions.modifier();
if(test)
{
   ui->tab_avions->setModel(tmpavions.afficher_avions());//refresh

   ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());
   ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
   ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

   ui->comboBox_mod_av->setModel(tmpavions.afficher_avionslist());
   ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
   refresh();
   initialiser();
   initialiser_modifier();

    QMessageBox::information(nullptr, QObject::tr("modifer un avions"),
                QObject::tr("avion modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un avions"),
                QObject::tr("avion non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_modifier_constructeur_clicked()
{

    tmpconstructeur.set_nom(ui->lineEdit_nom_const_mod->text());
    tmpconstructeur.set_mail(ui->lineEdit_mail_const_mod->text());
bool test=tmpconstructeur.modifier_constructeur();
if(test)
{
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
    refresh();
    initialiser_modifier();
    //refresh
    ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->comboBox_id_const_modi->setModel(tmpconstructeur.afficher_constructeurlist());

    ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

    QMessageBox::information(nullptr, QObject::tr("modifer un constructeur"),
                QObject::tr("constructeur modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un constructeur"),
                QObject::tr("constructeur non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion::on_chercher_constructeur_textChanged(const QString &arg1)
{
    if(k==0)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_id(arg1));
    if(k==1)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_nom(arg1));
    if(k==2)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_mail(arg1));
}


void gestion::on_chercher_avion_textChanged(const QString &arg1)
{
     if(k==0)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_id(arg1));
     if(k==1)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_etat(arg1));
     if(k==2)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_ID_CONSTRUCTEUR(arg1));
}


void gestion::on_trier_selon_id_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_id());
}
void gestion::on_trier_selon_id_desc_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_id_desc());
}


void gestion::on_trier_selon_etat_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_etat());
}
void gestion::on_trier_selon_etat_desc_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_etat_desc());
}


void gestion::on_trier_selon_id_constructeur_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_ID_CONSTRUCTEUR());
}
void gestion::on_trier_selon_id_constructeur_desc_clicked()
{

    ui->tab_avions->setModel(tmpavions.afficher_tri_ID_CONSTRUCTEUR_desc());
}


void gestion::on_comboBox_id_const_modi_activated(const QString &arg1)
{
    tmpconstructeur.set_id(arg1);
}


void gestion::on_pushButton_tri_id_const_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_id());
}
void gestion::on_pushButton_tri_id_const_desc_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_id_desc());
}


void gestion::on_pushButton_tri_nom_const_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_nom());
}
void gestion::on_pushButton_tri_nom_const_desc_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_nom_desc());
}


void gestion::on_pushButton_tri_mail_const_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_mail());
}
void gestion::on_pushButton_tri_mail_const_desc_clicked()
{

    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_mail_desc());
}
void gestion::sendMail_constructeur()
{
    QString mail = ui->comboBox_mail->currentText();

    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("dombe.airline@gmail.com", ui->comboBox_mail->currentText() , ui->subject_2->text(),ui->msg_2->toPlainText());
    //ui->comboBox_mail->setModel(tmpconstructeur.getMailModel());

}






void gestion::on_enpanne_clicked(bool checked)
{
    if(checked)
        etat="en panne";
}

void gestion::on_fonctionnel_clicked(bool checked)
{
    if(checked)
        etat="fonctionnel";
}

void gestion::on_comboBox_mod_av_currentTextChanged(const QString &arg1)
{

    QSqlQuery query=tmpavions.chercher_id(arg1);
    QString ide;

    while(query.next())
    {
    ui->lineEdit_etat_3->setText(query.value(1).toString());
    ui->id_constructeur_3->setCurrentText(query.value(2).toString());
    }
}
void gestion::on_comboBox_id_const_modi_currentTextChanged(const QString &arg1)
{
    QSqlQuery query=tmpconstructeur.chercher_id(arg1);
    QString ide;
    while(query.next())
    {
    ui->lineEdit_nom_const_mod->setText(query.value(1).toString());
    ui->lineEdit_mail_const_mod->setText(query.value(2).toString());
    }
}






void gestion::on_checkBox_toggled(bool checked)
{
    k=0;
    ui->checkBox_2->setCheckState(Qt::CheckState(0));
    ui->checkBox_3->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_2_toggled(bool checked)
{
    k=1;
    ui->checkBox->setCheckState(Qt::CheckState(0));
    ui->checkBox_3->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_3_toggled(bool checked)
{
    k=2;
    ui->checkBox->setCheckState(Qt::CheckState(0));
    ui->checkBox_2->setCheckState(Qt::CheckState(0));
}


void gestion::on_checkBox_id_avion_toggled(bool checked)
{
    k=0;
    ui->checkBox_etat_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_id_const_avion->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_etat_avion_toggled(bool checked)
{
    k=1;
    ui->checkBox_id_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_id_const_avion->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_id_const_avion_toggled(bool checked)
{
    k=2;
    ui->checkBox_id_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_etat_avion->setCheckState(Qt::CheckState(0));
}

void gestion::makePolt2()
{


 QPieSeries *series = new QPieSeries();
QSqlQuery qry=tmpavions.afficher_etat();
int tous=0;
int panne=0;
int fonctionnel=0;

if (qry.exec())
{

    while (qry.next())
    {

tous++;
if (qry.value(1)=="en panne")
{
panne++;
}
else if(qry.value(1)=="fonctionnel")
{
fonctionnel++;
}


    }
}


qDebug () << " " << panne;
    qDebug () << " " << fonctionnel;


float testing1 =(panne*100)/tous;
float testing2 =100-testing1;
QString pleasework = QString::number(testing1);
QString pleaseworks= QString::number(testing2);
series ->append("panne "+pleasework+"%",(panne));
series ->append("fonctionnel "+pleaseworks+"%",(fonctionnel));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

if (panne>fonctionnel)
{

slice0->setExploded();
slice0->setPen(QPen(Qt::darkGreen,2));
slice0->setBrush(Qt::red);

}
else
{

slice1->setExploded();
slice1->setPen(QPen(Qt::darkGreen,2));
slice1->setBrush(Qt::red);
}





QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("etat produit  : ");
chart->legend()->hide();



        QChartView *chartview = new QChartView (chart);
chartview->setRenderHint(QPainter::Antialiasing);
QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartview, 1, 1);
    ui->stat->setLayout(mainLayout);

}
//gestion fournisseur produit


void gestion::makePlot_fournisseur()
{// set dark background gradient:
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
void gestion::on_Ajouter_produit_clicked()
{
    QString id_produit=ui->lineEdit_idproduit->text();
    QString type=ui->lineEdit_typeproduit->text();
    QString date_fabrication=ui->lineEdit_DFproduit->text();
    QString date_expiration=ui->lineEdit_DEXproduit->text();
    prodect p(id_produit,type,date_fabrication,date_expiration,tmpproduit.get_id());
    bool teste;
           teste =p.ajouter_produit();
    if (teste)
   {   ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     QMessageBox::information(nullptr,QObject::tr("ajouter produit"),
       QObject::tr("produit ajoute") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("ajouter produit"),
          QObject::tr("produit existe deja ") ,QMessageBox::Cancel) ;
}
}


void gestion::on_supprimer_produit_clicked()
{
    QString id=ui->lineEdit_suppproduit->text();
    bool test=tmpproduit.supprimer_produit(id);
    if(test)
    {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit  supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("verfier l'id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestion::on_ajouter_fournisseur_clicked()
{QString id=ui->lineEdit_idfournisseur->text();
    QString nom=ui->lineEdit_nomfournisseur->text();
    QString mail=ui->lineEdit_mail->text();

    fournisseur f(id,nom,mail);
    bool teste;
           teste=f.ajouter_fournisseur();
    if (teste)
   {   ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     QMessageBox::information(nullptr,QObject::tr("ajouter fournisseur"),
       QObject::tr("fournisseur ajoute") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("ajouter fournisseur"),
          QObject::tr("fournisseur existe deja ") ,QMessageBox::Cancel) ;
}

}

void gestion::on_supprimer_fournisseur_clicked()
{  QString id=ui->lineEdit_suppfournisseur->text();
    bool test=tmpfournisseur.supprimer_fournisseur(id);
    if(test)
    {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        QMessageBox::information(nullptr, QObject::tr("Supprimer fournisseur"),
                    QObject::tr("fournisseur  supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer fournisseur"),
                    QObject::tr("verfier l'id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion::on_comboBox_activated(const QString &arg1)
{
    tmpproduit.set_id(arg1);
}

void gestion::on_comboBox_modidfournisseur_activated(const QString &arg1)
{
    tmpfournisseur.set_id(arg1) ;
}

void gestion::on_modifierfournisseur_clicked()
{
    QString nom=ui->lineEdit_modnomfournisseur->text();
    QString mail=ui->lineEdit_modmailfournisseur->text();

    fournisseur f(tmpfournisseur.get_id(),nom,mail);
    bool teste;
           teste=f.modifier_fournisseur();
    if (teste)
   {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     QMessageBox::information(nullptr,QObject::tr("modifier fournisseur"),
       QObject::tr("fournisseur modifier") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("modifier fournisseur"),
          QObject::tr("merci de remplir tout les champs correctement") ,QMessageBox::Cancel) ;
}


}


void gestion::on_comboBox_modidproduit_activated(const QString &arg1)
{
   tmpproduit.set_id(arg1);
}

void gestion::on_comboBoxmodidproduitfournisseur_activated(const QString &arg1)
{
    tmpproduit.set_ID_FOURNISSEUR(arg1);
}

void gestion::on_modifierproduit_clicked()
{     QString type=ui->lineEdit_modtypeproduit->text();
      QString date_fabrication=ui->lineEdit_modDFproduit->text();
      QString date_expiration=ui->lineEdit_modDEXproduit->text();
       prodect p(tmpproduit.get_id(),type,date_fabrication,date_expiration,tmpproduit.get_ID_FOURNISSEUR());
       bool teste;
              teste=p.modifier_produit();
       if (teste)
      {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
           ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
            ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
        ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
        ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        QMessageBox::information(nullptr,QObject::tr("modifier produit"),
          QObject::tr("produit modifier") ,QMessageBox::Cancel);

       }else
   {
           QMessageBox::critical(nullptr,QObject::tr("modifier produit"),
             QObject::tr("merci de remplir tout les champs correctement") ,QMessageBox::Cancel) ;
   }


}

void gestion::sendMail_fournisseur()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_2->text() , ui->subject_3->text(),ui->msg_3->toPlainText(), files );
    else
        smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_2->text() , ui->subject_3->text(),ui->msg_3->toPlainText());

}


void gestion::on_Recherche_fournisseur_clicked()
{
    QString id=ui->lineEdit->text();
ui->tableView->setModel(tmpfournisseur.rechercher(id));
}
//gestion vols et destination
void gestion::on_AJOUTER_VOLS_clicked()
{
    int N_VOL = ui->lineEdit_N_vol->text().toInt();
    QString HEURE = ui->lineEdit_heure->text();
    QString ORIGINE = ui->lineEdit_origine->text();

  gerer_vols e(N_VOL ,HEURE,ORIGINE,tmpvols.get_STATUT(),tmpvols.get_ID_DEST());
  bool test=e.ajouter_vol();
  if(test)
{
      ui->tab_vols->setModel(tmpvols.afficher_vol());
      ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
        ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

      ui->tab_dest->setModel(tmpdest.afficher_dest());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("vol ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("vol existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion::on_comboBox_ID_DEST_activated(const QString &arg1)
{
    tmpvols.set_ID_DEST(arg1);
}

void gestion::on_AJOUTER_DESTINATION_clicked()
{
    int duree = ui->lineEdit_DURREE->text().toInt();
    QString ville = ui->lineEdit_VILLE->text();
    QString id = ui->lineEdit_ID_DEST->text();
  destination v(id,ville,duree);
  bool test=v.ajouter_dest();
  if(test)
{
      ui->tab_vols->setModel(tmpvols.afficher_vol());
      ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
        ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

      ui->tab_dest->setModel(tmpdest.afficher_dest());  //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter destination"),
                  QObject::tr("dest ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter destination"),
                  QObject::tr("destination deja ajouter !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion::on_supprimer_dest_clicked()
{
    QString id = ui->lineEdit_suppdest->text();
    bool test=tmpdest.supprimer_destination(id);
    if(test)
    {
        ui->tab_vols->setModel(tmpvols.afficher_vol());
        ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
          ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
          ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
          ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

        ui->tab_dest->setModel(tmpdest.afficher_dest());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer destination"),
                    QObject::tr("destination supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer destination"),
                    QObject::tr("verfier l id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestion::on_supprimervols_clicked()
{int id = ui->lineEdit_suppvols->text().toInt();
    bool test=tmpvols.supprimer_vol(id);
    if(test)
    {
        ui->tab_vols->setModel(tmpvols.afficher_vol());
        ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
          ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->tab_dest->setModel(tmpdest.afficher_dest());
         //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer vol"),
                    QObject::tr("vol supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer vol"),
                    QObject::tr("verfier le numero du vol  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_comboBox_status_activated(const QString &arg1)
{
    tmpvols.set_STATUT(arg1);
}



void gestion::on_comboBox_ID_DEST_mod_activated(const QString &arg1)
{
    tmpdest.set_id(arg1);
    tmpdest.chercher_dest();
    ui->lineEdit_VILLE_mod->setText(tmpdest.get_ville());
    ui->lineEdit_DURREE_mod->setText(QString::number(tmpdest.get_duree()));

}




void gestion::on_comboBox_ID_DEST_mod_vol_activated(const QString &arg1)
{
    tmpvols.set_ID_DEST(arg1);
}

void gestion::on_comboBox_status_mod_activated(const QString &arg1)
{
    tmpvols.set_STATUT(arg1);
}



void gestion::on_comboBox_N_VOL_mod_activated(const QString &arg1)
{ int a=arg1.toInt();
    tmpvols.set_N_VOL(a);
    tmpvols.chercher_vol();
    ui->lineEdit_heure_mod->setText(tmpvols.get_HEURE());
    ui->lineEdit_origine_mod->setText(tmpvols.get_ORIGINE());
    ui->lineEdit_statut_mod->setText(tmpvols.get_STATUT());
     ui->lineEdit_ID_DEST_mod->setText(tmpvols.get_ID_DEST());

}

void gestion::on_mod_dest_clicked()
{

        QString ville =ui->lineEdit_VILLE_mod->text();
       int duree =ui->lineEdit_DURREE_mod->text().toInt();
        destination  d(tmpdest.get_id(),ville,duree);
       if((tmpdest.get_id()=="")||(ville=="")||(duree==0))

    {QMessageBox::information(nullptr,QObject::tr("verifier champs"),
                              QObject::tr("merci de remplir tous les champs \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else{       bool test=d.modifier_destination();
       if (test==true)
       {
           ui->tab_vols->setModel(tmpvols.afficher_vol());
           ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
           ui->tab_dest->setModel(tmpdest.afficher_dest());
           ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
            ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
            ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());



        QMessageBox::information(nullptr,QObject::tr("modifier destination"),
          QObject::tr("destination modifier.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else{
       QMessageBox::critical(nullptr, QObject::tr("modifier destination"),
           QObject::tr("ERREUR !.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

       }
       }
    }


void gestion::on_mod_vol_clicked()
{
    QString heure =ui->lineEdit_heure_mod->text();
   QString origine =ui->lineEdit_origine_mod->text();
    gerer_vols  v(tmpvols.get_N_VOL(),heure,origine,tmpvols.get_STATUT(),tmpvols.get_ID_DEST());



          bool test=v.modifier_vols();
   if (test==true)
   {
       ui->tab_vols->setModel(tmpvols.afficher_vol());
       ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
       ui->tab_dest->setModel(tmpdest.afficher_dest());
       ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());



    QMessageBox::information(nullptr,QObject::tr("modifier vols"),
      QObject::tr("vol modifier.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else{
   QMessageBox::critical(nullptr, QObject::tr("modifier vols"),
       QObject::tr("ERREUR !.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
}

void gestion::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tab_dest->setModel(tmpdest.chercher_destination(arg1));
}

void gestion::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_vols->setModel(tmpvols.chercher_vols(arg1));
}

void gestion::makePolt_dest()
{


       ///////////////////////////////////////////////////////////////////////
       // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot_dest->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot_dest->xAxis, ui->customPlot_dest->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("durees des vols");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;

          QSqlQuery q;
          int i=0;
          q.exec("select ville from destination ");
          while (q.next()) {
              QString adresse= q.value(0).toString();
              i++;
              ticks<<i;
              labels <<adresse;
          }
          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot_dest->xAxis->setTicker(textTicker);
          ui->customPlot_dest->xAxis->setTickLabelRotation(60);
          ui->customPlot_dest->xAxis->setSubTicks(false);
          ui->customPlot_dest->xAxis->setTickLength(0, 4);
          ui->customPlot_dest->xAxis->setRange(0, 8);
          ui->customPlot_dest->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot_dest->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot_dest->xAxis->grid()->setVisible(true);
          ui->customPlot_dest->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot_dest->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot_dest->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot_dest->yAxis->setRange(0,20);
          ui->customPlot_dest->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot_dest->yAxis->setLabel("Statistiques");
          ui->customPlot_dest->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot_dest->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot_dest->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot_dest->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot_dest->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot_dest->yAxis->setLabelColor(Qt::white);
          ui->customPlot_dest->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot_dest->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select duree from destination  ");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot_dest->legend->setVisible(true);
          ui->customPlot_dest->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot_dest->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot_dest->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot_dest->legend->setFont(legendFont);
          ui->customPlot_dest->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);






}


// gestion client promotion :
void gestion::on_pushButton_15_clicked()
{
 //  MainWindow m;
    close();
    //m.exec();
}

void gestion::on_pushButton_17_clicked()
{
    close();
}

void gestion::on_pushButton_19_clicked()
{
    close();
}

void gestion::on_pushButton_21_clicked()
{
    close();
}

void gestion::on_pushButton_18_clicked()
{
    QString okd="";
        Clients ok;
    QString num_passeport=tmpclient.getnumpasseport();
    bool test=tmpclient.supprimer_clients(num_passeport);
    if(test)
    {ui->tableView_affiche_client->setModel(tmpclient.afficher());
      ui->comboBox_mod_client->setModel(tmpclient.afficher_listclient());
       ui->comboBox_suppclients->setModel(tmpclient.afficher_listclient());//refresh
      QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ok.notification_supprimer_client(okd);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void gestion::on_comboBox_suppclients_activated(const QString &arg1)
{
    tmpclient.set_num_passeport(arg1);

}
void gestion::on_versionanglais_clicked()
{
    anglais a ;
            a.exec();
}

void gestion::on_comboBox_mod_client_activated(const QString &arg1)
{
   tmpclient.set_num_passeport(arg1);
}

void gestion::on_pushButton_16_clicked()
{
    QString okd="";
       Clients ok;


    QString nom = ui->lineEdit_nom_client->text();
        QString prenom = ui->lineEdit_prenom_client->text();
       QString num_passeport  = ui->lineEdit_num_passeport->text();
     QString nationnalite  = ui->lineEdit_nationnalite->text();
     QString email=ui->lineEdit_email->text();
     QString num_telephone=ui->lineEdit_num_telephone->text();

     int nb_voyages=ui->lineEdit_nb_voyages->text().toInt();
     Clients c(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
      bool test2=c.verif_mail(email);
         if(test2)
         {
     bool test=c.ajouter_client();
     if(test)
   {ui->tableView_affiche_client->setModel(tmpclient.afficher());
    ui->comboBox_mod_client->setModel(tmpclient.afficher_listclient());//refresh
    ui->comboBox_suppclients->setModel(tmpclient.afficher_listclient())  ;
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("client ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
  ok.notification_ajout_client(okd);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}}else { QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                               QObject::tr("merci de saisir une adresse mail valide !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
}

//Modifier!!!









void gestion::on_ajouter_promotion_clicked()
{
    QString okd="";
        Promotions ok;

    QString id =ui->lineEdit_id_promo->text();
    QString pourcentage  = ui->lineEdit_pourcentage->text();
        QString evenement = ui->lineEdit_evenement->text();

     Promotions p(pourcentage,evenement,id,tmppromo.getnum_passeport());

     bool test=p.ajouter_promotions();
     if(test)
   {ui->tableView_affiche_client->setModel(tmppromo.afficher());//refresh
     ui->comboBox_supp_promo->setModel(tmppromo.afficher_listpromo());
     QMessageBox::information(nullptr, QObject::tr("Ajouter une prmotion"),
                     QObject::tr("PROMOTION ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   ok.notification_ajout_promo(okd);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void gestion::on_comboBox_numpasseport_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}


void gestion::on_comboBox_num_passeport_mod_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}






void gestion::on_supprimer_promotion_clicked()
{    QString okd="";
    Promotions ok;

    QString id= tmppromo.getID_PROMO();
    bool test=tmppromo.supprimer_promotions(id);
    if(test)
    {ui->tab_promotions->setModel(tmppromo.afficher());
        ui->comboBox_supp_promo->setModel(tmppromo.afficher_listpromo());
        //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Promotion supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ok.notification_supprimer_promo(okd);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_pushButton_27_clicked()
{
    QString okd="";
    Promotions   ok;
    QString id=tmppromo.getID_PROMO();
    QString pourcentage  = ui->lineEdit_pourcentage->text();
        QString evenement = ui->lineEdit_evenement->text();

    Promotions p;
    if(p.rech(id)){
        bool test = p.modifier(pourcentage,evenement,tmppromo.getnum_passeport(),id);
        if(test){
            ui->tab_promotions->setModel(tmppromo.afficher());
            QMessageBox::information(nullptr,QObject::tr("Promotion modifée"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
     ok.notification_modifier_promo(okd);
        }

        else
          {  QMessageBox::critical(nullptr, QObject::tr("Modifier une promotion"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void gestion::on_pushButton_20_clicked()
{
    QString okd="";
      Clients ok;

    QString nom = ui->lineEdit_nom_client_mod->text();
    QString prenom = ui->lineEdit_prenom_client_mod->text();
    QString num_passeport = tmpclient.getnumpasseport();
    QString nationnalite = ui->lineEdit_nationnalite_mod->text();
    QString email = ui->lineEdit_email_client_mod->text();
    QString num_telephone = ui->lineEdit_num_telephone_2->text();
    int nb_voyages = ui->lineEdit_nb_voyages_2->text().toInt();


    Clients c;
    if(c.rech(num_passeport)){
        bool test = c.modifier(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
        if(test){
            ui->tableView_affiche_client->setModel(tmpclient.afficher());
            QMessageBox::information(nullptr,QObject::tr("Clients modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
      ok.notification_modifier_client(okd);
        }

        else
          {  QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void gestion::on_pushButton_23_clicked()
{
    close();
}

void gestion::on_pushButton_24_clicked()
{
     close();
}

void gestion::on_pushButton_22_clicked()
{
     close();
}
void gestion::on_pushButtontrinom_clicked()
{
      ui->tableView_affiche_client->setModel(tmpclient.afficher_tri_nom());
}



void gestion::on_pushButton_25_clicked()
{
     close();
}






void gestion::on_pushButton_tri_promo_clicked()
{
     ui->tab_promotions->setModel(tmppromo.afficher_tri_ID());
}


void gestion::on_lineEdit_chercher_client_cursorPositionChanged()
{
Clients c;
    QString num_passeport=ui->lineEdit_chercher_client->text();
     c.rechercher_client(ui->tableView_rechercheC,num_passeport);
}

void gestion::on_lineEdit_chercher_promo_cursorPositionChanged(int arg1, int arg2)
{
    Promotions p;
    QString ID_PROMO=ui->lineEdit_chercher_promo->text();
    p.rechercher_promotion(ui->tableView_rechercheC_2,ID_PROMO);

}


void gestion::on_comboBox_id_mail_activated(const QString &arg1)
{
   QString ID_PROMO=arg1;


    Promotions p ;
    p.rechercher_promotion(ui->tableView_mail,ID_PROMO);

}

void gestion::on_comboBox_id_promo_mod_activated(const QString &arg1)
{
    tmppromo.set_id(arg1);
}









void gestion::on_pushButton_8_clicked()
{
    ui->tab_promotions->setModel(tmppromo.afficher_tri_pourcentage());
}

void gestion::on_pushButton_9_clicked()
{
    ui->tableView_affiche_client->setModel(tmpclient.afficher_tri_prenom());

}
void gestion::on_pushButton_10_clicked()
{QString ID_PROMO;

    ID_PROMO=ui->lineEdit_chercher_promo->text();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("Select * from PROMOTIONS where ID_PROMO=:ID_PROMO");
    query->bindValue(":ID_PROMO",ID_PROMO);
    query->exec();
    model->setQuery(*query);

   qDebug()<<(model->rowCount());
   if( (model->rowCount()==0))
    QMessageBox::information(nullptr, QObject::tr("Rechercher une promotion"),
                QObject::tr(" Cette promotion n'existe pas .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


  else
    QMessageBox::information(nullptr, QObject::tr("Rechercher une promotion "),
                QObject::tr(" La promotion existe \n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}

void gestion::on_pushButton_7_clicked()
{QString num_passeport;

    num_passeport=ui->lineEdit_chercher_client->text();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("Select * from CLIENTS where num_passeport=:num_passeport ");
    query->bindValue(":num_passeport",num_passeport);
    query->exec();
    model->setQuery(*query);

   qDebug()<<(model->rowCount());
   if( (model->rowCount()==0))
    QMessageBox::information(nullptr, QObject::tr("Rechercher un client "),
                QObject::tr(" Ce client n'existe pas .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


  else
    QMessageBox::information(nullptr, QObject::tr("Rechercher un client "),
                QObject::tr(" Le client existe \n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}






void gestion::sendMail_promo()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_promo->text() , ui->subject_promo->text(),ui->msg_promo->toPlainText());
}


void gestion::makepolt_client()
{ QPieSeries *series = new QPieSeries();
    QSqlQuery qry;
    int tous=0;
    int etrangere=0;
    int tunisienne=0;

    qry.prepare("select * from clients ");
    if (qry.exec())
    {

        while (qry.next())
        {

tous++;

if(qry.value(3)=="tunisienne")
{
    tunisienne++;
}
else if(qry.value(3)!="tunisienne")
{
    etrangere++;
}


        }
    }


    qDebug () << " " << etrangere;
        qDebug () << " " << tunisienne;


float testing1 =(etrangere*100)/tous;
float testing2 =100-testing1;
QString pleasework = QString::number(testing1);
QString pleaseworks= QString::number(testing2);
series ->append("etrangere "+pleasework+"%",(etrangere));
    series ->append("tunisienne "+pleaseworks+"%",(tunisienne));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

if (etrangere>tunisienne)
{

   slice0->setExploded();
    slice0->setPen(QPen(Qt::darkGreen,2));
   slice0->setBrush(Qt::red);

}
else
{

slice1->setExploded();
slice1->setPen(QPen(Qt::darkGreen,2));
slice1->setBrush(Qt::red);
}





QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("etat produit  : ");
chart->legend()->hide();



            QChartView *chartview = new QChartView (chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(chartview, 1, 1);
        setLayout(mainLayout);
 ui->stat_client->setLayout(mainLayout);

}
//parking abonement ::
void gestion::on_ajouter_abon_clicked()
{
    int id = ui->lineEditid_abon->text().toInt();
        QString nom= ui->lineEditnom_abon->text();
        QString prenom= ui->lineEditprenom_abon->text();
        QDate datenaiss = ui->dateEdit_2_abon->date();
       QDate datedeb=ui->dateEdit_3_abon->date();
        QDate datefin=ui->dateEdit_4_abon->date();
 int numplace = ui->lineEditprenom_2_abon->text().toInt();
      abonnementCode c(id,nom,prenom,datenaiss,datedeb,datefin,numplace);
      bool test=c.ajouter();
      if((test)&&(id))
    {ui->tab_afficher_client->setModel(tmpabonnement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_supp_abon_clicked()
{    int id = ui->lineEditid_2_abon->text().toInt();
     bool test= tmpabonnement.supprimer(id);
     if(test)
     {ui->tab_afficher_client->setModel( tmpabonnement.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                     QObject::tr("abonnement supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion::on_midifer_abon_clicked()
{  int num = ui->lineEditprenom_3_abon->text().toInt();
    int qt_produit = ui->lineEditid_6_abon->text().toInt();

     bool test= tmpabonnement.modifier(num,qt_produit);
    if(test)
    {ui->tab_afficher_client->setModel( tmpabonnement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr(" abonnement modifié"),
                    QObject::tr("abonnement modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification abonnement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}







void gestion::on_pushButton_R_clicked()
{
    int id = ui->lineEdit_r_abon->text().toInt();
       bool test=tmpabonnement.tester(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("abonnement existe"),
                        QObject::tr("abonnement existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_rechercher_abonnement->setModel( tmpabonnement.afficherID(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::sendMail_abon()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


     smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_abon->text() , ui->subject_abon->text(),ui->msg_abon->toPlainText());

}


void gestion::on_pushButton_RP_clicked()
{
    int id = ui->lineEdit_RP->text().toInt();
       bool test=tmpparking.testerPark(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("parking existe"),
                        QObject::tr("parking existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_afficher_RP->setModel( tmpparking.afficherid(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_pushButton_NBE_clicked()
{
    parkingCode park;
        QSqlQueryModel* p=park.Tri2();


          ui->tab_afficher_triNBE->setModel(p);
}

void gestion::on_pushButton_NBP_clicked()
{
    parkingCode park;
        QSqlQueryModel* p=park.Tri();


          ui->tab_afficher_triNBP->setModel(p);
}


void gestion::on_ajouterparking_clicked()
{  int id = ui->lineEditcin_park->text().toInt();
    QString prenom= ui->lineEditnumtel_park->text();
    int nbrplace= ui->lineEditprenom_park->text().toInt();
    int nbretage= ui->comboBox_3_park->currentText().toInt();
  parkingCode r(id,prenom,nbrplace,nbretage);
  bool test=r.ajouter();
  if(test)
{ui->tab_afficher_client_park->setModel(tmpparking.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un parking"),
                  QObject::tr("parking ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un parking"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion::on_supp_park_clicked()
{int id = ui->lineEdit_park->text().toInt();
    bool test= tmpparking.supprimer(id);
    if(test)
    {ui->tab_afficher_client_park->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("parking supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion::on_modifier_parking_clicked()
{ int num = ui->lineEdit_2_park->text().toInt();
    int qt_produit = ui->lineEdit_3_park->text().toInt();

     bool test= tmpparking.modifier(num,qt_produit);
    if(test)
    {ui->tab_afficher_client_park->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr(" parking modifié"),
                    QObject::tr("PARKING modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void gestion::stat(){
    ui->table_no->setModel(tmpparking.afficher_stat());
    QSqlTableModel * model= new QSqlTableModel;

    model->setTable("PARKING");
    model->select();
    //ui->table_no_2->setModel(model);


    ui->widget_parking->xAxis->setLabel("numero parking");
    ui->widget_parking->yAxis->setLabel("nbr place");



    QVector<QCPGraphData> timeData(model->rowCount());
      for(int i=0;i<model->rowCount();i++)
        {
            timeData[i].key  = model->index(i, model->fieldIndex("ID")).data().toInt();
            timeData[i].value = model->index(i, model->fieldIndex("NBRPLACE")).data().toInt();
        }
    ui->widget_parking->xAxis->setRange(0,50);
    ui->widget_parking->yAxis->setRange(0,50);
    ui->widget_parking->addGraph();
    ui->widget_parking->graph(0)->data()->set(timeData);
    ui->widget_parking->replot();

}





void gestion::on_sendBtn_abon_clicked()
{sendMail_abon();

}





void gestion::on_comboBox_supp_promo_activated(const QString &arg1)
{
    tmppromo.set_id(arg1);
}
void gestion::on_sitee_clicked()
{
    QUrl url("https://noussakechrid.wixsite.com/domberairlines");
    QDesktopServices::openUrl(url);
}

void gestion::on_checkBox_son_on_toggled(bool checked)
{ui->checkBox_so_off->setCheckState(Qt::CheckState(0));
    son = 1;
}

void gestion::on_checkBox_so_off_toggled(bool checkedd)
{ui->checkBox_son_on->setCheckState(Qt::CheckState(0));
    son = 0;
}


void gestion::on_checkBox_notification_on_toggled(bool checked)
{ui->checkBox_notification_off->setCheckState(Qt::CheckState(0));
    notificationn = 1;
}

void gestion::on_checkBox_notification_off_toggled(bool checked)
{ui->checkBox_4->setCheckState(Qt::CheckState(0));
    notificationn = 0;
}

