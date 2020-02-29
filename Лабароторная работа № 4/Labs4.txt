МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 4<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы 192(2)  
<br/>Лунгула Кирилла Александровича  
<br/>направления подготовки 09.03.03 "Программная инженерия" 

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель

* Закрепить навыки работы с перечислениями;
* Закрепить навыки работы с структурами;
* Освоить методы составления многофайловых программ.

#### Ход работы

1. Вспомогательный файл
    ```cpp
    #include <iostream>
#include <ctime>
#include "helpfile.h"
using namespace std;
namespace game{

const int S_bord=3;

Game initGame(char userChar){
    Game rule;
    for(int i=0;i<=S_bord-1;i++){
        for(int k=0;k<=S_bord-1;k++){
         rule.bord[i][k]=' ';
        }
    }
    srand( time( 0 ) );
    rule.isUserTurn=rand()%2;
    rule.userChar=userChar;
    if(userChar=='x')rule.botChar='0';
    else rule.botChar='x';
return rule;
}
void updateDisplay(const Game game){
    system("cls");
    cout<<" 0  1  2 \n"
        <<"---------- \n ";
    for (int i = 0; i < S_bord; i++) {
                for (int j = 0; j < S_bord; j++) {
                    std::cout << game.bord[i][j] << "|  ";
                }
                std::cout << i << std::endl << "----------" << std::endl<<" ";
            }
        }

void botTurn(Game* game){
    int Q_spases=0,Q_user=0,Q_diagonal_rB=0,Q_diagonal_lB=0,Q_diagonal_rU=0,Q_diagonal_lU=0,
        Q_gorizontal1_B=0,Q_gorizontal2_B=0,Q_gorizontal3_B=0,Q_gorizontal1_U=0,Q_gorizontal2_U=0,
        Q_gorizontal3_U=0,Q_vertical1_B=0,Q_vertical2_B=0,Q_vertical3_B=0,Q_vertical1_U=0,Q_vertical2_U=0,
        Q_vertical3_U=0;
    for(int i=0;i<=S_bord-1;i++){
        for(int k=0;k<=S_bord-1;k++){
            if(game->bord[i][k]==' ')Q_spases++;
            if(game->bord[i][k]==game->userChar)Q_user++;



        }
        if(game->bord[0][i]==game->userChar)Q_gorizontal1_U++;//Проверка всех горизонталей на кол-во в каждой символов пользователя
        if(game->bord[1][i]==game->userChar)Q_gorizontal2_U++;
        if(game->bord[2][i]==game->userChar)Q_gorizontal3_U++;

        if(game->bord[0][i]==game->botChar)Q_gorizontal1_B++;//Проверка всех горизонталей на кол-во в каждой символов бота
        if(game->bord[1][i]==game->botChar)Q_gorizontal2_B++;
        if(game->bord[2][i]==game->botChar)Q_gorizontal3_B++;

        if(game->bord[i][0]==game->userChar)Q_vertical1_U++;//Проверка всех вертикалей на кол-во в каждой символов пользователя
        if(game->bord[i][1]==game->userChar)Q_vertical2_U++;
        if(game->bord[i][2]==game->userChar)Q_vertical3_U++;

        if(game->bord[i][0]==game->botChar)Q_vertical1_B++;//Проверка всех вертикалей на кол-во в каждой символов бота
        if(game->bord[i][1]==game->botChar)Q_vertical2_B++;
        if(game->bord[i][2]==game->botChar)Q_vertical3_B++;

        if(game->bord[i][i]==game->userChar)Q_diagonal_lU++;//Проверка диагоналей на кол-во символов пользователя


        if(game->bord[i][i]==game->botChar)Q_diagonal_lB++;//Проверка диагоналей на кол-во символов бота
    }
    if(game->bord[2][0]==game->userChar)Q_diagonal_rU++;
    if(game->bord[1][1]==game->userChar)Q_diagonal_rU++;
    if(game->bord[0][2]==game->userChar)Q_diagonal_rU++;

    if(game->bord[2][0]==game->botChar)Q_diagonal_rB++;
    if(game->bord[1][1]==game->botChar)Q_diagonal_rB++;
    if(game->bord[0][2]==game->botChar)Q_diagonal_rB++;


    if(Q_spases==S_bord*S_bord){
        srand( time( 0 ) );
        int x = rand()%S_bord;
        //srand( time( 0 ) );
        int y = rand()%S_bord;
        game->bord[x][y] = game->botChar;
    }
    else if(Q_user==1){//Q_diagonal_lU==1||Q_diagonal_rU==1||Q_gorizontal1_U==1||Q_gorizontal2_U==1||Q_gorizontal3_U==1||Q_vertical1_U==1||Q_vertical2_U==Q_vertical3_U==1
        while(true){
        srand( time( 0 ) );
        int x = rand()%S_bord;
        //srand( time( 0 ) );
        int y = rand()%S_bord;
        if(game->bord[x][y]==' '){
        game->bord[x][y] = game->botChar;
        break;}
        }
    }
        //Ход при главенствовании на поле бота***************************************
    else if(Q_diagonal_lB==2&&Q_diagonal_lU==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[i][i]==' '){
                game->bord[i][i]=game->botChar;
                break;
            }
        }
    }
     else if(Q_diagonal_rB==2&&Q_diagonal_rU==0){
        if(game->bord[2][0]==' ')game->bord[2][0]=game->botChar;
        else if(game->bord[1][1]==' ')game->bord[1][1]=game->botChar;
        else if(game->bord[0][2]==' ')game->bord[0][2]=game->botChar;
    }
     else if(Q_gorizontal1_B==2&&Q_gorizontal1_U==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[0][i]==' '){
                game->bord[0][i]=game->botChar;
                break;
            }

        }
    }
        else if(Q_gorizontal2_B==2&&Q_gorizontal2_U==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[1][i]==' '){
                game->bord[1][i]=game->botChar;
                break;
            }

        }
        }
    else if(Q_gorizontal3_B==2&&Q_gorizontal3_U==0){
    for(int i=0;i<=S_bord-1;i++){
        if(game->bord[2][i]==' '){
            game->bord[2][i]=game->botChar;
            break;
        }

    }
    }
     else if(Q_vertical1_B==2&&Q_vertical1_U==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[i][0]==' '){
                game->bord[i][0]=game->botChar;
                break;
            }

        }
    }
      else if(Q_vertical2_B==2&&Q_vertical2_U==0){
           for(int i=0;i<=S_bord-1;i++){
               if(game->bord[i][1]==' '){
                   game->bord[i][1]=game->botChar;
                   break;
               }

           }
        }
      else if(Q_vertical3_B==2&&Q_vertical3_U==0){
              for(int i=0;i<=S_bord-1;i++){
                  if(game->bord[i][2]==' '){
                      game->bord[i][2]=game->botChar;
                      break;
                  }

              }

    }//Ход при главенствовании на линии игрока******************************************************
    else if(Q_diagonal_lU==2&&Q_diagonal_lB==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[i][i]==' '){
                game->bord[i][i]=game->botChar;
                break;
            }
        }
    }
     else if(Q_diagonal_rU==2&&Q_diagonal_rB==0){
        if(game->bord[2][0]==' ')game->bord[2][0]=game->botChar;
        else if(game->bord[1][1]==' ')game->bord[1][1]=game->botChar;
        else if(game->bord[0][2]==' ')game->bord[0][2]=game->botChar;
    }
     else if(Q_gorizontal1_U==2&&Q_gorizontal1_B==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[0][i]==' '){
                game->bord[0][i]=game->botChar;
                break;
            }

        }
    }
        else if(Q_gorizontal2_U==2&&Q_gorizontal2_B==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[1][i]==' '){
                game->bord[1][i]=game->botChar;
                break;
            }

        }
        }
    else if(Q_gorizontal3_U==2&&Q_gorizontal3_B==0){
    for(int i=0;i<=S_bord-1;i++){
        if(game->bord[2][i]==' '){
            game->bord[2][i]=game->botChar;
            break;
        }

    }
    }
     else if(Q_vertical1_U==2&&Q_vertical1_B==0){
        for(int i=0;i<=S_bord-1;i++){
            if(game->bord[i][0]==' '){
                game->bord[i][0]=game->botChar;
                break;
            }

        }
    }
      else if(Q_vertical2_U==2&&Q_vertical2_B==0){
           for(int i=0;i<=S_bord-1;i++){
               if(game->bord[i][1]==' '){
                   game->bord[i][1]=game->botChar;
                   break;
               }

           }
        }
      else if(Q_vertical3_U==2&&Q_vertical3_B==0){
              for(int i=0;i<=S_bord-1;i++){
                  if(game->bord[i][2]==' '){
                      game->bord[i][2]=game->botChar;
                      break;
                  }

              }
        }


      else{
        int q=0;
            while(true){
            q++;
            srand( time( 0 ) );
            int x = rand()%S_bord;
            //srand( time( 0 ) );
            int y = rand()%S_bord;
            if(game->bord[x][y]==' '){
            game->bord[x][y] = game->botChar;
            break;}
            else if(q==9){
                for(int i=0;i<=S_bord-1;i++){
                    for(int k=0;k<=S_bord-1;k++){
                        if(game->bord[i][k]==' ')game->bord[i][k]=game->botChar;
                    }
                }
            }
}
    }
}

void userTurn(Game* game){
    int x_user,y_user;
    cout<<"Veddite koordinati(x y):";
    while(true){
    cin>>x_user>>y_user;
    if(game->bord[y_user][x_user]==' ' && x_user>=0 && x_user<=S_bord&&y_user>=0 &&y_user<=S_bord){
      game->bord[y_user][x_user]=game->userChar;
      break;
    }
    else{
        cout<<"FFFFFALL koordinats, press restart:\n";
    }
    }

}

bool updateGame(Game* game){
int Q_spases=0,Q_user=0,Q_diagonal_rB=0,Q_diagonal_lB=0,Q_diagonal_rU=0,Q_diagonal_lU=0,
    Q_gorizontal1_B=0,Q_gorizontal2_B=0,Q_gorizontal3_B=0,Q_gorizontal1_U=0,Q_gorizontal2_U=0,
    Q_gorizontal3_U=0,Q_vertical1_B=0,Q_vertical2_B=0,Q_vertical3_B=0,Q_vertical1_U=0,Q_vertical2_U=0,
    Q_vertical3_U=0;
for(int i=0;i<=S_bord-1;i++){
    for(int k=0;k<=S_bord-1;k++){
        if(game->bord[i][k]==' ')Q_spases++;
        if(game->bord[i][k]==game->userChar)Q_user++;
    }
    if(game->bord[0][i]==game->userChar)Q_gorizontal1_U++;//Проверка всех горизонталей на кол-во в каждой символов пользователя
    if(game->bord[1][i]==game->userChar)Q_gorizontal2_U++;
    if(game->bord[2][i]==game->userChar)Q_gorizontal3_U++;

    if(game->bord[0][i]==game->botChar)Q_gorizontal1_B++;//Проверка всех горизонталей на кол-во в каждой символов бота
    if(game->bord[1][i]==game->botChar)Q_gorizontal2_B++;
    if(game->bord[2][i]==game->botChar)Q_gorizontal3_B++;

    if(game->bord[i][0]==game->userChar)Q_vertical1_U++;//Проверка всех вертикалей на кол-во в каждой символов пользователя
    if(game->bord[i][1]==game->userChar)Q_vertical2_U++;
    if(game->bord[i][2]==game->userChar)Q_vertical3_U++;

    if(game->bord[i][0]==game->botChar)Q_vertical1_B++;//Проверка всех вертикалей на кол-во в каждой символов бота
    if(game->bord[i][1]==game->botChar)Q_vertical2_B++;
    if(game->bord[i][2]==game->botChar)Q_vertical3_B++;

    if(game->bord[i][i]==game->userChar)Q_diagonal_lU++;//Проверка диагоналей на кол-во символов пользователя


    if(game->bord[i][i]==game->botChar)Q_diagonal_lB++;//Проверка диагоналей на кол-во символов бота

}
if(game->bord[2][0]==game->userChar)Q_diagonal_rU++;
if(game->bord[1][1]==game->userChar)Q_diagonal_rU++;
if(game->bord[0][2]==game->userChar)Q_diagonal_rU++;

if(game->bord[2][0]==game->botChar)Q_diagonal_rB++;
if(game->bord[1][1]==game->botChar)Q_diagonal_rB++;
if(game->bord[0][2]==game->botChar)Q_diagonal_rB++;

if(Q_diagonal_lB==3)game->status=BOT_WIN;
else if(Q_diagonal_rB==3)game->status=BOT_WIN;
else if(Q_gorizontal1_B==3)game->status=BOT_WIN;
else if(Q_gorizontal2_B==3)game->status=BOT_WIN;
else if(Q_gorizontal3_B==3)game->status=BOT_WIN;
else if(Q_vertical1_B==3)game->status=BOT_WIN;
else if(Q_vertical2_B==3)game->status=BOT_WIN;
else if(Q_vertical3_B==3)game->status=BOT_WIN;

else if(Q_diagonal_lU==3)game->status=USER_WIN;
else if(Q_diagonal_rU==3)game->status=USER_WIN;
else if(Q_gorizontal1_U==3)game->status=USER_WIN;
else if(Q_gorizontal2_U==3)game->status=USER_WIN;
else if(Q_gorizontal3_U==3)game->status=USER_WIN;
else if(Q_vertical1_U==3)game->status=USER_WIN;
else if(Q_vertical2_U==3)game->status=USER_WIN;
else if(Q_vertical3_U==3)game->status=USER_WIN;

else if(Q_spases==0)game->status=NOT_WIN;
else game->status=PLAY;
if(game->status==PLAY){
    return false;
}
else return true;
}
}
    ```
