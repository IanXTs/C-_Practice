//
//  main.cpp
//  HelloWorld
//
//  Created by Ian Tsai on 2020-02-13.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//

#include <iostream>
#include "functions.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    char gameBoard[26];//one board array with 27 slots
    int move; //player's desired move position
    
    greetAndInstruct(); //greet
    displayBoard(gameBoard); //initialize game board
    while(true){
        cin >> move;
        move=move-1;
        if(checkIfLegal​(move, gameBoard)==true){
            Move('X', move, gameBoard);
            displayBoard(gameBoard);
            checkWinner(gameBoard);
            computerMove(gameBoard);
            checkWinner(gameBoard);
            }
    }
    return 0;
}

