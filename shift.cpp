#include "shift.h"
#include <QDebug>
shift::shift()
{

}
shift::shift(QString ID_EMPLOYE, QString DATEDUJOUR,QString SHIFFT)
{this->ID_EMPlOYE=ID_EMPLOYE;
this->DATEDUJOUR=DATEDUJOUR;
this->SHIFFT=SHIFFT;}
void shift::set_ID_EMPLOYE(QString ID_EMPLOYE){
    this->ID_EMPlOYE=ID_EMPLOYE;
}
void shift::set_DATEDUJOUR(QString DATEDUJOUR){
    this->DATEDUJOUR=DATEDUJOUR;
}

void shift::set_SHIFFT(QString SHIFFT){
    this->SHIFFT=SHIFFT;
}

QString shift::get_ID_EMPLOYE(){return ID_EMPlOYE;}
QString shift::get_DATEDUJOUR(){
    return DATEDUJOUR;}
QString shift::get_SHIFFT(){return SHIFFT;}
bool shift::ajouter_shift(){
    QSqlQuery query;
    query.prepare("INSERT INTO shift(ID_EMPLOYE,DATEDUJOUR,SHIFFT)VALUES(:ID_EMPLOYE,:DATEDUJOUR,:SHIFFT)");
    query.bindValue(":ID_EMPLOYE",ID_EMPlOYE);
    query.bindValue(":DATEDUJOUR",DATEDUJOUR);
    query.bindValue(":SHIFFT",SHIFFT);
            return  query.exec();
}
QSqlQueryModel * shift::afficher_shift()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from shift");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE DU JOUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SHIFT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
bool shift::supprimer_shift()
{
QSqlQuery query;
query.prepare("Delete from shift where (ID_EMPLOYE=:ID) AND (DATEDUJOUR=:DATEDUJOUR) AND (SHIFFT=:SHIFFT) ");
query.bindValue(":ID",ID_EMPlOYE);
query.bindValue(":DATEDUJOUR",DATEDUJOUR);
query.bindValue(":SHIFFT",SHIFFT);
   query.exec();
   return(query.numRowsAffected()>0);

}

QSqlQueryModel * shift::afficher_list(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id_employe||'#'||datedujour||'#'||shifft from shift");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employe||'#'||datedujour||'#'||shifft"));
return  model;
}
int shift::posD(QString ch){
    int i=0;
    while(ch[i]!='#'){
        i++;
    }
    return i;
}
void shift::generate_data(QString ch){
    QString ch1,ch2;
    int d=posD(ch);
  for(int i=0;i<d;i++){
      ch1=ch1+ch[i];
  }
  ID_EMPlOYE=ch1;
  ch.remove(0,d+1);
  d=posD(ch);
  for(int i=0;i<d;i++){
     ch2=ch2+ch[i];
  }
  DATEDUJOUR=ch2;
  ch.remove(0,d+1);
  SHIFFT=ch;
}

bool shift::modifier_shift(QString new_datedujour,QString new_shift){
    QSqlQuery query ;
     query.prepare("UPDATE shift SET DATEDUJOUR=:NEWDATEDUJOUR,SHIFFT=:NEWSHIFFT where (ID_EMPLOYE=:ID) AND (DATEDUJOUR=:DATEDUJOUR) AND (SHIFFT=:SHIFFT)");
     query.bindValue(":NEWDATEDUJOUR",new_datedujour);
     query.bindValue(":NEWSHIFFT",new_shift);
     query.bindValue(":ID",ID_EMPlOYE);
     query.bindValue(":DATEDUJOUR",DATEDUJOUR);
     query.bindValue(":SHIFFT",SHIFFT);
    query.exec();
    return(query.numRowsAffected()>0);

    }
QSqlQueryModel * shift::chercher_shift(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare("SELECT * from shift where id_employe like :nom or DATEDUJOUR like :nom or shifft like :nom order by  datedujour ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE DU JOUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SHIFT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
QSqlQueryModel * shift::afficher_trishift(QString tri)
{QSqlQueryModel * model= new QSqlQueryModel();
   QSqlQuery query;
query.prepare("select * from shift order by "+tri);
query.exec();
qDebug()<<tri;
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE DU JOUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SHIFT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
QSqlQueryModel * shift::afficher_trishiftDEC(QString tri)
{QSqlQueryModel * model= new QSqlQueryModel();
   QSqlQuery query;
query.prepare("select * from shift order by "+tri+" DESC");
query.exec();
qDebug()<<tri;
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE DU JOUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SHIFT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