2. Файл реализующий игру 
    ```CPP
   #include <iostream>
#include <ctime>
#include "helpfile.h"
using namespace std;
int main()
{
cout<<"Vvedite simvol cotorim hotite igrat(x or 0):";
char userChar;
while(true){
    cin>>userChar;
    if(userChar=='x'||userChar=='0'){
    break;
    }
    else cout<<"\nNevernaya bukva. Vvedite zanovo:";}
game::Game game1 = game::initGame(userChar);
    if(game1.isUserTurn){
        while(true){
            game::updateDisplay(game1);
            game::userTurn(&game1);
                       game::updateDisplay(game1);
                       if (game::updateGame(&game1)) break;
                       game::botTurn(&game1);
                       game::updateDisplay(game1);
                       if (game::updateGame(&game1)) break;
                   }
               } else{
                   while (true) {
                       game::botTurn(&game1);
                       game::updateDisplay(game1);
                       if (game::updateGame(&game1)) break;
                       game::userTurn(&game1);
                       game::updateDisplay(game1);
                       if (game::updateGame(&game1)) break;
                   }
               }
               switch (game1.status){
                   case game::USER_WIN:
                       std::cout << "YOU WIN!";
                       break;
                   case game::BOT_WIN:
                       std::cout << "BOT WIN!";
                       break;
                   case game::NOT_WIN:
                       std::cout << "NO WIN!";
                       break;
               }
               std::cout << std::endl;

    ```
    
3. Заголовочный файл.
    ```h
#ifndef HELPFILE_H
#define HELPFILE_H
namespace game {
   enum Status {
       PLAY,            // Игра продолжается
       USER_WIN,        // Игрок победил
       BOT_WIN,         // Бот победил
       NOT_WIN          // Ничья. Победителя нет, но и на поле нет свободной ячейки
   };

   struct Game {
       char bord[3][3];  // Игровое поле
       bool isUserTurn;  // Чей ход. Если пользователя, то isUserTurn = true
       char userChar;    // Символ которым играет пользователь
       char botChar;     // Символ которым играет бот
       Status status;
   };

   Game initGame(char);

   void updateDisplay(const Game);

   void botTurn(Game *);

   void userTurn(Game *);

   bool updateGame(Game *);
}
#endif // HELPFILE_H

    ```
   
#### Ввывод

в ходе лабораторной работы были получены такие навыки, как
* умение создавать многофайловые проекты.

