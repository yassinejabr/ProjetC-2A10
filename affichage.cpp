#include "affichage.h"
#include "ui_affichage.h"

affichage::affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affichage)
{
    ui->setupUi(this);
}

affichage::~affichage()
{
    delete ui;
}
//void affichage::setidcmd(commande c)
//{
    //ui->lineEdit_cmd1->setText(c.get_idcmd());
    //ui->lineEdit_prod1->setText(c.get_idprod());
    //ui->lineEdit_date1->setText(c.get_dateliv());
    //ui->lineEdit_client1->setText(c.get_idclient());
    //ui->lineEdit_destin1->setText(c.get_destin());//

//}

void affichage::on_pushButton_clicked()
{

}
