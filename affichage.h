#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "commande.h"

#include <QDialog>

namespace Ui {
class affichage;
}

class affichage : public QDialog
{
    Q_OBJECT

public:
    explicit affichage(QWidget *parent = nullptr);
    void setidcmd(commande c);
    ~affichage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::affichage *ui;
};

#endif // AFFICHAGE_H
