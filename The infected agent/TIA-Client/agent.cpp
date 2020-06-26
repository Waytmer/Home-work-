#include "agent.h"
#include <math.h>
#include <QPainter>
#include <ctime>


static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Agent::Agent(QObject *parent,int S_Agents,int S_AreaAgents):
    QObject(parent), QGraphicsItem()
{
    setRotation(0);    
    Traveling=false;
    SizeAgents=S_Agents;
    SizeAreaAgents=S_AreaAgents;
    TravelingQuarantine=false;
    AgentQuarantine=false;
    AgentMove=true;
    StartInfect=false;
    sectors=1;

    GameState=static_cast<state>(0);//все изначально здоровы
}

Agent::~Agent(){};

QRectF Agent::boundingRect() const
{
    return QRectF(0,0,SizeAgents,SizeAgents);
}
static qreal normalizeAngle(qreal angle)//для нормальногоо поворота агента
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}
void Agent::slotGameTimer()
{
//    if(GameState==Infection&&QuarantineStarting&&TravelingQuarantine==false&&AgentQuarantine==false){//проверка во время карантина агента и дальнейшее решение его судьбы(В карантин или нет)
//        if(rand()%(101-ChanceDetektdInfekt)==0){
//            TravelingQuarantine=true;//агент направляеться в карантин
//            SelectMovePoint();
//            AgentRotate();

//        }
//        else{
//            GameState=DontDetektInfection;//агента не заметили
//            DontDetektInfect=true;
//            DontDetektInfectHD=true;

//        }
//    }
//    if(1+rand()%100-TravelRate==0&&TravelingQuarantine==false&&Traveling==false){//шанс на то, что агент переместится в другой сектор
//        Traveling=true;//агент путешевствует
//        sectors=1+rand()%9;//выбор одного из 9 секторов
//        SelectMovePoint();
//        AgentRotate();
//    }

    if(Traveling){//агент в пути в другой сектор
        QLineF lineToTarget(QPoint(0,0), mapFromScene(i,q));
            if(lineToTarget.length() > 6){
                setPos(mapToParent(0, -6));}
            else {
                  Traveling=false;
                  AgentMove=false;
            }
    }//если агент прилетел в другой сектор, то он больше не путешевствует

    else if(TravelingQuarantine){//перемещение в карантин
         QLineF lineToTarget(QPoint(0,0), mapFromScene(i,q));
            if(lineToTarget.length() > 6){
                setPos(mapToParent(0, -6));}
            else {
                TravelingQuarantine=false;//агент больше не перемещаеться в карантин
                AgentQuarantine=true;
                AgentMove=false;//агент в карантине
            }
    }
    else{
    if((GameState==Infection&&AgentQuarantine==false)||GameState==DontDetektInfection){//если агент инфицированн и он не в карантине
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()//просчитываем всех itemos в зоне поражения
      << mapToScene(-SizeAreaAgents, SizeAreaAgents)
      << mapToScene(SizeAreaAgents,SizeAreaAgents)
      << mapToScene(SizeAreaAgents,-SizeAreaAgents)
      << mapToScene(-SizeAreaAgents,-SizeAreaAgents)
      );

    foreach (QGraphicsItem *item, foundItems) { // Проверяем все элементы
        if (item == this){ continue;}
        else{// Сама с собой не сталкивается
           Agent *A = qgraphicsitem_cast <Agent *> (item);
           if(this->sectors==A->sectors){//если агент в одном секторе с инфицированным
           A->agentInfection();}
           else{continue;}

        }
    }
    }

    QLineF lineToTarget(QPoint(0,0), mapFromScene(i,q));//если мы не попали никуда сверху то просто передвигаемся
        if(lineToTarget.length() > 4){
            setPos(mapToParent(0, -4));
        }
        else{

           AgentMove=false;

        }
 }
}

void Agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//рисование в зависимости от состояния агента
{

    switch (GameState) {

    case(0):
        painter->setBrush(Qt::green);
        painter->drawEllipse(0,0,SizeAgents,SizeAgents);
        break;
    case(1):
        painter->setBrush(Qt::red);
        painter->drawEllipse(0,0,SizeAgents,SizeAgents);
        break;
    case(2):
        painter->setBrush(Qt::darkGray);
        painter->drawEllipse(0,0,SizeAgents,SizeAgents);
        break;
    case(3):
        painter->setBrush(Qt::cyan);
        painter->drawEllipse(0,0,SizeAgents,SizeAgents);
        break;
    Q_UNUSED(option);
    Q_UNUSED(widget);
    }
}

void Agent::agentInfection(bool infectionInitialize){//заражениие агента

    if(infectionInitialize){//если агент неболен или это 1 зараженный агент
    GameState=Infection;//меняем состояние

    }
    else{
        StartInfect=true;
    }

}

void Agent::AgentRotate(){//Поворот объекта
    QLineF lineToTarget(QPointF(0, 0), mapFromScene(i,q));
   // Угол поворота в направлении к цели
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

     // Поворачиваем героя к цели
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        // Rotate lef
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        // Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
   }
}

void Agent::SelectMovePoint(int I, int Q){
    i=I;
    q=Q;
}

bool Agent::GetTravel(){
    return Traveling;
}

bool Agent::GetStartInfect(){
    return StartInfect;
}

bool Agent::GetMoveState(){
    return AgentMove;
}

bool Agent::GetTravelQuarantine(){
    return TravelingQuarantine;
}
int Agent::GetStatus(){
    return GameState;
}

void Agent::SetStatus(int states){
    GameState=static_cast<state>(states);
}

void Agent::SetTravel(){
    Traveling=true;
}
void Agent::SetTravelQuarantine(){
    TravelingQuarantine=true;
}
void Agent::SetMoveState(){
    AgentMove=true;
}

int Agent::GetSector(){
return sectors;
}

void Agent::SetSector(int sector){
    sectors=sector;
}
