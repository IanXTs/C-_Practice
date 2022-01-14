//
//  functions.hpp
//  HelloWorld
//
//  Created by Ian Tsai on 2020-02-13.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
void greetAndInstruct();
void displayBoard (char board[]);
bool checkIfLegal​ (int cellNbre, char board[]);
bool checkWinner(char board[]);
void Move(char input, int position, char board[]);
void computerMove(char board[]);
int canWinNext(char board[]);
#endif /* functions_hpp */

