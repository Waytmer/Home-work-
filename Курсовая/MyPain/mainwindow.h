#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customscene.h"
#include "agent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void myAgentInfection();
private:
    Ui::MainWindow *ui;
    CustomScene *scene;
    QList<QGraphicsItem *> agents;
    Agent *agent;
    int ResolutionX;
    int ResolutionY;
    int Sectors;
private slots:
    void slotInfection(QGraphicsItem *item);
};
#endif // MAINWINDOW_H
