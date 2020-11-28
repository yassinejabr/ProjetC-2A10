#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "produit.h"
#include "QMessageBox"
#include <QPrinter>
#include <QPrintDialog>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableCmd->setModel(tmpcmd.afficher());
    player = new QMediaPlayer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Yacyn/Desktop/validation 2/ProjektYassine/song.mp3"));
    player->play();
    qDebug() << player ->errorString();
}

void MainWindow::on_pb_ajouter_clicked()
{
    int idcmd=ui->le_idcmd->text().toInt();
    int idprod=ui->le_idprod->text().toInt();
    int idclient=ui->le_idclient->text().toInt();
    QString destin=ui->le_destin->text();
    QString dateliv=ui->le_dateliv->text();
    commande c(idcmd,idprod,dateliv,idclient,destin);

       commande a;
       bool test = a.ajouter();

       if(test)
     {
     QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                       QObject::tr("Commande ajouté.\n"
                                   "Click OK to continue."), QMessageBox::Ok);
             ui->tableCmd->setModel(tmpcmd.afficher());

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}






void MainWindow::on_pb_supp_clicked()
{
    {
        commande s;
        s.setidcmd(ui->le_idcmd->text().toInt());
        bool test=s.supprimer(s.get_idcmd());

        if(test)
           {      QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                                           QObject::tr("Commande supprimée.\n"
                                                       "Click OK to continue."), QMessageBox::Ok);
        ui->tableCmd->setModel(tmpcmd.afficher());

        }
        else
            QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                                                       QObject::tr("Erreur!.\n"
                                                                   "Click OK to continue."), QMessageBox::Ok);

    }

}

void MainWindow::on_pb_modif_clicked()
{
    int idcmd=ui->le_idcmd->text().toInt();
    int idprod=ui->le_idprod->text().toInt();
    int idclient=ui->le_idclient->text().toInt();
    QString destin=ui->le_destin->text();
    QString dateliv=ui->le_dateliv->text();
    commande c(idcmd,idprod,dateliv,idclient,destin);

       commande m;
       bool test = m.modifier();

       if(test)
     {
     QMessageBox::information(nullptr, QObject::tr("Modifier une commande"),
                       QObject::tr("Commande Modifié.\n"
                                   "Click OK to continue."), QMessageBox::Ok);
             ui->tableCmd->setModel(tmpcmd.afficher());

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modifier une commande"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_affiche_clicked()
{

}

void MainWindow::on_print_button1_clicked()
{
    QPrinter *imprimante;
    QPrintDialog pd(this);
    if(pd.exec()== QDialog::Rejected) return;
    imprimante=pd.printer();
    imprimante->setOutputFormat(QPrinter::PdfFormat);
    imprimante->setOutputFileName("C:/Users/Yacyn/Desktop/validation 2/imprimer.pdf");

}
