#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>
#include <QSqlQueryModel>
#include "qprinter.h"
#include "qprintdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_affiche_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();

    void on_print_button1_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    commande tmpcmd;


};
#endif // MAINWINDOW_H
