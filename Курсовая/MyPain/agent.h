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
    explicit Agent(QObject *parent = 0);
    ~Agent();
    int i=0;
    int q=0;
    enum state{
        Susceptible
       ,Infection
       ,Removed
    };
    state GameState=Susceptible;

signals:
    void signalCheckItem (QGraphicsItem *item);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void SetRotation();
    QPainterPath shape() const;

private:
    QTimer *gameTimer;      // Игровой таймер
    QTimer *timeInfection;
    QPointF target;         // Положение курсора
    //bool state;             // Статус идти/стоять
    QGraphicsItem *hero;

public slots:
    void slotGameTimer();   // Игровой слот
    void agentInfection();
    void infectionLater();
};


#endif // AGENT_H
