#include "Server.h"
server::server(){}

server::~server(){}

void server::startServer(){
    if(this->listen(QHostAddress::Any,49622)){
        qDebug()<<"Listening";
    }
    else{
        qDebug()<<"Not listening!";
    }
}

void server::incomingConnection(qintptr socketDescriptor){
    socket=new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisk()));

    qDebug()<<"Client connected";

}

void server::sockReady(){

    Data=socket->readAll();
    qDebug()<<"Data:"<<Data;

    doc = QJsonDocument::fromJson(Data, &docError);

    if(docError.errorString().toInt()==QJsonParseError::NoError){
        if(doc.object().value("type").toString()=="settings"){
            NumberOfAgents.push_back(doc.object().value("NumberOfAgents").toInt());
            ChanceOfDead.push_back(doc.object().value("ChanceOfDead").toInt());
            ChanceOfInfected.push_back(doc.object().value("ChanceOfInfected").toInt());
            ChanseOfDetektedInfektion.push_back(doc.object().value("ChanсeOfDetektedInfektion").toInt());
            ChanseOfTravel.push_back(doc.object().value("ChanсeOfTravel").toInt());
            StartQuarantin.push_back(0);
            TimeToHelalth.push_back(doc.object().value("TimeToHealth").toInt());
            IsDeadly.push_back(doc.object().value("IsDeadly").toInt());
            IsHealth.push_back(doc.object().value("IsHealth").toInt());
            IsQuarantin.push_back(doc.object().value("IsQuarantin").toInt());
            IsSectors.push_back(doc.object().value("IsSectors").toInt());
            agentss.push_back(agents);

             int NumberClient=NumberOfAgents.size()-1;
            int IncludeInfected=rand()%NumberOfAgents[NumberClient];//инфицированный
                for(int k =0;k<NumberOfAgents[NumberClient];k++){
                    if(IsSectors[NumberClient]){
                        //распределяем агентов по секторам
            if(k<NumberOfAgents[NumberClient]/9){

                    ServerAgent *agent = new ServerAgent(0,1,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                    agent->SelectMovePoint();
                    if(k==IncludeInfected){
                     agent->agentInfection(true);
                    }
                    agentss[NumberClient].append(agent);

            }
            else if((k>=NumberOfAgents[NumberClient]/9)&&(k<2*NumberOfAgents[NumberClient]/9)) {

                ServerAgent *agent = new ServerAgent(0,2,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }

            else if((k>=2*NumberOfAgents[NumberClient]/9)&&(k<3*NumberOfAgents[NumberClient]/9)) {

                ServerAgent *agent = new ServerAgent(0,3,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }


            else if((k>=3*NumberOfAgents[NumberClient]/9)&&(k<4*NumberOfAgents[NumberClient]/9)){

                ServerAgent *agent = new ServerAgent(0,4,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);

            }
            else if((k>=4*NumberOfAgents[NumberClient]/9)&&(k<5*NumberOfAgents[NumberClient]/9)) {

                ServerAgent *agent = new ServerAgent(0,5,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }

            else if((k>=5*NumberOfAgents[NumberClient]/9)&&(k<6*NumberOfAgents[NumberClient]/9)) {

                ServerAgent *agent = new ServerAgent(0,6,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }

            else if((k>=6*NumberOfAgents[NumberClient]/9)&&(k<7*NumberOfAgents[NumberClient]/9)){

                ServerAgent *agent = new ServerAgent(0,7,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);

            }
            else if((k>=7*NumberOfAgents[NumberClient]/9)&&(k<8*NumberOfAgents[NumberClient]/9)) {

                ServerAgent *agent = new ServerAgent(0,8,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }

            else if((k>=8*NumberOfAgents[NumberClient]/9)&&(k<=NumberOfAgents[NumberClient])) {

                ServerAgent *agent = new ServerAgent(0,9,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                agent->SelectMovePoint();
                if(k==IncludeInfected){
                 agent->agentInfection(true);
                }
                agentss[NumberClient].append(agent);


            }
                    }
                    else{//если режим секторов не включен
                        ServerAgent *agent = new ServerAgent(0,0,ChanceOfDead[NumberClient], ChanceOfInfected[NumberClient], ChanseOfTravel[NumberClient], TimeToHelalth[NumberClient],ChanseOfDetektedInfektion[NumberClient], IsDeadly[NumberClient], IsHealth[NumberClient], IsSectors[NumberClient]);
                        agent->SelectMovePoint();
                        if(k==IncludeInfected){
                         agent->agentInfection(true);
                        }
                        agentss[NumberClient].append(agent);
                    }
                }

                if(socket->isOpen()){
                    QByteArray NClient;
                    NClient.setNum(NumberClient);
                    QByteArray itog =("{\"type\":\"start\",\"number\":"+NClient+",\"result\":[");
                    for (int i=0; i<agentss[NumberClient].count(); i++){
                    ServerAgent *A = dynamic_cast <ServerAgent *> (agentss[NumberClient][i]);
                    QByteArray AgentI;
                    AgentI.setNum(A->GetI());
                    QByteArray AgentSector;
                    AgentSector.setNum(A->GetSector());
                    QByteArray AgentQ;
                    AgentQ.setNum(A->GetQ());
                    QByteArray AgentIPos;
                    AgentIPos.setNum(A->GetI());
                    QByteArray AgentQPos;
                    AgentQPos.setNum(A->GetQ());

                    QByteArray AgentStatus;
                    AgentStatus.setNum(A->GetStatus());
                    QByteArray AgentInform=("{\"status\":"+AgentStatus+",\"i\":"+AgentI+",\"q\":"+AgentQ+",\"PosI\":"+AgentIPos+",\"PosQ\":"+AgentQPos+",\"sector\":"+AgentSector+"},");
                    itog+=AgentInform;

            }
                    itog.remove(itog.size()-1,1);
                    itog+="]}";
                    socket->write(itog);
                   // socket->waitForBytesWritten(500);

               }


        }
        else if(doc.object().value("type").toString()=="AgentInform"){
            int NumberClient=doc.object().value("number").toInt();

            if(StartQuarantin[NumberClient]!=doc.object().value("StartQuarantine").toInt()){
              StartQuarantin[NumberClient]=1;
            }
            QByteArray itog =("{\"type\":\"continue\",\"result\":[");
                       QJsonArray docAr=doc.object().value("result").toArray();
            for(int i=0; i<agentss[NumberClient].count(); i++){
                ServerAgent *A = dynamic_cast <ServerAgent *> (agentss[NumberClient][i]);
                if(!docAr[i].toObject().value("Travel").toInt()&&A->GetTraveling()){
                    A->SetTraveling();
                }
                if(!docAr[i].toObject().value("TravelQuarantine").toInt()&&A->GetTravelingQuarantine()){
                    A->SetTravelingQuarantine();
                }
                if(docAr[i].toObject().value("StartInfect").toInt()){
                    A->agentInfection(0);
                }
                if(A->GetQuarantineStarting()!=StartQuarantin[NumberClient]){
                    A->SetQuarantineStarting();
                }
                A->slotGameTimer();

                QByteArray AgentIPos;
                AgentIPos.setNum(A->GetI());
                QByteArray AgentSector;
                AgentSector.setNum(A->GetSector());
                QByteArray AgentQPos;
                AgentQPos.setNum(A->GetQ());
                QByteArray AgentTravel;
                QByteArray AgentTravelQuarantine;
                QByteArray AgentStatus;
                AgentStatus.setNum(A->GetStatus());
                if(!docAr[i].toObject().value("Travel").toInt()&&A->GetTraveling()){
                    AgentTravel.setNum(1);
                }
                else{
                    AgentTravel.setNum(0);
                }
                if(!docAr[i].toObject().value("TravelQuarantine").toInt()&&A->GetTravelingQuarantine()){
                    AgentTravelQuarantine.setNum(1);
                }
                else{
                    AgentTravelQuarantine.setNum(0);
                }
                if(!docAr[i].toObject().value("MoveState").toInt()){
                    A->SelectMovePoint();
                    AgentIPos.setNum(A->GetI());
                    AgentQPos.setNum(A->GetQ());
                }

                    QByteArray AgentInform=("{\"status\":"+AgentStatus+",\"PosI\":"+AgentIPos+",\"PosQ\":"+AgentQPos+",\"Travel\":"+AgentTravel+",\"TravelQuarantine\":"+AgentTravelQuarantine+",\"sector\":"+AgentSector+"},");
                    itog+=AgentInform;

                    if(A->GetStatus()==4){
                    agentss[NumberClient].removeAt(i);
                    delete A;
                    continue;
                    }

            }
            itog.remove(itog.size()-1,1);
            itog+="]}";
            socket->write(itog);
            socket->waitForBytesWritten(500);

        }




        }

    }




void server::sockDisk(){
    qDebug()<<"Disconect";
    socket->deleteLater();
}
