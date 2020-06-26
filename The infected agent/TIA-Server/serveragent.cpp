#include "serveragent.h"

ServerAgent::ServerAgent(QObject *parent,int sectorsg,int C_Dead,int C_Infected,int C_Travel,int T_Health,int C_DetektedInfection,bool I_Deadly,bool I_Health,bool I_Sectors):
    QObject(parent)
{
    infectiousness=C_Infected;

    sectors=sectorsg;
    TravelRate=C_Travel;
    Traveling=false;

    ChanceDead=C_Dead;
    ChanceDetektdInfekt=C_DetektedInfection;
    IsDeadly=I_Deadly;
    IsHealth=I_Health;
    IsSectors=I_Sectors;
    TimeHealth=T_Health;
    TravelingQuarantine=false;
    AgentQuarantine=false;
    QuarantineStarting=false;
    GameState=static_cast<state>(0);//все изначально здоровы
}

void ServerAgent::SelectMovePoint(){//выбераем куда двигаться
    if(TravelingQuarantine||AgentQuarantine){//если мы в карантине или движемся туд
        i=400+rand()%200;
        q=460+rand()%200;
    }
    else if(IsSectors){//если мы в режиме страны
    switch (sectors) {
    //Верхние сектора
    //----------------------------------------------------------------------
    case(1):
        i=620+rand()%200;
        q=20+rand()%200;
        break;

    case(2):
        i=840+rand()%200;
        q=20+rand()%200;
        break;


    case(3):
        i=1060+rand()%200;
        q=20+rand()%200;
        break;
     //----------------------------------------------------------------------

     //Средние сектора
     //----------------------------------------------------------------------
     case(4):
         i=620+rand()%200;
         q=240+rand()%200;
         break;

     case(5):
         i=840+rand()%200;
         q=240+rand()%200;
         break;


      case(6):
         i=1060+rand()%200;
         q=240+rand()%200;
         break;
      //----------------------------------------------------------------------


      //Нижние сектора
      //----------------------------------------------------------------------
     case(7):
         i=620+rand()%200;
         q=460+rand()%200;
         break;

     case(8):
         i=840+rand()%200;
         q=460+rand()%200;
         break;


     case(9):
         i=1060+rand()%200;
         q=460+rand()%200;
         break;
     //----------------------------------------------------------------------
   }
    }
    else{//если мы в одном большом секторе
       i=620+rand()%600;
       q=20+rand()%600;
    }
}

void ServerAgent::agentInfection(bool infectionInitialize){//заражениие агента

    if(((GameState==Susceptible)&&((rand()%(101-infectiousness))==0))||infectionInitialize){//если агент неболен или это 1 зараженный агент
    GameState=Infection;//меняем состояние

    if(IsHealth||IsDeadly){//если мы можемм вылечиться или умереть
    timeInfection= new QTimer();//запускаем время инфекции
    connect(timeInfection, &QTimer::timeout, this, &ServerAgent::infectionLater);
    timeInfection->start(TimeHealth*1000);}
    }

}
void ServerAgent::infectionLater(){//после истечения времени
    if(rand()%(101-ChanceDead)==0){//если неповезло и умерли
    GameState=Dead;}
    else if(IsHealth){//если излечились
    GameState=Removed;
    }
    delete timeInfection;
}

void ServerAgent::slotGameTimer()
{
    if(GameState==Infection&&QuarantineStarting&&TravelingQuarantine==false&&AgentQuarantine==false){//проверка во время карантина агента и дальнейшее решение его судьбы(В карантин или нет)
        if(rand()%(101-ChanceDetektdInfekt)==0){
            TravelingQuarantine=true;
            AgentQuarantine=true;//агент направляеться в карантин


        }
        else{
            GameState=DontDetektInfection;//агента не заметили


        }
    }
    if(rand()%101-TravelRate==0&&TravelingQuarantine==false&&Traveling==false){//шанс на то, что агент переместится в другой сектор
        Traveling=true;//агент путешевствует
        sectors=1+rand()%9;//выбор одного из 9 секторов


    }


    }





int ServerAgent::GetI(){
    return i;
}

int ServerAgent::GetQ(){
    return q;
}

int ServerAgent::GetStatus(){
    return GameState;
}
int ServerAgent::GetSector(){
    return sectors;
}

bool ServerAgent::GetTraveling(){
    return Traveling;
}

bool ServerAgent::GetTravelingQuarantine(){
    return TravelingQuarantine;
}

bool ServerAgent::GetQuarantineStarting(){
    return QuarantineStarting;
}

void ServerAgent::SetTraveling(){
    Traveling=false;
}

void ServerAgent::SetTravelingQuarantine(){
    TravelingQuarantine=false;
}

void ServerAgent::SetQuarantineStarting(){
    QuarantineStarting=true;
}
