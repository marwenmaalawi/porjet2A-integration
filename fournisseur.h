#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
class fournisseur
{
public:
    fournisseur();
    fournisseur (QString,QString,QString);
    QString get_id();
    QString get_nom();
    QString get_mail();
    void set_id(QString id);
    void set_nom(QString nom);
    void set_mail(QString mail);
    bool ajouter_fournisseur();
    QSqlQueryModel * afficher_fournisseur();
    bool supprimer_fournisseur(QString);
    QSqlQueryModel * afficher_listfournisseur();
    bool modifier_fournisseur();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * stats();
private:
    QString id,nom,mail;
};

#endif // FOURNISSEUR_H
