#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "tia_simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();


public slots:

private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;

    TIA_Simulation *w;
    int NumberOfAgents;
    int SizeAgents;
    int SizeTheAffectedArea;
    int ChanceOfDead;
    int ChanceOfInfected;
    int ChanseOfTravel;
    int ChanseOfDetektedInfektion;
    int StartQuarantin;
    int TimeToHelalth;
    bool IsDeadly;
    bool isHealth;
    bool isSectors;
    bool IsQuarantin;
    QString IP;
};
#endif // MENU_H
