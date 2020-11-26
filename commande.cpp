#include "commande.h"

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
