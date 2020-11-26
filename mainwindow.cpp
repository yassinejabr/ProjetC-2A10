#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"

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


void MainWindow::on_pushButton_1_clicked()
{
    commande c;
    c.setidcmd(ui->lineEdit_cmd1->text());
    c.setidprod(ui->lineEdit_prod1->text());
    c.setdateliv(ui->lineEdit_date1->text());
    c.setidclient(ui->lineEdit_client1->text());
    c.setdestin(ui->lineEdit_destin1->text());

}


