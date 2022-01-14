//
//  blackjack.h
//  Assignment2
//
//  Created by Ian Tsai on 2020-03-05.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//

#ifndef blackjack_h
#define blackjack_h
#include <vector>
using namespace std;

enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Type {CLUBS=1, DIAMONDS, HEARTS, SPADES};

class Card{
    private:
        Rank curRank;
        Type curType;

    public:
        Card(Rank r,Type t);
        int getValue();
        void displayCard();
};

class Hand{
    public:
        vector<Card> hand;
        void add(Card pCard);
        void clear();
        int getTotal();
};

class Deck{
    private:
        vector<Card> deck;
    public:
        void populate();
        void shuffle();
        Card deal();
};

class AbstractPlayer: public Hand{
    public:
        virtual bool isDrawing() = 0;
        bool isBusted();
};

class ComputerPlayer: public AbstractPlayer{
    public:
        bool isDrawing();
};

class HumanPlayer: public AbstractPlayer{
    public:
        bool isDrawing();
        void announce(int input);
};

class BlackJackGame {
    private:
        Deck m_deck;
        HumanPlayer m_player;
        ComputerPlayer m_casino;

    public:
        int play();
};

#endif /* blackjack_h */
