#include "constructeur.h"
#include <QDebug>

constructeur::constructeur()
{

}

constructeur::constructeur(QString id,QString nom,QString mail)
{
  this->id=id;
  this->nom=nom;
  this->mail=mail;
}
QString constructeur::get_nom(){return  nom;}
QString constructeur::get_mail(){return mail;}
QString constructeur::get_id(){return  id;}
void constructeur::set_id(QString id){this->id=id;};
void constructeur::set_nom(QString nom ){this->nom=nom;};
void constructeur::set_mail(QString mail ){this->mail=mail;};

bool constructeur::ajouter_constructeur()
{
QSqlQuery query;

query.prepare("INSERT INTO constructeur (ID_CONSTRUCTEUR, NOM, MAIL) "
                    "VALUES (:id, :nom, :mail)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":mail", mail);

return    query.exec();
}

QSqlQueryModel * constructeur::afficher_constructeur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by id_constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_id_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by id_constructeur desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_nom
()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_nom_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by nom desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_mail()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by mail");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_mail_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by mail desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}


bool constructeur::supprimer_constructeur(QString idd)
{
QSqlQuery query;

query.prepare("Delete from constructeur where ID_CONSTRUCTEUR = :idd ");
query.bindValue(":idd", idd);
return    query.exec();
}
QSqlQueryModel * constructeur::afficher_constructeurlist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id_constructeur from constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
    return model;
}

bool constructeur::modifier_constructeur()
{
    QSqlQuery query;
    query.prepare("UPDATE constructeur set nom=:nom, mail=:mail where id_constructeur =:idd ");
    query.bindValue(":idd",id);
    query.bindValue(":nom",nom);
    query.bindValue(":mail",mail);
    return    query.exec();

}
QSqlQueryModel * constructeur::chercher_constructeur_id(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where id_constructeur like :nom order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::chercher_constructeur_nom(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where nom like :nom  order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::chercher_constructeur_mail(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where mail like :nom order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}


QSqlQueryModel * constructeur::getIdModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select id_constructeur from constructeur");
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel * constructeur::getMailModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select mail from constructeur");
    query->exec();
    model->setQuery(*query);
    return model;
}


QSqlQuery  constructeur::chercher_id(QString id){
     QSqlQuery query;

     query.exec("select * from constructeur where id_constructeur ='"+id+"'");
  query.exec();
  return query;}
void constructeur::notification_ajout_constructeur(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    QString s = id;
    notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau constructeur a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}



bool constructeur::verif_email(QString mail){
   bool test=false;
   int i;
   for(i=0;i<mail.length();i++)
   {
       if(mail[i]=='@'){
       test=true;
       }
   }

return test;}
bool constructeur::verif_id(QString ch_id){
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
bool constructeur::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;

        }
    }
  }
    return  test;
}

