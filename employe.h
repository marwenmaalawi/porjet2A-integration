#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(QString ID_EMPLOYE,QString ASSIDUITE,QString AVANTAGE,int SOLDE_DE_CONGE,int ABSENCE,int SALAIRE,int RANG,QString NOM,QString PRENOM);

    QString get_ID_EMPLOYE();
    QString get_ASSIDUITE();
    QString get_AVANTAGES();
    void set_ID_EMPLOYE(QString ID_EMPLOYE);
    int  get_SOLDE_DE_CONGE();
    int  get_ABSENCE();
    int  get_SALAIRE();
    int  get_RANG();
    QString get_NOM();
    QString get_PRENOM();
    bool ajouter_employe();
    QSqlQueryModel * afficher_employe();
    bool modifier_employe ();
    bool supprimer_employe(QString ID) ;
    QSqlQueryModel * afficher_list();
    void chercher();
   QSqlQueryModel * chercher_employe(QString );
   QSqlQueryModel * afficher_triemploye(QString tri);
   QSqlQueryModel * afficher_triemployeDEC(QString tri);
   QSqlQuery afficher_prenom();
   QSqlQuery afficher_salaire();


private:
QString ID_EMPLOYE,ASSIDUITE,AVANTAGE,NOM,PRENOM;
int SOLDE_DE_CONGE,ABSENCE, SALAIRE,RANG;
};

#endif // EMPLOYE_H
