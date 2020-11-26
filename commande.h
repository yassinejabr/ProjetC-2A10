#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>

class commande
{
public:
    commande();
    commande(int idcmd,int idprod,QString dateliv,int idclient,QString destin);

    void setidcmd(int);
    void setidprod(int);
    void setdateliv(QString);
    void setidclient(int);
    void setdestin(QString);
    int get_idcmd();
    int get_idprod();
    QString get_dateliv();
    int get_idclient();
    QString get_destin();
private:
    QString dateliv,destin;
    int idcmd,idprod,idclient;
};

#endif // COMMANDE_H
