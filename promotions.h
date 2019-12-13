#ifndef PROMOTIONS_H
#define PROMOTIONS_H
#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include<QTableView>
#include <QSystemTrayIcon>
#include<QString>
class Promotions
{
public:
    Promotions();
    Promotions(QString,QString,QString,QString);
    void set_num_passeport(QString);
    void set_id(QString);
    QString getpourcentage();
    QString getID_PROMO();
    QString getnum_passeport();
    QString getevenement();
    bool ajouter_promotions();
    bool supprimer_promotions(QString);
    void rechercher_promotion(QTableView *table,QString s);
    QSqlQueryModel *afficher_tri_ID();
    QSqlQueryModel *afficher_tri_pourcentage();
    void notification_ajout_promo(QString id);
    void notification_modifier_promo(QString id);
    void notification_supprimer_promo(QString id);

    QSqlQueryModel * afficher();
    bool rech(QString);
    bool modifier(QString,QString,QString,QString);
    QSqlQueryModel * afficher_listpromo();

private :
      QString pourcentage,ID_PROMO,num_passeport,evenement;



};

#endif // PROMOTIONS_H
