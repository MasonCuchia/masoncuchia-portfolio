/*
FILE NAME: Battleship.cpp
AUTHORS: Mason Cuchia 
DATE: 12/09/24
PRE: NONE
POST: Give the user the amount of turns it took them to win
DESCRIPTION: Uses parallel 2d arrays to play single player battleship. 
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Prototypes
void intro(int board[4][4]); //prints instructions
void placeShips(int board[4][4]); //places ships on the board 
void getInput(int &row, int &col); //gets the user input and passes by reference
void displayBoard(int board[4][4]); //shows the player the board
bool checkWin(int board[4][4]); // checks if there are still ships on the board and returns bool

/*
NAME: Mason Cuchia
FUNCTION: main()
PURPOSE: play a single player game of battleship 
PRE: NONE
POST: prints out the number of turns it took the player to win
*/
int main(){
    srand(time(0));

    int user_Pick_Row, user_Pick_Col, turns = 0; // user input and number of turns
    //put 0s on both boards
    int board[4][4] = {0};
    int player_board[4][4] = {0};
    //show the user what the board looks like and how to play
    intro(player_board);
    //put ships onto the board that the user won't see
    placeShips(board);

    while(!(checkWin(board))){//while the user did not win, play the game
        getInput(user_Pick_Row, user_Pick_Col); //get the row and column from the user
        
        if(board[user_Pick_Row][user_Pick_Col] == 1){//player hit something
            //put info on player's view
            player_board[user_Pick_Row][user_Pick_Col] = 1;
            //put info on actual board
            board[user_Pick_Row][user_Pick_Col] = 2;
            cout << "HIT!" << endl;
        }else{//player did not hit anything
            //put info on player's view
            player_board[user_Pick_Row][user_Pick_Col] = 2;
            cout << "MISS." << endl;
        }
        displayBoard(player_board); //show the user the misses and hits
        turns++; //increment the turns
        cout << endl;
    }

    //All the ships are destroyed
    cout << "You win!" << endl;
    cout << "You destroyed all the ships in [" << turns << "] turns." << endl << endl;

    //End Game
    return 0;
}

//functions
/*
FUNCTION: intro()
PURPOSE: Displays the rules of the game
PRE: 2D array board is a 4x4 square
POST: Displays the rules of the game
*/
void intro(int board[4][4]){
    cout << endl << "Welcome to Battleship" << endl << endl;
    cout << "This is what the board looks like" << endl;
    displayBoard(board); //shows the user the board
    cout << "1 = hit. 2 = miss." << endl << endl;
    cout << "There are 3 ships, 2 spaces long, randomly in the water." << endl << endl;
    cout << "To play: input row number, \"Enter\", input column number, \"Enter\"." << endl;
    cout << "(Hint: Rows go down and Columns go across)" << endl;
}
/*
FUNCTION: placeShips()
PURPOSE: puts the ships onto the board
PRE: 2D array board is a 4x4 square
POST: puts the ships onto the board
*/
void placeShips(int board[4][4]){
    int randRow, randCol, ship_orientation; //random row, col and ship orientation
    for(int i = 0; i < 3; i++){//place 3 ships with a random orientation
        ship_orientation = rand() % 2;//random number between 0-1
        if(ship_orientation == 0){// if 0 it is horizontal
            //get random spot
            randRow = rand() %4;//random number between 0-3
            randCol = rand() % 3;//random number between 0-2
            while(board[randRow][randCol] == 1 || board[randRow][randCol+1] == 1){//while new spot or spot next to it is not taken
                randRow = rand() % 4;//random number between 0-3
                randCol = rand() % 3;//random number between 0-2
            }
            //place ship and one to the right
            board[randRow][randCol] = 1;
            board[randRow][randCol+1] = 1;
        }else if(ship_orientation == 1){//if 1 it is vertical
            randRow = rand() % 3;//random number between 0-2
            randCol = rand() % 4;//random number between 0-3
            //make sure the spot isnt taken
            while(board[randRow][randCol] == 1 || board[randRow+1][randCol] == 1){//while new spot or spot under it is not taken
                randRow = rand() % 3;//random number between 0-2
                randCol = rand() % 4;//random number between 0-3
            }
            //place ship and 1 below it
            board[randRow][randCol] = 1;
            board[randRow+1][randCol] = 1;
        }
    }
}
/*
FUNCTION: getInput()
PURPOSE: gets the user's input
PRE: integers row and col passed by reference
POST: users row and column passed by reference
*/
void getInput(int &row, int &col){
    do{
        cout << "Input a row (1-4) and a column (1-4):" << endl;
        cin >> row >> col;
        if((row < 1 || row > 4) || (col < 1 || col > 4)){//if input is not in range 1-4
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        }
    }while((row < 1 || row > 4) || (col < 1 || col > 4)); //while input is not in range 1-4
    //put row and col in array terms (take away 1)
    row--;
    col--;
    cout << endl;
}
/*
FUNCTION: displayBoard()
PURPOSE: displays the game board
PRE: 2D array board is a 4x4 square
POST: game board displayed
*/
void displayBoard(int board[4][4]){
    //show board
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            cout << board[row][col] << " ";//display number at current space
        }
        cout << endl;
    }
}
/*
FUNCTION: checkWin()
PURPOSE: Checks if the 2d array still has a 1 on it
         If it dose, they did not win yet
PRE: 2D array board is a 4x4 square
POST: returns true if user has won, false otherwise
*/
bool checkWin(int board[4][4]){
    //check if there are any 1s left on the board
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(board[row][col] == 1){ //means there still ships
                return false;
            }
        }
    }
    return true;
}








