#include "fighter.h"


Fighter::Fighter()
{ 
    healths=100;
    health_points=0;
    force_points=0;
    defence_points=0;
    agility_points=0;
    critical_points=0;
    points=10;

}

Fighter::Fighter(int PHealth,int PForse,int PCritical,int PDefense,int PAgility){

    health_points=PHealth;
    force_points=PForse;
    defence_points=PDefense;
    agility_points=PAgility;
    critical_points=PCritical;
    healths=100+health_points*100;
    points=0;
}

bool Fighter::add_health_points(int RPoint){
      //int RPoint=rand()%11;
      if(RPoint>points){
          healths=100+health_points*100;
          return false;
      }
      else{
          health_points+=RPoint;
          points-=RPoint;
          return true;
      }
}

bool Fighter::add_force_points(int RPoint){
      //int RPoint=rand()%11;
      if(RPoint>points){
          return false;
      }
      else{
          force_points+=RPoint;
          points-=RPoint;
          return true;
      }
}

bool Fighter::add_defence_points(int RPoint){
      //int RPoint=rand()%11;
      if(RPoint>points){
          return false;
      }
      else{
          defence_points+=RPoint;
          points-=RPoint;
          return true;
      }
}

bool Fighter::add_agility_points(int RPoint){
     // int RPoint=rand()%11;
      if(RPoint>points){
          return false;
      }
      else{
          agility_points+=RPoint;
          points-=RPoint;
          return true;
      }
}

bool Fighter::add_critical_points(int RPoint){
     // int RPoint=rand()%11;
      if(RPoint>points){
          return false;
      }
      else{
          critical_points+=RPoint;
          points-=RPoint;
          return true;
      }
}

double Fighter::force(){
    return 1+force_points;
}

bool Fighter::critical(){
    double RNumber=rand()/static_cast<double>(RAND_MAX);
    double CriticalChance=1 / ( 1+pow( critical_points / 4.0, 4) );
    if(RNumber>CriticalChance){
        return true;
    }
    else{
        return false;
    }
}

double Fighter::attack(){
    return force()*(1+critical());
}

double Fighter::defence(){
    return  1+pow( defence_points / 4.0, 4);
}

bool Fighter::agility(){
    double RNumber=rand()/static_cast<double>(RAND_MAX);
    double CriticalChance=1 / ( 1+pow( agility_points / 4.0, 4) );
    if(RNumber>CriticalChance){
        return true;
    }
    else{
        return false;
    }
}

double Fighter::damage(double dmg){
   healths-=(1-agility())*defence()*dmg;
   return (1-agility())*defence()*dmg;
}

bool Fighter::is_dead(){
    if(healths<=0){
        return true;
    }
    else{
        return false;
    }
}

