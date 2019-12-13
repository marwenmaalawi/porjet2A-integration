#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>


class connexion
{
public:
    connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
