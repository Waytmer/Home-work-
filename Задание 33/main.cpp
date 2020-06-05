#include <QCoreApplication>
#include <ctime>
#include<fighter.h>
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand( time( 0 ) );
    int game_mode;

    cout<<"Select a game mode:\n  1.Bot vs Bot\n  2.Bot vs Player\n  3.Player vs Player\nSelect mode:";
    cin>>game_mode;
    cout<<endl;
    switch (game_mode) {
    case 1:
    {
        Fighter Bot1;
        Fighter Bot2;
        bool Select1=true;
        while(Select1){
            int RCharacteristic=1+rand()%5;
            switch (RCharacteristic) {
            case 1:
                if(!Bot1.add_health_points(1)){
                    Select1=false;
                }
                break;
            case 2:
                if(!Bot1.add_force_points(1)){
                    Select1=false;
                }
                break;
            case 3:
                if(!Bot1.add_critical_points(1)){
                    Select1=false;
                }
                break;
            case 4:
                if(!Bot1.add_defence_points(1)){
                    Select1=false;
                }
                break;
            case 5:
                if(!Bot1.add_agility_points(1)){
                    Select1=false;
                }
                break;
            }
        }
        bool Select2=true;
        while(Select2){
            int RCharacteristic=1+rand()%5;
            switch (RCharacteristic) {
            case 1:
                if(!Bot2.add_health_points(1)){
                    Select2=false;
                }
                break;
            case 2:
                if(!Bot2.add_force_points(1)){
                    Select2=false;
                }
                break;
            case 3:
                if(!Bot2.add_critical_points(1)){
                    Select2=false;
                }
                break;
            case 4:
                if(!Bot2.add_defence_points(1)){
                    Select2=false;
                }
                break;
            case 5:
                if(!Bot2.add_agility_points(1)){
                    Select2=false;
                }
                break;
            }
        }


        bool firstAtack = true;
            while ( (!Bot1.is_dead()) && (!Bot2.is_dead()) )
            {
                if (firstAtack)
                {
                    double hit = Bot2.damage(Bot1.attack());

                    cout <<"Bot2 received damage of " << hit << " untits\n";
                }
                else
                {
                    double hit = Bot1.damage(Bot2.attack());

                    cout << "Bot1 received damage of " << hit << " untits\n";
                }

                firstAtack = !firstAtack;
            }

            if ( Bot1.is_dead() )
                cout << "\nBot2";
            else
                cout << "\nBot1";

            cout << " winer!\n";
        break;
        }
    case 2:
        {

        cout<<"Player,input Health point,Forse point,Critical point, Defense point,Agility point:";
        int PHealth;
        int PForse;
        int PCritical;
        int PDefense;
        int PAgility;
        cin>>PHealth>>PForse>>PCritical>>PDefense>>PAgility;
        cout<<endl;
        Fighter Player1(PHealth,PForse,PCritical,PDefense,PAgility);

        Fighter Bot1;
        bool Select1=true;
        while(Select1){
            int RCharacteristic=1+rand()%5;
            switch (RCharacteristic) {
            case 1:
                if(!Bot1.add_health_points(1)){
                    Select1=false;
                }
                break;
            case 2:
                if(!Bot1.add_force_points(1)){
                    Select1=false;
                }
                break;
            case 3:
                if(!Bot1.add_critical_points(1)){
                    Select1=false;
                }
                break;
            case 4:
                if(!Bot1.add_defence_points(1)){
                    Select1=false;
                }
                break;
            case 5:
                if(!Bot1.add_agility_points(1)){
                    Select1=false;
                }
                break;
            }
        }
            bool firstAtack = true;
                while ( (!Bot1.is_dead()) && (!Player1.is_dead()) )
                {
                    if (firstAtack)
                    {
                        double hit = Player1.damage(Bot1.attack());

                        cout <<"Player received damage of" << hit << "  untits\n";
                    }
                    else
                    {
                        double hit = Bot1.damage(Player1.attack());

                        cout << "Bot received damage of" << hit << "  untits\n";
                    }

                    firstAtack = !firstAtack;
                }

                if ( Bot1.is_dead() )
                    cout << "\nPlayer";
                else
                    cout << "\nBot";

                cout << " winer!\n";

        break;
        }
    case 3:
        {
        int PHealth;
        int PForse;
        int PCritical;
        int PDefense;
        int PAgility;
        cout<<"Player1,input Health point,Forse point,Critical point, Defense point,Agility point:";
        cin>>PHealth>>PForse>>PCritical>>PDefense>>PAgility;
        Fighter Player1(PHealth,PForse,PCritical,PDefense,PAgility);

        cout<<"Player2,input Health point,Forse point,Critical point, Defense point,Agility point:";
        cin>>PHealth>>PForse>>PCritical>>PDefense>>PAgility;
        Fighter Player2(PHealth,PForse,PCritical,PDefense,PAgility);

        cout<<endl;

        bool firstAtack = true;
            while ( (!Player1.is_dead()) && (!Player2.is_dead()) )
            {
                if (firstAtack)
                {
                    double hit = Player2.damage(Player1.attack());

                    cout <<"Player2 received damage of " << hit << " untits\n";
                }
                else
                {
                    double hit = Player1.damage(Player2.attack());

                    cout << "Player1 received damage of " << hit << " untits\n";
                }

                firstAtack = !firstAtack;
            }

            if ( Player1.is_dead() )
                cout << "\nPlayer2";
            else
                cout << "\nPlayer1";

            cout << " winer!\n";
        break;
        }
    default:
        {
        break;
        }


}

    return a.exec();
}

