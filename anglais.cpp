#include "ui_anglais.h"
#include "anglais.h"



anglais::anglais(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::anglais)
{
    ui->setupUi(this);
    ui->tableView_3->setModel(tmpclient.afficher());
    ui->tab_promotions->setModel(tmppromo.afficher());
 ui->comboBox->setModel(tmpclient.afficher_listclient());
 ui->comboBox_2->setModel(tmpclient.afficher_listclient());

 ui->comboBox_4->setModel(tmppromo.afficher_listpromo());
  ui->comboBox_id_mail->setModel(tmppromo.afficher_listpromo());
 connect(ui->sendBtn_promo, SIGNAL(clicked()),this, SLOT(sendMail_promo()));
makepolt_client();


}


anglais::~anglais()
{
    delete ui;
}


void anglais::on_pushButton_15_clicked()
{
 //  MainWindow m;
    close();
    //m.exec();
}

void anglais::on_pushButton_17_clicked()
{
    close();
}

void anglais::on_pushButton_19_clicked()
{
    close();
}

void anglais::on_pushButton_21_clicked()
{
    close();
}

void anglais::on_pushButton_18_clicked()
{
    QString okd="";
       Clients ok;
    QString num_passeport= ui->lineEdit_20->text();
    bool test=tmpclient.supprimer_clients(num_passeport);
    if(test)
    {ui->tableView_3->setModel(tmpclient.afficher());//refresh
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

void anglais::on_pushButton_16_clicked()
{
    QString okd="";
      Clients ok;


    QString nom = ui->lineEdit_15->text();
        QString prenom = ui->lineEdit_16->text();
       QString num_passeport  = ui->lineEdit_18->text();
     QString nationnalite  = ui->lineEdit_19->text();
     QString email=ui->lineEdit_email->text();
     QString num_telephone=ui->lineEdit_num_telephone->text();
     int nb_voyages=ui->lineEdit_nb_voyages->text().toInt();
     Clients c(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
     bool test=c.ajouter_client();
     if(test)
   {ui->tableView_3->setModel(tmpclient.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("client ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   ok.notification_ajout_client(okd);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
}

//Modifier!!!









void anglais::on_ajouter_promotion_clicked()
{
    QString okd="";
        Promotions ok;

    QString id = ui->lineEdit_id->text();
    QString pourcentage  = ui->lineEdit_pourcentage->text();
        QString evenement = ui->lineEdit_evenement->text();

     Promotions p(pourcentage,evenement,id,tmppromo.getnum_passeport());

     bool test=p.ajouter_promotions();
     if(test)
   {ui->tableView_3->setModel(tmppromo.afficher());//refresh
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






void anglais::on_comboBox_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}

void anglais::on_supprimer_promotion_clicked()
{    QString okd="";
     Promotions ok;

    QString id= ui->lineEdit_supprimer_promotion->text();
    bool test=tmppromo.supprimer_promotions(id);
    if(test)
    {ui->tab_promotions->setModel(tmpclient.afficher());//refresh
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

void anglais::on_pushButton_27_clicked()
{
    QString okd="";
          Promotions ok;
    QString id = ui->lineEdit_id->text();
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

void anglais::on_pushButton_20_clicked()
{
    QString okd="";
         Clients ok;

    QString nom = ui->lineEdit_24->text();
    QString prenom = ui->lineEdit_17->text();
    QString num_passeport = ui->lineEdit_21->text();
    QString nationnalite = ui->lineEdit_22->text();
    QString email = ui->lineEdit_email_2->text();
    QString num_telephone = ui->lineEdit_num_telephone_2->text();
    int nb_voyages = ui->lineEdit_nb_voyages_2->text().toInt();


    Clients c;
    if(c.rech(num_passeport)){
        bool test = c.modifier(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
        if(test){
            ui->tableView_3->setModel(tmpclient.afficher());
            QMessageBox::information(nullptr,QObject::tr("Clients modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
       ok.notification_modifier_client(okd);
        }

        else
          {  QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void anglais::on_pushButton_23_clicked()
{
    close();
}

void anglais::on_pushButton_24_clicked()
{
     close();
}

void anglais::on_pushButton_22_clicked()
{
     close();
}

void anglais::on_pushButton_25_clicked()
{
     close();
}

void anglais::on_pushButton_clicked()
{
    ui->tableView_3->setModel(tmpclient.afficher_tri_nom());
}

void anglais::on_pushButton_2_clicked()
{
  ui->tab_promotions->setModel(tmppromo.afficher_tri_ID());
}

void anglais::on_pushButton_5_clicked()
{
    QString num_passeport;

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

void anglais::on_lineEdit_chercher_client_cursorPositionChanged()
{
Clients c;
    QString num_passeport=ui->lineEdit_chercher_client->text();
     c.rechercher_client(ui->tableView_rechercheC,num_passeport);
}


void anglais::on_lineEdit_id_3_cursorPositionChanged()
{
    Promotions p;
    QString ID_PROMO=ui->lineEdit_id_3->text();
    p.rechercher_promotion(ui->tableView_rechercheC_2,ID_PROMO);
}


void anglais::on_pushButton_6_clicked()
{
    QString ID_PROMO;

     ID_PROMO=ui->lineEdit_id_3->text();
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

void anglais::on_comboBox_3_activated(const QString &arg1)
{
   tmppromo.set_num_passeport(arg1);
}

void anglais::on_comboBox_4_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}







void anglais::on_pushButton_7_clicked()
{
    close();
}

void anglais::on_pushButton_8_clicked()
{
    ui->tab_promotions->setModel(tmppromo.afficher_tri_pourcentage());
}

void anglais::on_pushButton_9_clicked()
{
    ui->tableView_3->setModel(tmpclient.afficher_tri_prenom());

}
void anglais::makepolt_client()
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
void anglais::sendMail_promo()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_promo->text() , ui->subject_promo->text(),ui->msg_promo->toPlainText());
}


void anglais::on_comboBox_id_mail_activated(const QString &arg1)
{
    QString ID_PROMO=arg1;
    Promotions p ;
    p.rechercher_promotion(ui->tableView_mail,ID_PROMO);
}

void anglais::on_sendBtn_promo_clicked()
{
   sendMail_promo();
}
