#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H


#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomScene(QObject *parent = 0);
    ~CustomScene();
};

#endif // CUSTOMSCENE_H
