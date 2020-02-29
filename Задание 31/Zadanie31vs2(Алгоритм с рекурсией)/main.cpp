#include <iostream>
#include<windows.h>
using namespace std;
string maze[25] = {
"####B######################",
"# #       #   #      #    #",
"# # # ###### #### ####### #",
"# # # #       #   #       #",
"#   # # ######### # ##### #",
"# # # #   #       #     # #",
"### ### ### ############# #",
"# #   #     # #           #",
"# # #   ####### ###########",
"# # # #       # #         C",
"# # ##### ### # # ####### #",
"# # #     ### # #       # #",
"#   ##### ### # ######### #",
"######### ### #           #",
"# ####### ### #############",
"A           #   ###   #   #",
"# ############# ### # # # #",
"# ###       # # ### # # # #",
"# ######### # # ### # # # F",
"#       ### # #     # # # #",
"# ######### # ##### # # # #",
"# #######   #       #   # #",
"# ####### ######### #######",
"#         #########       #",
"#######E############D######"
};
string otvet;
void Print(){
    system("cls");
    for(int i=0;i<25;i++){
        //cout<<i;
        for(int k=0;k<27;k++){
            cout<<maze[i][k];
        }
    cout<<"\n";
}
    //cout<<"Exits:"<<otvet;
Sleep(100);
}
void Find(int x,int y){
    Print();
    maze[x][y]='*';
    int c=0;
    if(maze[x][y-1]!='#'&&maze[x][y-1]!=' '&&maze[x][y-1]!='*'){
        otvet+=maze[x][y-1]+' ';
        maze[x][y-1]='#';
    }
    if(maze[x-1][y]!='#'&&maze[x-1][y]!=' '&&maze[x-1][y]!='*'){
        otvet+=maze[x-1][y]+' ';
        maze[x-1][y]='#';
    }
    if(maze[x][y+1]!='#'&&maze[x][y+1]!=' '&&maze[x][y+1]!='*'){
        otvet+=maze[x][y+1]+' ';
        maze[x][y+1]='#';
    }
    if(maze[x+1][y]!='#'&&maze[x+1][y]!=' '&&maze[x+1][y]!='*'){
        otvet+=maze[x+1][y]+' ';
        maze[x+1][y]='#';}
    if(maze[x][y-1]==' ')c++;
    if(maze[x-1][y]==' ')c++;
    if(maze[x][y+1]==' ')c++;
    if(maze[x+1][y]==' ')c++;
    if(c==1){
            if(maze[x][y-1]==' ')y--;
            else if(maze[x-1][y]==' ')x--;
            else if(maze[x][y+1]==' ')y++;
            else if(maze[x+1][y]==' ')x++;
            Find(x,y);}
    else if(c>1){
        if(maze[x][y-1]==' '){//y--;
            Find(x,y-1);}
        if(maze[x-1][y]==' '){//x--;
            Find(x-1,y);}
        if(maze[x][y+1]==' '){//y++;
            Find(x,y+1);}
        if(maze[x+1][y]==' '){//x++;
            Find(x+1,y);
        }
    }
    }

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
        cout<<"Vvedite kordinati:"<<endl;
        int x_start, y_start;
        cin>>y_start>>x_start;
        if(maze[x_start][y_start]!=' '){
            cout<<"nevernoe znacenie kordinat";
        }
        else{
            //maze[x_start][y_start]='$';//Центр начала поиска
            Find(x_start,y_start);
            cout<<"Exits:"<<otvet;
        }

}
