#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem*parent=0,int SroupeScene=0);
    void increase(int GScore);
    int getScore();
    void SetColor(int colorID);
    void SetText(QString name);
    int GetScore();
private:
    int score;
};

#endif // SCORE_H
