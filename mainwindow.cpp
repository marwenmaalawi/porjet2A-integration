#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion.h"
#include "admin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{gestion g;
    QString ID,MOT_de_passe;
ID=ui->admin_id->text();
MOT_de_passe=ui->admin_mdp->text();
if((ID!="")&&(MOT_de_passe!=""))
{if(a.chercher(ID,MOT_de_passe)){
    g.exec();}

}}

