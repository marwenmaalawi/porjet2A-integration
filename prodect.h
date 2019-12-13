#ifndef PRODECT_H
#define PRODECT_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
class prodect
{
public:
    prodect();
    prodect(QString ,QString ,QString,QString,QString );

    QString get_id();
    QString get_type();
    QString get_date_fabrication();
    QString get_date_expiration();
    QString get_ID_FOURNISSEUR();
    void set_id(QString id_produit);
    void set_date_expiration(QString date_expiration);
    void set_date_fabrication(QString date_fabrication);
    void set_type(QString type);
    void set_ID_FOURNISSEUR(QString);
    bool ajouter_produit();
    QSqlQueryModel * afficher_produit();
    bool supprimer_produit(QString);
    QSqlQueryModel * afficher_listprodect();
    bool  modifier_produit();

private:
    QString id_produit,type,date_fabrication,date_expiration,ID_FOURNISSEUR;
};

#endif // PRODECT_H

