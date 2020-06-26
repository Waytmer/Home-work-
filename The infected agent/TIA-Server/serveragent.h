#ifndef SERVERAGENT_H
#define SERVERAGENT_H

#include "random"
#include<QTimer>
#include<QObject>
class ServerAgent:public QObject
{
    Q_OBJECT
public:
    explicit ServerAgent(QObject *parent = 0, int sectorsg=0,int C_Dead=0,int C_Infected=0,int C_Travel=0,int T_Health=0,int C_DetektedInfection=0, bool I_Deadly=0,bool I_Health=0,bool I_Sectors=0);

    void SelectMovePoint();
    void agentInfection(bool infectionInitialize);
    void infectionLater();
    void slotGameTimer();
    int GetI();
    int GetQ();
    int GetStatus();
    int GetSector();
    bool GetTraveling();
    bool GetTravelingQuarantine();
    void SetTraveling();
    void SetTravelingQuarantine();
    void SetQuarantineStarting();
    bool GetQuarantineStarting();


private:
    int ResolutionX;
    int ResolutionY;
    int i;//x
    int q;//y
    int infectiousness;//шанс заразиться
    enum state{//состояние агента
        Susceptible
       ,Infection
       ,Removed
       ,DontDetektInfection
       ,Dead
    };
    state GameState=Susceptible;
    int sectors;//выбор сектора
    int TravelRate;//шанс переехать
    int ChanceDead;//шанс умереть(
    int ChanceDetektdInfekt;//шанс не попасть в карантин
    int TimeHealth;//время до выздоровления или смерти как повезет
    bool Traveling;//агент путешествует?
    bool TravelingQuarantine;//агент идет в карантин?
    bool IsDeadly;//агент может умереть?
    bool IsHealth;//агент может выздоровить?
    bool IsSectors;//режим странны?
    bool QuarantineStarting;//да начнеться карантин
    bool AgentQuarantine;//агент в карантине
    QTimer *timeInfection;
};

#endif // SERVERAGENT_H
