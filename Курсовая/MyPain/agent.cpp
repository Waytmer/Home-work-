#include "agent.h"
#include <math.h>
#include <QPainter>
#include <ctime>


static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Agent::Agent(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    setRotation(0);

    //state = STOP;
    gameTimer = new QTimer();   // Инициализируем игровой таймер
    // Подключаем сигнал от таймера и слоту обработки игрового таймера
    connect(gameTimer, &QTimer::timeout, this, &Agent::slotGameTimer);
    GameState=static_cast<state>(0);
    q=0;
    i=0;
    gameTimer->start(5);   // Стартуем таймер
}

Agent::~Agent(){};

QRectF Agent::boundingRect() const
{
    return QRectF(0,0,5,5);
}
static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}
void Agent::slotGameTimer()
{
         

    if(GameState==Infection){
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
      << mapToScene(-8, 8)
      << mapToScene(8,8)
      << mapToScene(8,-8)
      << mapToScene(-8,-8)
      );

    foreach (QGraphicsItem *item, foundItems) { // Проверяем все элементы
        if (item == this){ continue;}
        else{// Сама с собой  не сталкивается
     emit signalCheckItem(item);} // дл остальных объектов выслыаем сигнал
        }
    }
        QLineF lineToTarget(QPoint(0,0), mapFromScene(i,q));
        if(lineToTarget.length() > 2){
            setPos(mapToParent(0, -2));
        }
        else{

            q=rand() % 600;
            i=rand() % 600;

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

}

void Agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int in=5;
    switch (GameState) {

    case(0):
    painter->setBrush(Qt::green);
    painter->drawEllipse(0,0,in,in);
        break;
    case(1):
        painter->setBrush(Qt::red);
        painter->drawEllipse(0,0,in,in);
        break;
    case(2):
        painter->setBrush(Qt::darkGray);
        painter->drawEllipse(0,0,in,in);
        break;
    Q_UNUSED(option);
    Q_UNUSED(widget);
    }
}

QPainterPath Agent::shape() const
{
    QPainterPath path;
    path.addEllipse(0,0,6,6);
    return path;
}

void Agent::agentInfection(){
    if(GameState==Susceptible){
    GameState=Infection;
    timeInfection= new QTimer();
    connect(timeInfection, &QTimer::timeout, this, &Agent::infectionLater);
    timeInfection->start(30000);
    }

}

void Agent::infectionLater(){
    GameState=Removed;
    delete timeInfection;
}

