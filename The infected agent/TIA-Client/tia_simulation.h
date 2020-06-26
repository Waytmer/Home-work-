#ifndef TIA_SIMULATION_H
#define TIA_SIMULATION_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QMessageBox>
#include "customscene.h"
#include "agent.h"
#include "score.h"
#include "clock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TIA_Simulation; }
QT_END_NAMESPACE

class TIA_Simulation : public QMainWindow
{
    Q_OBJECT

public:
    TIA_Simulation(QWidget *parent = nullptr,QString IP="",int NAgents=0,int SAgents=0,int SAreaAgents=0,int CDead=0,int CInfected=0,int CTravel=0,int THealth=0,int CDetectedInfection=0,int SQuarantine=0,bool IDesdly=0,bool IHealth=0,bool ISectors=0,bool IQuarantine=0);
    ~TIA_Simulation();
signals:

private:
    Ui::TIA_Simulation *ui;
    QGraphicsScene *scene;
    QList<QGraphicsItem *> agents;
    QList<QGraphicsTextItem *> scoures;
    Agent *agent;
    int ResolutionX;//размер экрана по x
    int ResolutionY;//размер экрана по y
    int Sectors;
    int NumberOfAgent;//колличество агентов
    int IncludeInfected;//инфицированный агент
    int StartQuarantine;//тот, с кого начнеться карантин
    int SizeAgent;
    int SizeZoneAgent;
    bool IsQuarantine;//проверка на режим карантина
    bool IsSectors;
    bool QuarantineStarting;
    int NumberClient;
    QByteArray NClient;
    Score *NumbersOfHealth;//счет всех
    Score *NumbersOfInfected;
    Score *NumbersOfRemoved;
    Score *NumbersOfDead;
    Score *NumbersOfSecretInfected;
    Clock *clock;
    QTcpSocket* socket;
    QByteArray Data;
    QJsonDocument doc;
    QJsonParseError docError;

private slots:
    //void slotGameTimer();
    void slotReady();
    void slotDisc();
    //void slotDontConnected(QAbstractSocket::SocketError);

};


#endif // TIA_SIMULATION_H
