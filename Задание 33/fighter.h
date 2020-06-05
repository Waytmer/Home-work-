#ifndef FIGHTER_H
#define FIGHTER_H
#include <random>
#include <cmath>

class Fighter
{
private:
    int health_points;
    int healths;
    int force_points;
    int defence_points;
    int agility_points;
    int critical_points;
    int points;

    double force();
    bool critical();

    double defence();
    bool agility();
public:

    Fighter();
    Fighter(int PHealth,int PForse,int PCritical,int PDefense,int PAgility);
    bool add_health_points(int RPoint);
    bool add_force_points(int RPoint);
    bool add_defence_points(int RPoint);
    bool add_agility_points(int RPoint);
    bool add_critical_points(int RPoint);
    double attack();
    double damage(double dmg);
    bool is_dead();
};

#endif // FIGHTER_H
