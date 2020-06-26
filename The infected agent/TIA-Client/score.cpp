#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem* parent,int ScoupeScene):QGraphicsTextItem(parent)
{
score=ScoupeScene;
setPlainText(("Score:")+QString::number(score));
setDefaultTextColor(Qt::blue);
setFont(QFont("times",16));
}

void Score::increase(int GScore){
    score+=GScore;
}

void Score::SetColor(int colorID){
    switch (colorID) {
    case(1):
        setDefaultTextColor(Qt::green);
        break;


    case(2):
        setDefaultTextColor(Qt::red);
        break;

    case(3):
        setDefaultTextColor(Qt::darkGray);
        break;


    case(4):
        setDefaultTextColor(Qt::white);
        break;
    case(5):
        setDefaultTextColor(Qt::cyan);
        break;
    }
    }

void Score::SetText(QString name){
    setPlainText(name+QString::number(score));
}

int Score::GetScore(){
    return score;
}
