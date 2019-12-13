#ifndef GERER_VOLS_H
#define GERER_VOLS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class gerer_vols
{
public:
    gerer_vols();
    gerer_vols(int,QString,QString,QString,QString);
      int get_N_VOL();
      QString get_HEURE();
      QString get_ORIGINE();
      QString get_STATUT();
      QString get_ID_DEST();
       void set_N_VOL(int );
       void set_HEURE(QString);
       void set_ORIGINE(QString);
       void set_STATUT(QString);
       void set_ID_DEST(QString);
       bool ajouter_vol();
      QSqlQueryModel * afficher_vol();
      bool supprimer_vol (int);
      QSqlQueryModel * afficher_vollist();
      bool modifier_vols();
      void chercher_vol();
      QSqlQueryModel * chercher_vols(QString);

private:
      QString HEURE,ORIGINE,STATUT,ID_DEST;
      int N_VOL ;


};

#endif // GERER_VOLS_H
