#include "tia_simulation.h"
#include "ui_tia_simulation.h"


TIA_Simulation::TIA_Simulation(QWidget *parent,QString IP,int NAgents,int SAgents,int SAreaAgents,int CDead,int CInfected,int CTravel,int THealth,int CDetectedInfection,int SQuarantine,bool IDesdly,bool IHealth,bool ISectors,bool IQuarantine)
    : QMainWindow(parent)
    , ui(new Ui::TIA_Simulation)
{
    // Устанавливаем параметры окна приложения
    setWindowTitle("The Infected Agent:Simulation ");
    setAttribute(Qt::WA_DeleteOnClose);
    ResolutionX=1280;
    ResolutionY=720;
    Sectors=1;
    NumberOfAgent=NAgents;
    SizeAgent=SAgents;
    SizeZoneAgent=SAreaAgents;
    IsSectors=ISectors;
    QuarantineStarting=false;
    this->resize(ResolutionX,ResolutionY);
    this->setFixedSize(ResolutionX,ResolutionY);
    socket=new QTcpSocket(this);
    // connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotDontConnected(QAbstractSocket::SocketError)));
     socket->connectToHost(IP,49622);
     while(!socket->waitForConnected(100)){
         QMessageBox msgBox;
         msgBox.setText("Ошибка");
         msgBox.setInformativeText("Не удалось подключиться к сервру. Повторить попытку? ");
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
         msgBox.setIcon(QMessageBox::Warning);
         msgBox.setDefaultButton(QMessageBox::No);
         int res = msgBox.exec();

         if (res == QMessageBox::Yes)
         {
             socket->connectToHost(IP,49622);

         }

        else if (res == QMessageBox::No)
         {
             slotDisc();
             break;
         }
     }
     //if(!socket->isOpen())
     //
     //{
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(slotDisc()));

    if(socket->isOpen()){
        QByteArray NumAgents;
        NumAgents.setNum(NAgents);
        QByteArray ChanOfDead;
        ChanOfDead.setNum(CDead);
        QByteArray ChanOfInfected;
        ChanOfInfected.setNum(CInfected);
        QByteArray ChanOfTravel;
        ChanOfTravel.setNum(CTravel);
        QByteArray ChanOfDetectedInfected;
        ChanOfDetectedInfected.setNum(CDetectedInfection);
        QByteArray StQuarantine;
        StQuarantine.setNum(SQuarantine);
        QByteArray THealh;
        THealh.setNum(THealth);
        QByteArray IsDeadly;
        IsDeadly.setNum(IDesdly);
        QByteArray IsHealth;
        IsHealth.setNum(IHealth);
        QByteArray IsQuarantine;
        IsQuarantine.setNum(IQuarantine);
        QByteArray IsSectors;
        IsSectors.setNum(ISectors);

        QByteArray itog =("{\"type\":\"settings\",\"NumberOfAgents\":"+NumAgents+",\"TimeToHealth\":"+THealh+",\"ChanceOfDead\":"+ChanOfDead+",\"ChanceOfInfected\":"+ChanOfInfected+",\"ChanсeOfDetektedInfektion\":"+ChanOfDetectedInfected+",\"ChanseOfTravel\":"+ChanOfTravel+",\"StartQuarantin\":"+StQuarantine+",\"IsDeadly\":"+IsDeadly+",\"IsHealth\":"+IsHealth+",\"IsQuarantin\":"+IsQuarantine+",\"IsSectors\":"+IsSectors+"}");
        socket->write(itog);
    }
    StartQuarantine=SQuarantine;
    IsQuarantine=IQuarantine;


    ui->setupUi(this);
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, false);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

   // ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
   ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

   scene->setSceneRect(0,0,ResolutionX,ResolutionY);// Устанавливаем размеры графической сцены
//инициализируем чилса заболевшыъ выживших и тд
   NumbersOfHealth=new Score(0,NumberOfAgent);
    NumbersOfHealth->setPos(20,20);
    scene->addItem(NumbersOfHealth);
    NumbersOfHealth->SetColor(1);
    NumbersOfHealth->SetText("Susceptible:");


    NumbersOfInfected=new Score();
    NumbersOfInfected->setPos(20,60);
    scene->addItem(NumbersOfInfected);
    NumbersOfInfected->SetColor(2);
    NumbersOfInfected->SetText("Infection:");


    NumbersOfRemoved=new Score();
    NumbersOfRemoved->setPos(20,100);
    scene->addItem(NumbersOfRemoved);
    NumbersOfRemoved->SetColor(3);
    NumbersOfRemoved->SetText("Removed:");


    NumbersOfDead=new Score();
    NumbersOfDead->setPos(20,140);
    scene->addItem(NumbersOfDead);
    NumbersOfDead->SetColor(4);
    NumbersOfDead->SetText("Dead:");
//только при карантине
if(IQuarantine){
    NumbersOfSecretInfected=new Score();
    NumbersOfSecretInfected->setPos(20,180);
    scene->addItem(NumbersOfSecretInfected);
    NumbersOfSecretInfected->SetColor(5);
    NumbersOfSecretInfected->SetText("Never isolated:");
}

