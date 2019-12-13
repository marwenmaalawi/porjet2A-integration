#include "clients.h"

Clients::Clients()
{
   nom="";
   prenom="";
   num_passeport="";
   nationnalite="";
   email="";
   num_telephone="";
   nb_voyages=0;
}

Clients::Clients(QString nom,QString prenom,QString num_passeport,QString nationnalite,QString email,QString num_telephone,int nb_voyages)
{
    this->nom=nom;
    this->prenom=prenom;
    this->num_passeport=num_passeport;
    this->nationnalite=nationnalite;
    this->email=email ;
    this->num_telephone=num_telephone ;
    this->nb_voyages=nb_voyages;

}

QString Clients::getemail()
{return email;}
QString Clients::getnum_telephone()
{return num_telephone;}
int Clients::getnb_voyages()
{return nb_voyages;}
QString Clients::getnom()
{return nom;}
QString Clients::getprenom()
{return prenom;}
QString Clients::getnumpasseport()
{return num_passeport;}
QString Clients::getnationnalite()
{return nationnalite;}

void Clients::set_num_passeport(QString num_passeport)
{this->num_passeport=num_passeport; }
bool Clients::ajouter_client()
{
QSqlQuery query;
query.prepare("INSERT INTO CLIENTS (NOM,PRENOM,NUM_PASSEPORT,NATIONNALITE,EMAIL,NUM_TELEPHONE,NB_VOYAGES) "
                    "VALUES (:nom,:prenom,:num_passeport,:nationnalite,:email,:num_telephone,:nb_voyages)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":num_passeport", num_passeport);
query.bindValue(":nationnalite", nationnalite);
query.bindValue(":email", email);
query.bindValue(":num_telephone", num_telephone);
query.bindValue(":nb_voyages", nb_voyages);
return    query.exec();
}
QSqlQueryModel * Clients::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_passeport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationnalite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_telephone"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("nb_voyages"));
    return model;
}

QSqlQueryModel * Clients::afficher_listclient()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select num_passeport from CLIENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_passeport"));
return model;
}


bool Clients::supprimer_clients(QString num_passeport)
{
QSqlQuery query;
//bool test=false;
query.prepare("Delete from clients where num_passeport = :num_passeport");
query.bindValue(":num_passeport", num_passeport);

 return    query.exec();

}


bool Clients::rech(QString x){
    QSqlQuery query;
    query.prepare("select * from CLIENTS where num_passeport = :num_passeport;");
    query.bindValue(":num_passeport", x);
    return query.exec();
}

bool Clients::modifier(QString a,QString b,QString c,QString d,QString e, QString f, int g){
    QSqlQuery query;
    query.prepare("update CLIENTS set nom=:nom ,prenom=:prenom ,num_passeport=:num_passeport  ,nationnalite=:nationnalite  where num_passeport=:num_passeport;");
    query.bindValue(":nom", a);
    query.bindValue(":prenom", b);
    query.bindValue(":num_passeport",c);
    query.bindValue(":nationnalite", d);
    query.bindValue(":email", e);
    query.bindValue(":num_telephone", f);
    query.bindValue(":nb_voyages", g);

    return query.exec();
}

QSqlQueryModel * Clients::afficher_tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_passeport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationnalite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_telephone"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("nb_voyages"));
    return model;
}
QSqlQueryModel * Clients::afficher_tri_prenom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS order by prenom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_passeport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationnalite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_telephone"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("nb_voyages"));
    return model;
}
void Clients::rechercher_client(QTableView *table,QString s)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Select * from CLIENTS where (regexp_like(num_passeport,:num_passeport))");
    qry.bindValue(":num_passeport",s);
    qry.exec();
    model->setQuery(qry);
    table->setModel(model);
    table->show();
}
QSqlQueryModel * Clients ::stats()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("SELECT Num_passeport, Nationnalite,((Num_passeport*100)/(select SUM(Num_passeport) from CLIENTS) from CLIENTS");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_passeport"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nationnalite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

            return model;


}
bool Clients::verif_mail(QString ch)
{bool test=false ; int i,j;
 for (i=0;i<ch.length();i++)
{ if(ch[i]=='@')
     { for (j=i;j<ch.length();j++)
         {if ((ch[j]=='.')&&(j>i+1)){test=true;break;}

        }}}
 return test ;


 }
void Clients::notification_ajout_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été ajouter!",QSystemTrayIcon::Information,15000);
//num++;
}

void Clients::notification_supprimer_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été supprimer!",QSystemTrayIcon::Information,15000);
//num++;
}



void Clients::notification_modifier_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été modifier!",QSystemTrayIcon::Information,15000);
//num++;
}

