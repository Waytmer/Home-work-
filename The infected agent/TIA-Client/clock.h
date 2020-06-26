#ifndef CLOCK_H
#define CLOCK_H
#include <QGraphicsTextItem>
#include <QTimer>
class Clock:public QGraphicsTextItem
{
public:
    Clock(QGraphicsItem*parent=0);
    void times();
private:
    QTimer* StartingTimes;
   int second;
   int minute;
   int hour;

};

#endif // CLOCK_H
