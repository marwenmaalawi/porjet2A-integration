#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("marwen");
    db.setPassword("esprit18");
    if(db.open())
    {test=true;}
    else
    {throw QString("Erreur paramétres"+test);}
    return  test;
}
void connexion::fermerConnexion()
{db.close();}
