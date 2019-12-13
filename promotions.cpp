#include "promotions.h"
#include<QTableView>

Promotions::Promotions()
{

}
Promotions::Promotions(QString pourcentage,QString evenement,QString ID_PROMO,QString num_passeport)
{
    this->pourcentage=pourcentage;
    this->evenement=evenement;
    this->ID_PROMO=ID_PROMO;
    this->num_passeport=num_passeport;

}
void Promotions::set_num_passeport(QString num_passeport)
{this->num_passeport=num_passeport; }
void Promotions::set_id(QString ID_PROMO)
{this->ID_PROMO=ID_PROMO;}

QString Promotions::getpourcentage()
{return pourcentage;}
QString Promotions::getevenement()
{return evenement;}
QString Promotions::getID_PROMO()
{return ID_PROMO;}
QString Promotions::getnum_passeport()
{return num_passeport;}


bool Promotions::ajouter_promotions()
{
QSqlQuery query;
query.prepare("INSERT INTO PROMOTIONS (pourcentage,evenement,ID_PROMO,num_passeport) "
                    "VALUES (:pourcentage,:evenement,:ID_PROMO,:num_passeport)");
query.bindValue(":pourcentage", pourcentage);
query.bindValue(":evenement", evenement);
query.bindValue(":num_passeport", num_passeport);
query.bindValue(":ID_PROMO", ID_PROMO);

return    query.exec();
}
QSqlQueryModel * Promotions::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PROMOTIONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("pourcentage"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("evenement"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_passeport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PROMO"));

    return model;
}


bool Promotions::supprimer_promotions(QString ID_PROMO)
{
QSqlQuery query;
//bool test=false;
query.prepare("Delete from PROMOTIONS where ID_PROMO = :ID_PROMO");
query.bindValue(":ID_PROMO", ID_PROMO);

 return    query.exec();

}


bool Promotions::rech(QString x){
    QSqlQuery query;
    query.prepare("select * from PROMOTIONS where ID_PROMO = :ID_PROMO;");
    query.bindValue(":ID_PROMO", x);
    return query.exec();
}

bool Promotions::modifier(QString a,QString b,QString c,QString d){
    QSqlQuery query;
    query.prepare("update PROMOTIONS set pourcentage=:pourcentage ,evenement=:evenement ,ID_PROMO=:ID_PROMO  ,num_passeport=:num_passeport  where ID_PROMO = :ID_PROMO;");
    query.bindValue(":pourcentage", a);
    query.bindValue(":evenement", b);
    query.bindValue(":num_passeport", c);
    query.bindValue(":ID_PROMO",d);
    return query.exec();
}
QSqlQueryModel * Promotions::afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PROMOTIONS order by ID_PROMO ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("pourcentage"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("evenement"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_passeport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PROMO"));

    return model;
}
QSqlQueryModel * Promotions::afficher_tri_pourcentage()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PROMOTIONS order by pourcentage ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("pourcentage"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("evenement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_passeport"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PROMO"));

        return model;

}

void Promotions::rechercher_promotion(QTableView *table,QString s)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Select * from PROMOTIONS where (regexp_like(ID_PROMO,:ID_PROMO))");
    qry.bindValue(":ID_PROMO",s);
    qry.exec();
    model->setQuery(qry);
    table->setModel(model);
    table->show();
}

QSqlQueryModel * Promotions::afficher_listpromo()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID_PROMO from PROMOTIONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROMO"));
return model;
}
void Promotions::notification_ajout_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été ajouter!",QSystemTrayIcon::Information,15000);
//num++;
}

void Promotions::notification_supprimer_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été supprimer!",QSystemTrayIcon::Information,15000);
//num++;
}
void Promotions::notification_modifier_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été modifier!",QSystemTrayIcon::Information,15000);
//num++;
}
