#ifndef CLIENTS_H
#define CLIENTS_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QVector>
#include<QTableView>
#include <QSystemTrayIcon>
#include<QString>
class Clients
{
public:
    Clients();
    Clients(QString,QString,QString,QString,QString,QString,int);
    QString getnom();
    QString getprenom();
    QString getcin();
    QString getnumpasseport();
    QString getnationnalite();
    QString getemail();
    QString getnum_telephone();
    int getnb_voyages();
    void set_num_passeport(QString);
    bool ajouter_client();
    bool supprimer_clients(QString);
    void notification_ajout_client(QString id);
    void notification_supprimer_client(QString id);
    void notification_modifier_client(QString id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_tri_nom();
    QSqlQueryModel * afficher_tri_prenom();

    bool rech(QString);
  bool modifier(QString a,QString b,QString c,QString d,QString e, QString f, int g);
    QSqlQueryModel * afficher_listclient();
void rechercher_client(QTableView *table,QString s);
QSqlQueryModel *stats();

bool verif_mail(QString);

private :
      QString nom;
      QString prenom;
      QString num_passeport;
      QString nationnalite;
      QString email;
      QString num_telephone;
      int nb_voyages;
};

#endif // CLIENTS_H
