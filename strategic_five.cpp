#include<iostream>
using namespace std;
#include<windows.h>               //header for clearing the console screen

int counter = 0;
//2D array representing the game board

char shape[10][19]={
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
    {'','','',char(124),'','','',char(124),'','','',char(124),'','','',char(124),'','','_'},
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
    {'','','',char(124),'','','',char(124),'','','',char(124),'','','',char(124),'','','_'},
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
    {'','','',char(124),'','','',char(124),'','','',char(124),'','','',char(124),'','','_'},
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
    {'','','',char(124),'','','',char(124),'','','',char(124),'','','',char(124),'','','_'},
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
    {' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' ',char(124),' ',' ',' '},
};

//function to print the Shape of the game
void printShape(){

    cout<<"Player 1 --> O \n";
    cout<<"Player 2 --> X \n\n";

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 19; ++j) {
            cout << shape[i][j];
        }
        cout << endl;
    }
}

int checkFreeSpaces() {
        int freeSpaces = 0;

        for (int i = 0; i < 9; i += 2) {
            for (int j = 1; j < 19; j += 4) {
                if (shape[i][j] == ' ') {
                    freeSpaces++;
                }
            }
        }

        return freeSpaces;
    }

void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
}
}

class boardGame{
    public:
    int positionX;
    int positionY;

    // Function to ask for row input from the player
    int askrow() {
    int row;
    again:
    cout << "\r Row: "; 
    cin >> row;
    if (row < 1 || row > 5)
        goto again;

    switch(row)
    {
    case 1: 
        row = 0;
    case 2: 
        row = 2;
    case 3:
        row = 4;
    case 4:
        row = 6;
    case 5:
        row = 8;
    return row;
    }
}

// Function to ask for column input from the player

int askcol() {
    int col;
    again:
    cout << "\r Column: "; 
    cin >> col;
    if (col < 1 || col > 5) 
        goto again;

    switch(col)
    {
    case 1:
        col = 1;

    case 2:
        col = 5;
    case 3:
        col = 9;
    case 4:
        col = 13;
    case 5:
        col = 17;
    return col;
    }
}
    bool check(){
        bool flag=false;

        // Check horizontal lines
        for (int i = 0; i < 9; i+=2) {
            if (shape[i][1] == shape[i][5] && shape[i][5] == shape[i][9] && shape[i][9] == shape[i][13] && shape[i][13] == shape[i][17] && shape[i][1] != ' ') {
                flag=true;
                return flag;
            }
        }

        // Check vertical lines
        for (int i = 1; i < 19; i+=4) {
            if (shape[0][i] == shape[2][i] && shape[2][i] == shape[4][i] && shape[4][i] == shape[6][i] && shape[6][i] == shape[8][i] && shape[0][i] != ' ') {
                flag=true;
                return flag;
            }
        }

        // Check diagonals
        if (shape[0][1] == shape[2][5] && shape[2][5] == shape[4][9] && shape[4][9] == shape[6][13] && shape[6][13] == shape[8][17] && shape[0][1] != ' ') {
            flag=true;
            return flag;
        }
        if (shape[0][17] == shape[2][13] && shape[2][13] == shape[4][9] && shape[4][9] == shape[6][5] && shape[6][5] == shape[8][1] && shape[0][17] != ' ') {
            flag=true;
            return flag;
        }
        return flag;
    }
};


int main(){
    boardGame player1{}, player2{};
    int x,y;
    while(1){

        //Player 1 game part
        again1:
        printShape();
        cout<<"\n \" Player 1 Move \" \n";
        y = player1.askrow();
        x = player1.askcol();
        if(shape[y][x]=='X' || shape[y][x]=='O')
        goto again1;
        system("cls");
        shape[y][x]='O';
        counter++;

        //check if the player1 won or not
        if(player1.check()){
            system("cls");
            printShape();
            cout<<"\n PLAYER 1 WON \n";
            break;
        }
        
        //counter to count the number or moves and implment the draw mechanism
        if(counter==25){
            system("cls");
            printShape();
            cout<<"\n DRAW \n";
            break;
        }

        //Player 2 game part
        again2:
        printShape();
        cout<<"\n \" Player 2 Move \" \n";
        y = player2.askrow();
        x = player2.askcol();
        if(shape[y][x]=='X' || shape[y][x]=='O')
        goto again2;
        system("cls");
        shape[y][x]='X';
        counter++;

        //check if the player2 won or not
        if(player2.check()){
            system("cls");
            printShape();
            cout<<"\n PLAYER 2 WON \n";
            break;
        }
    } 

return 0;
}
