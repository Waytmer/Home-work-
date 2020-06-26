#include "clock.h"
#include <QFont>
Clock::Clock(QGraphicsItem* parent):QGraphicsTextItem(parent)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",24));
    second=0;
    minute=0;
    hour=0;
    setPlainText("0"+QString::number(hour)+":0"+QString::number(minute)+":0"+QString::number(second));
    StartingTimes=new QTimer();
    StartingTimes->start(1000);   // Стартуем таймер
    connect(StartingTimes, &QTimer::timeout, this, &Clock::times);
}

void Clock::times(){
    second++;
    if(second==60){
        minute++;
        second=0;
    }
    if(minute==60){
        hour++;
        minute=0;
    }

    if(hour<10&&minute<10&&second<10){
         setPlainText("0"+QString::number(hour)+":0"+QString::number(minute)+":0"+QString::number(second));
    }
    else if(hour<10&&minute<10&&second>=10){
        setPlainText("0"+QString::number(hour)+":0"+QString::number(minute)+":"+QString::number(second));

    }
    else if(hour<10&&minute>=10&&second<10){
        setPlainText("0"+QString::number(hour)+":"+QString::number(minute)+":0"+QString::number(second));

    }
    else if(hour>=10&&minute<10&&second<10){
        setPlainText(QString::number(hour)+":0"+QString::number(minute)+":"+QString::number(second));

    }
    else if(hour<10&&minute>=10&&second>=10){
        setPlainText("0"+QString::number(hour)+":"+QString::number(minute)+":"+QString::number(second));

    }
    else if(hour>=10&&minute<10&&second>=10){
        setPlainText(QString::number(hour)+":0"+QString::number(minute)+":"+QString::number(second));

    }
    else if(hour>=10&&minute>=10&&second<10){
        setPlainText(QString::number(hour)+":"+QString::number(minute)+":0"+QString::number(second));

    }
    else{
            setPlainText(QString::number(hour)+":"+QString::number(minute)+":"+QString::number(second));

    }
}
