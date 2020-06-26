#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
//#include <QGraphicsEllipseItem>

class Agent: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Agent(QObject *parent = 0,int S_Agents=0,int S_AreaAgents=0);
    ~Agent();
    int i=0;//x
    int q=0;//y
    int infectiousness;//шанс заразиться
    enum state{//состояние агента
        Susceptible
       ,Infection
       ,Removed
       ,DontDetektInfection
       ,Dead
    };
    state GameState=Susceptible;
private:
    int sectors;//выбор сектора

    int SizeAgents;//размер агента
    int SizeAreaAgents;//размер области заражения
    bool AgentQuarantine;//агент в карантини
    bool AgentMove;
    bool StartInfect;
    bool Traveling;
    bool TravelingQuarantine;
public:
    bool GetTravel();
    bool GetStartInfect();
    bool GetTravelQuarantine();
    bool GetMoveState();
    int GetStatus();
    void SetStatus(int states);
    void SetTravel();
    void SetTravelQuarantine();
    void SetMoveState();
    int GetSector();
    void SetSector(int sector);


signals:


private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void SetRotation();
private:
    //QTimer *gameTimer;      // Игровой таймер
   // QTimer *timeInfection;

public slots:
    void slotGameTimer();   // Игровой слот
    void agentInfection(bool infectionInitialize=false);
   // void infectionLater();
    void AgentRotate();
    void SelectMovePoint(int I,int Q);
};


#endif // AGENT_H
