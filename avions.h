#ifndef AVIONS_H
#define AVIONS_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QSystemTrayIcon>
class avions
{
public:
    avions();
    avions(QString,QString,QString);
    void initialiser();
    QString get_id();
    QString get_etat();
    QString get_ID_CONSTRUCTEUR();
    void set_id(QString);
    void set_etat(QString);
    void set_ID_CONSTRUCTEUR(QString);

    QSqlQueryModel * afficher_tri_id();
    QSqlQueryModel * afficher_tri_id_desc();

    QSqlQueryModel * afficher_tri_etat();
    QSqlQueryModel * afficher_tri_etat_desc();

    QSqlQueryModel * afficher_tri_ID_CONSTRUCTEUR();
     QSqlQueryModel * afficher_tri_ID_CONSTRUCTEUR_desc();

    QSqlQueryModel * chercher_avions_id(QString nom);
    QSqlQueryModel * chercher_avions_etat(QString nom);
    QSqlQueryModel * chercher_avions_ID_CONSTRUCTEUR(QString nom);

    QSqlQueryModel * afficher_avions();
    QSqlQueryModel * afficher_avionslist();

    QSqlQueryModel * stats();
    QSqlQueryModel * getIdModel();

    bool supprimer_avions(QString);
    bool ajouter_avions();
    bool modifier();

    QSqlQuery  afficher_etat();
    QSqlQuery chercher_id(QString id);
    bool verif_id_avions(QString);
    void notification_ajout_avion(QString);


private:
    QString id,etat,ID_CONSTRUCTEUR;
};

#endif // AVIONS_H
