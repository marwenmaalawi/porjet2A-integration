#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    try {
        c.ouvrirConnexion();
        w.show();
    } catch (QString s) {
        qDebug()<<s;

    }
    return a.exec();
}
