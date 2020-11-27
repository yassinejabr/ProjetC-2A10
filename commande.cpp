#include "commande.h"
#include <QSqlQuery>
#include <QDebug>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QObject>

commande::commande()
{
idcmd=0;
idprod=0;
dateliv="";
idclient=0;
destin="";
}
commande::commande(int idcmd,int idprod,QString dateliv,int idclient,QString destin)
{
    this->idcmd=idcmd; this->idprod=idprod; this->dateliv=dateliv; this->idclient=idclient; this->destin=destin;
}

QSqlQueryModel* commande:: afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT *  FROM COMMANDES");
          model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID Commande"));
          model->setHeaderData(1,Qt::Horizontal, QObject::tr("ID Produit"));
          model->setHeaderData(2,Qt::Horizontal, QObject::tr("Date livraison"));
          model->setHeaderData(3,Qt::Horizontal, QObject::tr("ID Client"));
          model->setHeaderData(4,Qt::Horizontal, QObject::tr("Destination"));
    return model;

}


int commande::get_idcmd(){return idcmd;}
int commande::get_idprod(){return idprod;}
QString commande::get_dateliv(){return dateliv;}
int commande::get_idclient(){return idclient;}
QString commande::get_destin(){return destin;}

void commande::setidcmd(int idcmd){this->idcmd=idcmd;}
void commande::setidprod(int idprod){this->idprod=idprod;}
void commande::setdateliv(QString dateliv){this->dateliv=dateliv;}
void commande::setidclient(int idclient){this->idclient=idclient;}
void commande::setdestin(QString destin){this->destin=destin;}

bool commande::ajouter()
{
   bool test=false;
    QString idcmd_string=QString::number(idcmd);
    QString idprod_string=QString::number(idprod);
    QString idclient_string=QString::number(idclient);
    QSqlQuery query;
          query.prepare("INSERT INTO COMMANDES (IDCMD, IDPROD, DATELIV,IDCLIENT,DESTIN) "
                        "VALUES (:idcmd, :idprod, :dateliv, :idclient, :destin)");
          query.bindValue(":idcmd", idcmd_string);
          query.bindValue(":idprod", idprod_string);
          query.bindValue(":dateliv", dateliv);
          query.bindValue(":idclient", idclient_string);
          query.bindValue(":destin", destin);
           return query.exec();



    return test;
}

bool commande::supprimer(int idcmd)
{
QString idcmd_string=QString::number(idcmd);
        QSqlQuery query;
             query.prepare(" Delete from COMMANDES where idcmd=:idcmd");
             query.bindValue(0, idcmd_string);

            return query.exec();

}

bool commande::modifier()
{
    QString idcmd_string=QString::number(idcmd);
    QString idprod_string=QString::number(idprod);
    QString idclient_string=QString::number(idclient);
    QSqlQuery query;
          query.prepare("UPDATE COMMANDES  SET IDPROD = idprod, DATELIV = dateliv , IDCLIENT = idclient , DESTIN = destin WHERE  IDCMD= :idcmd ");
          query.bindValue(":idcmd", idcmd_string);
          query.bindValue(":idprod", idprod_string);
          query.bindValue(":dateliv", dateliv);
          query.bindValue(":idclient", idclient_string);
          query.bindValue(":destin", destin);
           return query.exec();

}
