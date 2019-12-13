#include "admin.h"
#include <QSqlQuery>
#include <QDebug>
admin::admin()
{

}
admin::admin(QString id,QString mdp){

    this->id=id;
    this->mdp=mdp;
}
bool admin::chercher(QString ID, QString MDP){
QSqlQuery  query1; QString id_admin,mpd_admin;
query1.prepare("SELECT id,mdp from admin where id=:ID");
query1.bindValue(":ID",ID);
query1.exec();
  while(query1.next()){
    id=query1.value(0).toString();
  mdp=query1.value(1).toString();
  }
  if((id==ID)&&(mdp==MDP)){
      return  true;
  }else{
      return  false;
  }
}
