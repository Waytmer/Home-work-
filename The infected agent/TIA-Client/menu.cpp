#include "menu.h"
#include "ui_menu.h"


Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
     setWindowTitle("The Infected Agent:Menu");
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    NumberOfAgents=ui->NumberOfAgents->value();
    SizeAgents=ui->SizeAgent->value();
    SizeTheAffectedArea=ui->SizeTheAffectedArea->value();
    ChanceOfDead=ui->ChanceOfDead->value();
    ChanceOfInfected=ui->ChanceOfInfected->value();
    ChanseOfTravel=ui->ChanceOfTravel->value();
    ChanseOfDetektedInfektion=ui->ChanseOfDetektedInfect->value();
    StartQuarantin=ui->StartQuarantine->value();
    TimeToHelalth=ui->TimeToHealth->value();
    IP=ui->IP->text();
    if(ui->IsDeadly->isChecked())
    {
    IsDeadly=true;
    }
    else{
        IsDeadly=false;
    }

    if(ui->IsSectors->isChecked())
    {
    isSectors=true;
    }
    else{
        isSectors=false;
    }

    if(ui->IsHealth->isChecked())
    {
    isHealth=true;
    }
    else{
    isHealth=false;
    }
    if(ui->IsQuarantine->isChecked())
    {
    IsQuarantin=true;
    }
    else{
        IsQuarantin=false;
    }
    show();
    w = new TIA_Simulation(this,IP,NumberOfAgents,SizeAgents,SizeTheAffectedArea,ChanceOfDead,ChanceOfInfected,ChanseOfTravel,TimeToHelalth,ChanseOfDetektedInfektion,StartQuarantin,IsDeadly,isHealth,isSectors,IsQuarantin);
    w->show();
}
