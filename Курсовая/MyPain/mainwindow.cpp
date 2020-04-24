#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Устанавливаем параметры окна приложения
    ResolutionX=600;
    ResolutionY=600;
    Sectors=1;
    this->resize(ResolutionX+10,ResolutionY+20);
    this->setFixedSize(ResolutionX+10,ResolutionY+25);

    ui->setupUi(this);
    scene = new CustomScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    scene->setSceneRect(0,0,ResolutionX,ResolutionY);
                                        // Устанавливаем размеры графической сцены

    //Горизонтальные линии
    //--------------------------------------------------------------------------------------------------------------
    /*scene->addRect(0,10,(ResolutionX/3)-5,1,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(ResolutionX/3,0,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(2*ResolutionX/3,0,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));

    scene->addRect(0,(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(ResolutionX/3,(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(2*ResolutionX/3,(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));

    scene->addRect(0,2*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(ResolutionX/3,2*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(2*ResolutionX/3,2*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));

    scene->addRect(0,3*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(ResolutionX/3,3*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(2*ResolutionX/3,3*(ResolutionY/3)-10,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white));
    //----------------------------------------------------------------------------------------------------------------




    scene->addRect(0,0,10,ResolutionY,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(ResolutionX-10,0,10,ResolutionY,QPen(Qt::NoPen),QBrush(Qt::white));

    scene->addRect(ResolutionX/3,0,10,ResolutionY/3,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect((ResolutionX/3)-15,0,10,ResolutionY/3,QPen(Qt::NoPen),QBrush(Qt::white));
    scene->addRect(2*ResolutionX/3,0,(ResolutionX/3)-5,10,QPen(Qt::NoPen),QBrush(Qt::white))*/;

    for(int k =0;k<100;k++){
        //данная часть кода отвечает за удаление быстрых
//if(k<=20){
//    Agent *agent = new Agent();
//    //connect(this,&MainWindow::myAgentInfection,agent,&Agent::agentInfection);

//    //emit myAgentInfection();
//    agent->setPos(0,0);
//    scene->addItem(agent);
//    agents.append(agent);
//connect(agent, &Agent::signalCheckItem, this, &MainWindow::slotInfection);
//delete agent;
//    }
if(k==21){

        Agent *agent = new Agent();
        //connect(this,&MainWindow::myAgentInfection,agent,&Agent::agentInfection);

        agent->agentInfection();
        agent->setPos(0,0);
        scene->addItem(agent);
        agents.append(agent);
    connect(agent, &Agent::signalCheckItem, this, &MainWindow::slotInfection);
}
else{

Agent *agent = new Agent();


agent->setPos(0,200);
scene->addItem(agent);
agents.append(agent);
connect(this,&MainWindow::myAgentInfection,agent,&Agent::agentInfection);
connect(agent, &Agent::signalCheckItem, this, &MainWindow::slotInfection);}
    }

}






MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotInfection(QGraphicsItem *item) {
 /* Получив сигнал от агента, перебираем список и инфицируем найденное */
 foreach (QGraphicsItem *agent, agents) {
        if (agent == item) {
            Agent *A = qgraphicsitem_cast <Agent *> (item);
            A->agentInfection();
        }
        }
       }
