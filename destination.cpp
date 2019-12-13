#include "destination.h"

destination::destination()
{

}
destination::destination(QString id,QString ville,int duree)
{this->id=id;
this->ville=ville;
this->duree=duree;}
QString destination::get_id(){return  id;}
QString destination::get_ville(){return ville;}
int destination::get_duree(){return  duree;}
void destination::set_id(QString id){this->id=id;}
void destination::set_ville(QString ville){this->ville=ville;}
void destination::set_duree(int duree){this->duree=duree;}

bool destination::ajouter_dest()
{
QSqlQuery query;
QString res= QString::number(duree);
query.prepare("INSERT INTO destination (ID_DEST, ville,duree ) "
                    "VALUES (:id,:ville,:duree )");
query.bindValue(":duree", res);
query.bindValue(":id", id);
query.bindValue(":ville", ville);

return    query.exec();
}

QSqlQueryModel * destination::afficher_dest()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from destination order by ID_DEST ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ville "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
    return model;
}

bool destination::supprimer_destination(QString idd)
{
QSqlQuery query;

query.prepare("Delete from destination where ID_DEST = :idd ");
query.bindValue(":idd", idd);
return    query.exec();
}
QSqlQueryModel * destination::afficher_destlist()
{QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select ID_DEST from DESTINATION");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_DEST"));
return model ;
}
bool destination::modifier_destination()
{QSqlQuery query ;
    QString res=QString::number(duree);
 query.prepare("UPDATE destination SET ville=:ville,duree=:duree where ID_DEST=:id");
 query.bindValue(":id",id);
 query.bindValue(":ville",ville);
 query.bindValue(":duree",res);

 query.exec();
 if(query.numRowsAffected()==0){
     return false;
 } else{
     return true;
 }
}
void destination::chercher_dest(){
    QSqlQuery query;
    query.prepare("select ville,duree from destination where ID_DEST=:id");
    query.bindValue(":id",id);
    query.exec();
    while(query.next()){

    ville=query.value(0).toString();
    duree=query.value(1).toInt();
    }
 }
QSqlQueryModel * destination::chercher_destination(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare("SELECT * from destination where ID_DEST like :nom or duree like :nom or ville like :nom  order by ID_DEST ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEST"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
    return model;
}
