#include "fournisseur.h"
#include "QtSql"
#include "QSqlQuery"
fournisseur::fournisseur()
{

}


fournisseur::fournisseur(QString id,QString nom,QString mail)
{this->id=id;
 this->nom=nom;
 this->mail=mail;

}
QString fournisseur::get_id(){return id;}
QString fournisseur:: get_nom(){return nom;}
QString fournisseur::get_mail(){return mail;}
void fournisseur:: set_id(QString id){this->id=id;}
void fournisseur::set_nom(QString nom){this->nom=nom;}
void fournisseur::set_mail(QString mail){this->mail=mail;}




QSqlQueryModel * fournisseur::rechercher(QString id)
{
QSqlQueryModel * model=new QSqlQueryModel();
    QString idd=id;
 model->setQuery("select * from FOURNISSEURS where ID_FOURNISSEUR='"+idd+"'");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR"));

 return  model;
}
bool fournisseur::ajouter_fournisseur()
{
QSqlQuery query;
query.prepare("INSERT INTO fournisseurs (ID_FOURNISSEUR,NOM_FOURNISSEUR,ADRESSE_MAIL) VALUES (:ID_FOURNISSEUR,:NOM_FOURNISSEUR,:ADRESSE_MAIL)");
query.bindValue(":ID_FOURNISSEUR",id);
query.bindValue(":NOM_FOURNISSEUR", nom);
query.bindValue(":ADRESSE_MAIL", mail);


return    query.exec();
}

QSqlQueryModel * fournisseur::afficher_fournisseur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID_FOURNISSEUR, NOM_FOURNISSEUR, ADRESSE_MAIL from fournisseurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));

    return model;
}



bool fournisseur::supprimer_fournisseur(QString id)
{
QSqlQuery query;
query.prepare("Delete from fournisseurs where ID_FOURNISSEUR=:ID_FOURNISSEUR ");
query.bindValue(":ID_FOURNISSEUR", id);
  query.exec();
return (query.numRowsAffected()>0) ;
}
QSqlQueryModel * fournisseur::afficher_listfournisseur()
{QSqlQueryModel* model =new QSqlQueryModel();
model->setQuery("select ID_FOURNISSEUR from FOURNISSEURS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
return model ;}
bool fournisseur::modifier_fournisseur()
{QSqlQuery query ;

 query.prepare("UPDATE FOURNISSEURS SET NOM_FOURNISSEUR=:NOM_FOURNISSEUR , ADRESSE_MAIL=:ADRESSE_MAIL where ID_FOURNISSEUR=:ID_FOURNISSUER");
 query.bindValue(":ID_FOURNISSUER",id);
 query.bindValue(":NOM_FOURNISSEUR",nom);
 query.bindValue(":ADRESSE_MAIL",mail);
 qDebug()<<id;
 query.exec();
 if(query.numRowsAffected()==0){
     return false;
 } else{
     return true;
 }
}


QSqlQueryModel * fournisseur::stats()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT ADRESSE_MAIL, :NOM_FOURNISSEUR,((NOM_FOURNISSEUR*100)/(select SUM(NOM_FOURNISSEUR) from FOURNISSEURS) from FOURNISSEURS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse_mail"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

        return model;
}



