#include "prodect.h"
#include "QtSql"
#include "QSqlQuery"

prodect::prodect()
{

}
prodect::prodect(QString id_produit,QString type,QString date_fabrication,QString date_expiration,QString ID_FOURNISSEUR)
{this->id_produit=id_produit;
 this->type=type;
 this->date_fabrication=date_fabrication;
 this->date_expiration=date_expiration;
 this->ID_FOURNISSEUR=ID_FOURNISSEUR;
}
QString prodect::get_id(){return id_produit;}
QString prodect:: get_type(){return type;}
QString prodect::get_date_fabrication(){return date_fabrication;}
QString prodect::get_date_expiration(){return date_expiration;}
QString prodect::get_ID_FOURNISSEUR(){return ID_FOURNISSEUR;}
void prodect:: set_id(QString id_produit){this->id_produit=id_produit;}
void prodect::set_date_expiration(QString date_expiration){this->date_expiration=date_expiration;}
void prodect::set_date_fabrication(QString date_fabrication){this->date_fabrication=date_fabrication;}
void prodect::set_type(QString type){this->type=type;}
void prodect::set_ID_FOURNISSEUR(QString ID_FOURNISSEUR){this->ID_FOURNISSEUR=ID_FOURNISSEUR;}

bool prodect::ajouter_produit()
{
QSqlQuery query;

query.prepare("INSERT INTO PRODUIT (id_produit,type,date_fabrication,date_expiration,id_fournisseur) VALUES (:ID_PRODUIT,:TYPE,:DATE_FABRICATION,:DATE_EXPIRATION,:ID_FOURNISSEUR)");
query.bindValue(":ID_PRODUIT",id_produit);
query.bindValue(":TYPE", type);
query.bindValue(":DATE_FABRICATION", date_fabrication);
query.bindValue(":DATE_EXPIRATION", date_expiration);
query.bindValue(":ID_FOURNISSEUR", ID_FOURNISSEUR);

return    query.exec();
}

QSqlQueryModel * prodect::afficher_produit()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUIT order by DATE_EXPIRATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_fabrication"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_expiration"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));

    return model;
}



bool prodect::supprimer_produit(QString id_produit)
{
QSqlQuery query;
query.prepare("Delete from PRODUIT where id_produit = :ID_PRODUIT ");
query.bindValue(":ID_PRODUIT", id_produit);
  query.exec();
return (query.numRowsAffected()>0) ;
}

QSqlQueryModel * prodect::afficher_listprodect()
{QSqlQueryModel* model =new QSqlQueryModel();
model->setQuery("select id_produit from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
return model ;}

bool prodect::modifier_produit()
{QSqlQuery query ;

 query.prepare("UPDATE PRODUIT SET id_produit=:ID_PRODUIT,type=:TYPE,date_fabrication=:DATE_FABRICATION,date_expiration=:DATE_EXPIRATION,id_fournisseur=:ID_FOURNISSEUR where id_produit=:ID_PRODUIT");
         query.bindValue(":ID_PRODUIT",id_produit);
         query.bindValue(":TYPE", type);
         query.bindValue(":DATE_FABRICATION", date_fabrication);
         query.bindValue(":DATE_EXPIRATION", date_expiration);
         query.bindValue(":ID_FOURNISSEUR", ID_FOURNISSEUR);
 query.exec();
 if(query.numRowsAffected()==0){
     return false;
 } else{
     return true;
 }
}
