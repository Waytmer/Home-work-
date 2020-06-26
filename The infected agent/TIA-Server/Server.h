#ifndef SERVER_H
#define SERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QVector>
#include<QList>
#include <ctime>
#include "serveragent.h"

class server:public QTcpServer
{
    Q_OBJECT
public:
    server();
    ~server();

    QTcpSocket* socket;
    QByteArray Data;
    QJsonDocument doc;
    QJsonParseError docError;

    QVector <int> NumberOfAgents;
    QVector <int> ChanceOfDead;
    QVector <int> ChanceOfInfected;
    QVector <int> ChanseOfTravel;
    QVector <int> ChanseOfDetektedInfektion;
    QVector <int> StartQuarantin;
    QVector <int> TimeToHelalth;
    QVector <QList<ServerAgent *>> agentss;
    QList<ServerAgent *> agents;
    QVector <bool> IsDeadly;
    QVector <bool> IsHealth;
    QVector <bool> IsSectors;
    QVector <bool> IsQuarantin;

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisk();

};
#endif // SERVER_H
