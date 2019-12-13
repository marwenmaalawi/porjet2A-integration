#ifndef SHIFT_H
#define SHIFT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <datapath.h>


class shift
{
public:

    shift();
    shift(QString ID_EMPLOYE, QString DATEDUJOUR,QString SHIFFT);
    void set_ID_EMPLOYE(QString ID_EMPLOYE);
    QString get_DATEDUJOUR();
    QString get_SHIFFT();
    QString get_ID_EMPLOYE();
    QString get_NOM();
    void set_DATEDUJOUR(QString);
    void set_SHIFFT(QString);
    bool ajouter_shift();
    QSqlQueryModel * afficher_shift();
    bool modifier_shift (QString,QString);
    bool supprimer_shift() ;
    QSqlQueryModel * afficher_list();
    void generate_data(QString);
    int posD(QString);
    QSqlQueryModel * chercher_shift(QString );
    QSqlQueryModel * afficher_trishift(QString);
    QSqlQueryModel * afficher_trishiftDEC(QString);
private:
  QString ID_EMPlOYE;
  QString DATEDUJOUR;
  QString SHIFFT ;
};

#endif // SHIFT_H
