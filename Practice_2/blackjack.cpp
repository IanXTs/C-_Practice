//
//  blackjack.cpp
//  Assignment2
//
//  Created by Ian Tsai on 2020-03-05.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "blackjack.h"
#include <random>
#include <vector>

using namespace std;

Card::Card(Rank rank,Type type) {
    curRank = rank;
    curType = type;
}

int Card::getValue(){
   if(curRank == JACK || curRank == QUEEN || curRank == KING){
       return 10;
   } else{
       return curRank;
   }
}
    
void Card::displayCard(){
    if(curRank == JACK){
        cout << "J";
    } else if(curRank == QUEEN){
        cout << "Q";
    } else if(curRank == KING){
        cout << "K";
    } else {
        cout << curRank;
    }
    
    if(curType==CLUBS){
        cout << "C ";
    } else if (curType==DIAMONDS){
        cout << "D ";
    } else if (curType==HEARTS){
        cout << "H ";
    } else if (curType==SPADES){
        cout << "S ";
    }
};

void Hand::add(Card inputCard){
    hand.push_back(inputCard);
}
    
void Hand::clear(){
    hand.clear();
};
    
int Hand::getTotal(){
    int total=0;
    for(int i=0; i < hand.size(); i++){
        int getCard = hand.at(i).getValue();
        if(getCard == 1){ //if cur is ACE
            if((getCard + 10 +total)<21){
                getCard = getCard + 10;
            }
        }
        total = total + getCard;
    }
    return total;
};

void Deck::populate(){
    for(Type type = Type::CLUBS; type != Type::SPADES + 1; type = static_cast<Type>(type+1)){
        for(Rank rank = Rank::ACE; rank != Rank::KING + 1; rank = static_cast<Rank>(rank+1)){
            deck.push_back(Card(rank,type));
        }
    }
};
    
void Deck::shuffle(){
    random_device rand;
    ::shuffle(begin(deck),end(deck),rand);
}
    
Card Deck::deal(){
    Card dealt = deck.front();
    deck.erase(deck.begin());
    return dealt;
};

bool AbstractPlayer::isBusted() {
    return getTotal() > 21;
}

bool ComputerPlayer::isDrawing() {
    return getTotal() < 16;
}

bool HumanPlayer::isDrawing(){
        char response;
        cout << "Do you want to draw? (y/n):";
        cin >> response;
        cout << endl;
        if(response == 'y'){
            return true;
        } else{
            return false;
        }
}

void HumanPlayer::announce(int x) {
    if(x==1){
        cout << "Player wins. " << endl;
    } else if(x==2){
        cout << "Casino wins. " << endl;
    } else{
        cout << "Push: No one wins. " << endl;
    }
}

int BlackJackGame::play(){
    
    //Initialize first drawn cards
    m_deck.populate();
    m_deck.shuffle();
    Card computerInit = m_deck.deal();
    cout << "Casino: " ;
    computerInit.displayCard();
    m_casino.add(computerInit);
    cout << " [" << m_casino.getTotal() << "]" << endl;
    cout << "Player: " ;
    Card playerInit1 = m_deck.deal();
    playerInit1.displayCard();
    Card playerInit2 = m_deck.deal();
    playerInit2.displayCard();
    m_player.add(playerInit1);
    m_player.add(playerInit2);
    cout << " [" << m_player.getTotal() << "]" << endl;

    while(m_player.isDrawing()!=false){
        cout << "Player: " ;
        Card player = m_deck.deal();
        m_player.add(player);
        for(Card player : m_player.hand){
            player.displayCard();
        }
        cout << " [" << m_player.getTotal() << "]" << endl;
        //if player hand busts
        if(m_player.isBusted()){
            cout << "Player busts. " << endl;
            m_player.announce(2);
            m_player.clear();
            m_casino.clear();
            return 0;
        }
    }

    while(m_casino.isDrawing()!=false){
        cout << "Casino: " ;
        Card casino = m_deck.deal();
        m_casino.add(casino);
        for(Card casino : m_casino.hand){
            casino.displayCard();
        }
        cout << " [" << m_casino.getTotal() << "]" << endl;
        //if casino hand busts
        if(m_casino.isBusted()){
            cout << "Casino busts"<< endl;
            m_player.announce(1);
            //refresh hand
            m_casino.clear();
            m_player.clear();
            return 0;
        }
    }
   
    //final print
    cout << "Final Casino: " ;
    for(Card casino : m_casino.hand){
        casino.displayCard();
    }
    cout << " [" << m_casino.getTotal() << "]" << endl;
    //if casino hand busts
    if(m_casino.isBusted()){
        cout << "Casino busts"<< endl;
        m_player.announce(1);
        //refresh hand
        m_casino.clear();
        m_player.clear();
        return 0;
    }
    
    //final compare
    if(m_player.getTotal()> m_casino.getTotal()){
        m_player.announce(1);
        //refresh hand
        m_player.clear();
        m_casino.clear();
        return 0;
    } else if(m_player.getTotal() < m_casino.getTotal()){
        m_player.announce(2);
        //refresh hand
        m_player.clear();
        m_casino.clear();
        return 0;
    } else{
        m_player.announce(3);
        //refresh hand
        m_player.clear();
        m_casino.clear();
        return 0;
    }
}
