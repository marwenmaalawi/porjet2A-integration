#include "avions.h"
#include <QString>
#include <QDebug>
#include "QMessageBox"
avions::avions()
{

}
avions::avions(QString id,QString etat,QString ID_CONSTRUCTEUR)
{
  this->id=id;
  this->etat=etat;
  this->ID_CONSTRUCTEUR=ID_CONSTRUCTEUR;
}
QString avions::get_etat(){return  etat;}
QString avions::get_ID_CONSTRUCTEUR(){return ID_CONSTRUCTEUR;}
QString avions::get_id(){return  id;}
void avions::set_id(QString id){this->id=id;};
void avions::set_etat(QString etat ){this->etat=etat;};
void avions::set_ID_CONSTRUCTEUR(QString ID_CONSTRUCTEUR ){this->ID_CONSTRUCTEUR=ID_CONSTRUCTEUR;};

bool avions::ajouter_avions()
{
QSqlQuery query;

query.prepare("INSERT INTO avion (ID_avion, etat, ID_CONSTRUCTEUR) "
                    "VALUES (:id, :etat, :ID_CONSTRUCTEUR)");
query.bindValue(":id", id);
query.bindValue(":etat", etat);
query.bindValue(":ID_CONSTRUCTEUR", ID_CONSTRUCTEUR);

return    query.exec();
}

QSqlQueryModel * avions::afficher_avions()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by id_avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_id_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by id_avion desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_ID_CONSTRUCTEUR()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by ID_CONSTRUCTEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_ID_CONSTRUCTEUR_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by ID_CONSTRUCTEUR desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_etat()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by etat");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

QSqlQueryModel * avions::afficher_tri_etat_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from avion order by etat desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONST"));
    return model;
}

bool avions::supprimer_avions(QString idd)
{
QSqlQuery query;
query.prepare("Delete from avion where ID_avion = :idd ");
query.bindValue(":idd", idd);
return    query.exec();
}

QSqlQueryModel * avions::afficher_avionslist()
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery QUERY;
QUERY.prepare("select id_avion from avion");
QUERY.exec();
model->setQuery(QUERY);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_avion"));
    return model;
}

bool avions::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE avion set etat=:etat, ID_CONSTRUCTEUR=:id_constructeur where ID_avion =:idd ");
    query.bindValue(":idd",id);
    query.bindValue(":id_constructeur",ID_CONSTRUCTEUR);
    query.bindValue(":etat",etat);
    return    query.exec();

}

QSqlQueryModel * avions::chercher_avions_id(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from avion where id_avion like :nom order by id_avion ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONSTRUCTEUR"));
    return model;
}

QSqlQueryModel * avions::chercher_avions_etat(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from avion where etat like :nom order by id_avion ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONSTRUCTEUR"));
    return model;
}

QSqlQueryModel * avions::chercher_avions_ID_CONSTRUCTEUR(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from avion where id_constructeur like :nom order by id_avion ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CONSTRUCTEUR"));
    return model;
}


QSqlQueryModel * avions::stats()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT id_avion, etat,((id_avion*100)/(select SUM(id_avion) from avion) from avion");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

        return model;
}


QSqlQueryModel * avions::getIdModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select id_avion from avion");
    query->exec();
    model->setQuery(*query);
    return model;
}



QSqlQuery  avions::afficher_etat(){
    QSqlQuery query;

    query.prepare("select * from avion ");
    query.exec();
    return query;

}

QSqlQuery  avions::chercher_id(QString id){
     QSqlQuery query;
  query.exec("select * from avion where id_avion ='"+id+"'");
  query.exec();
  return query;}



bool avions::verif_id_avions(QString ch_id){
   bool test=true;
   int i;
   if(ch_id.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_id.length();i++){
           if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
               test=false;
               return  test;
       }
       }

   }
return test;}
void avions::notification_ajout_avion(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    QString s = id;
    notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau avion a été ajoutée !",QSystemTrayIcon::Information,15000);
//num++;
}
