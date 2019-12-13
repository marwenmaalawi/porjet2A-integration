#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QSystemTrayIcon>
class constructeur
{
public:
    constructeur();
    constructeur(QString,QString,QString);
    void initialiser();
    QString get_id();
    QString get_nom();
    QString get_mail();
    void set_id(QString);
    void set_nom(QString);
    void set_mail(QString);

    QSqlQueryModel * afficher_tri_id();
    QSqlQueryModel * afficher_tri_nom();
    QSqlQueryModel * afficher_tri_mail();
    QSqlQueryModel * afficher_tri_id_desc();
    QSqlQueryModel * afficher_tri_nom_desc();
    QSqlQueryModel * afficher_tri_mail_desc();

    bool ajouter_constructeur();
    QSqlQueryModel * afficher_constructeur();
    bool supprimer_constructeur(QString);
    QSqlQueryModel * afficher_constructeurlist();
    bool modifier_constructeur();
    QSqlQueryModel * chercher_constructeur_id(QString nom);
    QSqlQueryModel * chercher_constructeur_nom(QString nom);
    QSqlQueryModel * chercher_constructeur_mail(QString nom);

    QSqlQueryModel * getIdModel();
     QSqlQueryModel * getMailModel();

    QSqlQuery chercher_id(QString );
    void notification_ajout_constructeur(QString);

    bool verif_email(QString);
    bool verif_id(QString);
    bool verif_nom(QString);


private:
    QString id,nom,mail;
};

#endif // CONSTRUCTEUR_H
