//
//  main.cpp
//  Assignment2
//
//  Created by Ian Tsai on 2020-03-05.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//

#include <iostream>
#include "blackjack.h"

using namespace std;

int main(){
    cout << "\tWelcome to the Comp322 Blackjack game!" << endl << endl;

    BlackJackGame game;
    bool playAgain = true;
    char anser = 'y';
    
    //The main loop for the game
    while(playAgain){
        game.play();
        //Check whether the player would like to play another round
        cout << "Would you like another round? (y/n): ";
        cin >> anser;
        cout << endl << endl;
        playAgain = (anser == 'y');
    }
    cout << "Game over!" << endl;
    return 0;
}
