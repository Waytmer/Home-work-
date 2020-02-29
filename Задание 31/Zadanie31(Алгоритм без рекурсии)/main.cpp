#include <iostream>
#include <locale>
#include<windows.h>
using namespace std;
string otvet;
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
void Print(){
    system("cls");
    for(int i=0;i<25;i++){
        //cout<<i;
        for(int k=0;k<27;k++){
            cout<<maze[i][k];
        }
    cout<<"\n";
}
    cout<<"Exits:"<<otvet;
Sleep(100);
}

void Find(int x_start,int y_start){
    int x=x_start, y=y_start;

    while(1){
    while(maze[x][y-1]==' '||maze[x-1][y]==' '||maze[x][y+1]==' '||maze[x+1][y]==' '){
    if(maze[x][y-1]==' '){
    while(maze[x][y-1]==' '){
        --y;
        maze[x][y]='*';
        Print();

    }
    }
    else if(maze[x-1][y]==' '){
        while(maze[x-1][y]==' '){
            --x;
            maze[x][y]='*';
            Print();

    }
    }
    else if(maze[x][y+1]==' '){
        while(maze[x][y+1]==' '){
            y++;
            maze[x][y]='*';
            Print();

        }
}
    else if(maze[x+1][y]==' '){
        while(maze[x+1][y]==' '){
            x++;
            maze[x][y]='*';
            Print();

    }
    }

    }
    int a = 0,b = 0,c = 0;
    if(maze[x][y-1]!='#'&&maze[x][y-1]!=' '&&maze[x][y-1]!='*'&&maze[x][y-1]!='@'&&maze[x][y-1]!='$'){
        otvet+=maze[x][y-1]+' ';
        maze[x][y-1]='#';
    }
    if(maze[x-1][y]!='#'&&maze[x-1][y]!=' '&&maze[x-1][y]!='*'&&maze[x-1][y]!='@'&&maze[x-1][y]!='$'){
        otvet+=maze[x-1][y]+' ';
        maze[x-1][y]='#';
    }
    if(maze[x][y+1]!='#'&&maze[x][y+1]!=' '&&maze[x][y+1]!='*'&&maze[x][y+1]!='@'&&maze[x][y+1]!='$'){
        otvet+=maze[x][y+1]+' ';
        maze[x][y+1]='#';
    }
    if(maze[x+1][y]!='#'&&maze[x+1][y]!=' '&&maze[x+1][y]!='*'&&maze[x+1][y]!='@'&&maze[x+1][y]!='$'){
        otvet+=maze[x+1][y]+' ';
        maze[x+1][y]='#';
    }
    Print();
    if(maze[x][y-1]=='*')c++;
    if(maze[x-1][y]=='*')c++;
    if(maze[x][y+1]=='*')c++;
    if(maze[x+1][y]=='*')c++;
    if(maze[x][y-1]=='#')a++;
    if(maze[x-1][y]=='#')a++;
    if(maze[x][y+1]=='#')a++;
    if(maze[x+1][y]=='#')a++;
    if(maze[x][y-1]=='@')b++;
    if(maze[x-1][y]=='@')b++;
    if(maze[x][y+1]=='@')b++;
    if(maze[x+1][y]=='@')b++;
    if((a+b<=2)&&(b!=2)){
    if(maze[x][y-1]=='*')--y;
    else if(maze[x-1][y]=='*')--x;
    else if(maze[x][y+1]=='*')++y;
    else if(maze[x+1][y]=='*')++x;}
    else {
        if(maze[x][y-1]=='$'||maze[x-1][y]=='$'||maze[x][y+1]=='$'||maze[x+1][y]=='$'){
            if(a+b+c==4)break;
        x=x_start;
        y=y_start;
        Print();
        }
        else{
            maze[x][y]='@';
            if(maze[x][y-1]=='*')--y;
            else if(maze[x-1][y]=='*')--x;
            else if(maze[x][y+1]=='*')++y;
            else if(maze[x+1][y]=='*')++x;
            Print();
        }
    }

}
}
int main()
{   setlocale(LC_ALL, "RUSSIAN");
    cout<<"Vvedite kordinati:"<<endl;
    int x_start, y_start;
    cin>>y_start>>x_start;
    if(maze[x_start][y_start]!=' '){
        cout<<"nevernoe znacenie kordinat";
    }
    else{
        maze[x_start][y_start]='$';//Центр начала поиска
        Find(x_start,y_start);
    }
}
