#include "gerer_vols.h"
#include <QSqlQuery>
#include <QString>
gerer_vols::gerer_vols()
{

}
gerer_vols::gerer_vols(int N_VOL,QString HEURE,QString ORIGINE,QString STATUT,QString ID_DEST)
{this->HEURE=HEURE;
this->ORIGINE=ORIGINE;
this->N_VOL=N_VOL;
this->STATUT=STATUT;
this->ID_DEST=ID_DEST;}
QString gerer_vols::get_HEURE(){return  HEURE;}
QString gerer_vols::get_ORIGINE(){return ORIGINE;}
int gerer_vols::get_N_VOL(){return  N_VOL;}
QString gerer_vols::get_STATUT(){return STATUT;}
QString gerer_vols::get_ID_DEST(){return ID_DEST;}

void gerer_vols::set_HEURE(QString HEURE){this->HEURE=HEURE;}
void gerer_vols::set_ORIGINE(QString ORIGINE){this->ORIGINE=ORIGINE;}
void gerer_vols::set_N_VOL(int N_VOL){this->N_VOL=N_VOL;}
void gerer_vols::set_STATUT(QString STATUT){this->STATUT=STATUT;}
void gerer_vols::set_ID_DEST(QString ID_DEST){this->ID_DEST=ID_DEST;}
bool gerer_vols :: ajouter_vol()
{
    QSqlQuery query;
    QString res= QString :: number(N_VOL);
    query.prepare (" INSERT INTO VOLS (N_VOL , HEURE , ORIGINE , STATUT,ID_DEST)"
                  " VALUES (:N_VOL, :HEURE, :ORIGINE,  :STATUT,:ID_DEST)" );
    query.bindValue(":N_VOL",res);
    query.bindValue(":HEURE",HEURE);
    query.bindValue(":ORIGINE",ORIGINE);
    query.bindValue(":STATUT",STATUT);
    query.bindValue(":ID_DEST",ID_DEST);
    return query.exec();

}
QSqlQueryModel * gerer_vols::afficher_vol()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOLS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("N_VOL"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEURE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ORIGINE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_DEST"));
return model;
}

bool gerer_vols::supprimer_vol(int N_VOL)
{
QSqlQuery query;
QString res= QString::number(N_VOL);
query.prepare("Delete from vols where N_VOL = :N_VOL");
query.bindValue(":N_VOL", res);
return    query.exec();
}
QSqlQueryModel * gerer_vols::afficher_vollist()
{QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select N_VOL from vols");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("N_VOL"));
return model ;
}
bool gerer_vols::modifier_vols()
{QSqlQuery query ;
    QString res1=QString::number(N_VOL);
 query.prepare("UPDATE vols SET  HEURE=:HEURE,ORIGINE =:ORIGINE,STATUT=:STATUT,ID_DEST=:id where N_VOL =:N_VOL");

 query.bindValue(":N_VOL",res1);
 query.bindValue(":HEURE",HEURE);
 query.bindValue(":ORIGINE",ORIGINE);
 query.bindValue(":STATUT",STATUT);
 query.bindValue(":id",ID_DEST);

 query.exec();
 if(query.numRowsAffected()==0){
     return false;
 } else{
     return true;
 }
}
void gerer_vols::chercher_vol(){
    QSqlQuery query;
       QString res=QString::number(N_VOL);
    query.prepare("select HEURE,ORIGINE,STATUT,ID_DEST from vols where N_VOL=:N_VOL");
    query.bindValue(":N_VOL",res);
    query.exec();
    while(query.next()){
   HEURE=query.value(0).toString();
    ORIGINE=query.value(1).toString();
    STATUT=query.value(2).toString();
    ID_DEST=query.value(3).toString();

    }
 }
QSqlQueryModel * gerer_vols::chercher_vols(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare("SELECT * from vols where N_VOL like :nom or heure like :nom or origine like :nom or statut like :nom or ID_DEST like :nom order by N_VOL ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("N_VOL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEURE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ORIGINE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_DEST"));
    return model;
}


