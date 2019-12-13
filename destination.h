#ifndef DESTINATION_H
#define DESTINATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class destination
{
public:
    destination();
    destination(QString,QString,int);
      QString get_id();
      QString get_ville();
      int get_duree();
      void set_id(QString);
      void set_duree(int );
      void set_ville(QString);
       bool ajouter_dest();
      QSqlQueryModel * afficher_dest();
      bool supprimer_destination (QString);
      QSqlQueryModel * afficher_destlist();
      bool modifier_destination();
      void chercher_dest();
       QSqlQueryModel * chercher_destination(QString);

private:
      QString id,ville;
      int duree;



};

#endif // DESTINATION_H
