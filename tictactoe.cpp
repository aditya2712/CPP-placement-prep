#include<bits/stdc++.h>
#include<iostream>

#define   NORMAL   cout<<"\t\t     |     |     \n";
#define   MID      cout<<"\t\t_____|_____|_____\n";


using namespace std;

char board[3][3]={'1','2','3','4','5','6','7','8','9'};
char choice,turn='X';
int row=10,column=10;


void display_board();
void player_turn();
bool gameover();


void display_board(){
    system("cls");

    cout<<"\tTIC TAC TOE\n\tPLAYER 1:[X]\n\tPLAYER 2:[O]\n\n";
    NORMAL
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    MID
    NORMAL
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    MID
    NORMAL
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    NORMAL

}


void player_turn(){

    cout<<endl<<endl;

    if(turn=='X'){
        cout<<"\tPLAYER 1 [X] TURN:";
    }
    else if(turn=='O'){
        cout<<"\tPLAYER 2 [O] TURN:";
    }
    cin>>choice;
    fflush(stdin);

    switch(choice){
        case '1': row=0; column=0; break;
        case '2': row=0; column=1; break;
        case '3': row=0; column=2; break;
        case '4': row=1; column=0; break;
        case '5': row=1; column=1; break;
        case '6': row=1; column=2; break;
        case '7': row=2; column=0; break;
        case '8': row=2; column=1; break;
        case '9': row=2; column=2; break;
        default: cout<<"\n\tINVAID CHOICE!\n";   break;
    }


    if(turn=='X' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='O';
        turn='X';
    }
    else {
        cout<<"\tPLEASE TRY AGAIN!!\n";
        player_turn();
    }

}

bool gameover(){
 return false;
}


int main(){
    char cmd[8]="color 0"; //string of command to change color
    while(!gameover()){
        system(cmd);        //change color of text (foreground) in command processor
        display_board();
        player_turn();
        gameover();
        cmd[6]++;           //color update after every chance
    }
}