clock=new Clock();
clock->setPos(20,ResolutionY-60);
scene->addItem(clock);

if(ISectors){
   //Верхняя линия
   //------------------------------------------------------------------------------------------------------------------
   scene->addRect((ResolutionX/2)-20,20,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,20,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,20,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,220,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,220,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,220,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)+180,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+400,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+620,20,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   //------------------------------------------------------------------------------------------------------------------

   //Средняя линия
   //------------------------------------------------------------------------------------------------------------------
   scene->addRect((ResolutionX/2)-20,240,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,240,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,240,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,440,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,440,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,440,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)+180,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+400,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+620,240,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   //------------------------------------------------------------------------------------------------------------------

   //Нижняя линия
   //------------------------------------------------------------------------------------------------------------------
   scene->addRect((ResolutionX/2)-20,460,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,460,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,460,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)-20,660,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+200,660,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+420,660,200,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));

   scene->addRect((ResolutionX/2)+180,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+400,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   scene->addRect((ResolutionX/2)+620,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkGray));
   //------------------------------------------------------------------------------------------------------------------
}
else{
  scene->addRect((ResolutionX/2)-20,20,600,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
  scene->addRect((ResolutionX/2)-20,20,1,600,QPen(Qt::NoPen),QBrush(Qt::darkGray));
  scene->addRect((ResolutionX/2)+580,20,1,600,QPen(Qt::NoPen),QBrush(Qt::darkGray));
  scene->addRect((ResolutionX/2)-20,620,600,1,QPen(Qt::NoPen),QBrush(Qt::darkGray));
}
//зона карантина
if(IQuarantine){
scene->addRect((ResolutionX/2)-240,460,200,1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
scene->addRect((ResolutionX/2)-240,660,200,1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
scene->addRect((ResolutionX/2)-240,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkRed));
scene->addRect((ResolutionX/2)-40,460,1,200,QPen(Qt::NoPen),QBrush(Qt::darkRed));

 }
}

void TIA_Simulation::slotDisc(){
    QMessageBox msgBox;
    msgBox.setText("Ошибка!");
    msgBox.setInformativeText("Потеряна связь с сервером. ");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int res = msgBox.exec();

    if (res == QMessageBox::Ok)
    {
        socket->deleteLater();
        QMainWindow::close();

    }

}
void TIA_Simulation::slotReady(){
    Data=socket->readAll();
    qDebug()<<"Data:"<<Data;

    doc = QJsonDocument::fromJson(Data, &docError);

    if(docError.errorString().toInt()==QJsonParseError::NoError){
        if(doc.object().value("type").toString()=="start"){
            NumberClient=doc.object().value("number").toInt();
            NClient.setNum(NumberClient);
        QJsonArray docAr=doc.object().value("result").toArray();
        for(int k=0;k<docAr.count();k++){
            Agent *agent = new Agent(0,SizeAgent,SizeZoneAgent);
            agent->SetSector(docAr[k].toObject().value("sector").toInt());
            agent->setPos(docAr[k].toObject().value("i").toInt(),docAr[k].toObject().value("q").toInt());
            agent->SelectMovePoint(docAr[k].toObject().value("PosI").toInt(),docAr[k].toObject().value("PosQ").toInt());
            scene->addItem(agent);
            agent->AgentRotate();
            agents.append(agent);
         }
        QByteArray itog =("{\"type\":\"AgentInform\",\"number\":"+NClient+",\"result\":[");
        for (int i=0; i<agents.count(); i++){

            Agent *A = dynamic_cast <Agent *> (agents[i]);
            A->slotGameTimer();

            QByteArray AgentTravel;
            AgentTravel.setNum(A->GetTravel());
            QByteArray AgentTravelQuarantine;
            AgentTravelQuarantine.setNum(A->GetTravelQuarantine());
            QByteArray AgentMoveState;
            AgentMoveState.setNum(A->GetMoveState());
            QByteArray AgentStartInfect;
            AgentStartInfect.setNum(A->GetStartInfect());
            QByteArray AgentInform=("{\"Travel\":"+AgentTravel+",\"TravelQuarantine\":"+AgentTravelQuarantine+",\"MoveState\":"+AgentMoveState+",\"StartInfect\":"+AgentStartInfect+"},");
            itog+=AgentInform;

        }
        ui->graphicsView->update();//обновляем сцену
        ui->graphicsView->scene()->update();
        ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        if(socket->isOpen()){
            itog.remove(itog.size()-1,1);
            QByteArray StartQuarantine;
            StartQuarantine.setNum(QuarantineStarting);
            itog+="],\"StartQuarantine\":"+StartQuarantine+"}";
            socket->write(itog);
        }

     }
        else if(doc.object().value("type").toString()=="continue"){
            QJsonArray docAr=doc.object().value("result").toArray();
            QByteArray itog =("{\"type\":\"AgentInform\",\"number\":"+NClient+",\"result\":[");
            for (int i=0; i<agents.count(); i++){

                Agent *A = dynamic_cast <Agent *> (agents[i]);
                if(A->GetStatus()!=docAr[i].toObject().value("status").toInt()){
                    A->SetStatus(docAr[i].toObject().value("status").toInt());


                    if(docAr[i].toObject().value("status").toInt()==1){//добавляем к счету инфицированного и отнимаем здорового
                        NumbersOfInfected->increase(1);
                        NumbersOfInfected->SetText("Infection:");
                        NumbersOfHealth->increase(-1);
                        NumbersOfHealth->SetText("Susceptible:");

                    }
                    if(docAr[i].toObject().value("status").toInt()==2){//добавляем выздоровшего и удаляем заболевшего
                        if(A->GetStatus()==3){
                        NumbersOfSecretInfected->increase(-1);
                        NumbersOfSecretInfected->SetText("Never isolated:");
                        }
                        NumbersOfRemoved->increase(1);
                        NumbersOfRemoved->SetText("Removed:");
                        NumbersOfInfected->increase(-1);
                        NumbersOfInfected->SetText("Infection:");

                    }
                    if(docAr[i].toObject().value("status").toInt()==4){//добавляем мёртвого, удаляем его и отнимаем от заболевшего
                        if(A->GetStatus()==3){
                        NumbersOfSecretInfected->increase(-1);
                        NumbersOfSecretInfected->SetText("Never isolated:");
                        }
                        scene->removeItem(A);
                        agents.removeAt(i);
                        NumbersOfDead->increase(1);
                        NumbersOfDead->SetText("Dead:");
                        NumbersOfInfected->increase(-1);
                        NumbersOfInfected->SetText("Infection:");
                        delete A;
                        continue;

                    }

                    if(docAr[i].toObject().value("status").toInt()==3){//добавляем того, кто не попал под проаерку
                        NumbersOfSecretInfected->increase(1);
                        NumbersOfSecretInfected->SetText("Never isolated:");


                    }
                    if(StartQuarantine<=NumbersOfInfected->GetScore()&&IsQuarantine){//запускаем карантин
                        QuarantineStarting=true;
                    }
                }
                 if(docAr[i].toObject().value("sector").toInt()!=A->GetSector()){
                    A->SetSector(docAr[i].toObject().value("sector").toInt());
                }
                if(!A->GetMoveState()){
                    A->SelectMovePoint(docAr[i].toObject().value("PosI").toInt(),docAr[i].toObject().value("PosQ").toInt());
                    A->SetMoveState();
                    A->AgentRotate();
                    if(A->GetTravelQuarantine()!=docAr[i].toObject().value("TravelQuarantine").toInt()){
                        A->SetTravelQuarantine();
                        //A->SelectMovePoint(docAr[i].toObject().value("PosI").toInt(),docAr[i].toObject().value("PosQ").toInt());
                        //A->AgentRotate();
                    }
                else if(A->GetTravel()!=docAr[i].toObject().value("Travel").toInt()){
                    A->SetTravel();
                    //A->SelectMovePoint(docAr[i].toObject().value("PosI").toInt(),docAr[i].toObject().value("PosQ").toInt());
                    //A->AgentRotate();
                }

                }
                A->slotGameTimer();
                QByteArray AgentTravel;
                AgentTravel.setNum(A->GetTravel());
                QByteArray AgentTravelQuarantine;
                AgentTravelQuarantine.setNum(A->GetTravelQuarantine());
                QByteArray AgentMoveState;
                AgentMoveState.setNum(A->GetMoveState());
                QByteArray AgentStartInfect;
                AgentStartInfect.setNum(A->GetStartInfect());
                QByteArray AgentInform=("{\"Travel\":"+AgentTravel+",\"TravelQuarantine\":"+AgentTravelQuarantine+",\"MoveState\":"+AgentMoveState+",\"StartInfect\":"+AgentStartInfect+"},");
                itog+=AgentInform;
            }

            ui->graphicsView->update();//обновляем сцену
            ui->graphicsView->scene()->update();
            ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
            if(socket->isOpen()){
                itog.remove(itog.size()-1,1);
                QByteArray StartQuarantine;
                StartQuarantine.setNum(QuarantineStarting);
                itog+="],\"StartQuarantine\":"+StartQuarantine+"}";
                socket->write(itog);
                socket->waitForBytesWritten(1000);


        }
   }
 }
}


TIA_Simulation::~TIA_Simulation()
{
    for (int i=0; i<agents.count(); i++){

        Agent *A = dynamic_cast <Agent *> (agents[i]);
        scene->removeItem(A);
        agents.removeAt(i);
        delete A;
    }
    scene->removeItem(NumbersOfDead);
    delete NumbersOfDead;

    scene->removeItem(NumbersOfHealth);
    delete NumbersOfHealth;

    scene->removeItem(NumbersOfRemoved);
    delete NumbersOfRemoved;

    scene->removeItem(NumbersOfInfected);
    delete NumbersOfInfected;
    if(IsQuarantine){
    scene->removeItem(NumbersOfSecretInfected);
            delete NumbersOfSecretInfected;
    }
    delete ui;
    QMainWindow::close();
}

