
//  functions.cpp
//  HelloWorld
//
//  Created by Ian Tsai on 2020-02-13.
//  Copyright © 2020 Ian Tsai. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include "functions.hpp"

using namespace std;
void greetAndInstruct(){
    char insert;
    cout<< //greeting msg
    "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n"
    "The board is numbered from 1 to 27 as per the following:\n\n"
    "1|2|3 10|11|12 19|20|21\n"
    "4|5|6 13|14|15 22|23|24\n"
    "7|8|9 16|17|18 25|26|27\n\n"
    "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O.\n"
    "Start? (y/n)\n";
    cin >> insert; //takes input y/n
    
    if(insert == 'y'){
        cout << "Drop your move on the board" <<endl;
    } else if (insert == 'n'){
        exit(2);
    }else{
        cout<< "Unidentified input!\n";
        exit(3);
    }
}

void displayBoard (char board[]){
    string forPrint[27] ={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"};
    
    for(int i=0; i<27; i++){
        if(board[i]=='X' || board[i]=='O' ){
            forPrint[i]=board[i]; //insert 'X' and 'O'
        }
    }
    
    int x=0;
    for(int i=0; i<3; i++){
        cout<< forPrint[x] << "|" << forPrint[x+1] << "|" << forPrint[x+2] << "   ";
        x=x+9;
    }
    cout << "\n" << endl;
    int y=3;
    for(int i=0; i<3; i++){
        cout<< forPrint[y] << "|" << forPrint[y+1] << "|" << forPrint[y+2] << "   ";
        y=y+9;
    }
    cout << "\n" << endl;
    int z=6;
    for(int i=0; i<3; i++){
        cout<< forPrint[z] << "|" << forPrint[z+1] << "|" << forPrint[z+2] << "   ";
        z=z+9;
    }
    cout<< "\n" << endl;
}

bool checkIfLegal​ (int cellNbre, char board[]){
    if(board[cellNbre]=='X' || board[cellNbre]=='O'){
        cout << "Spot taken!" << endl;
        displayBoard(board);
        return false;
    } else if (cellNbre>26 || cellNbre<0){
        cout << "Out of Range" << endl;
        displayBoard(board);
        return false;
    } else{
        return true;
    }
}

bool checkWinner(char board[]){
    //Tie Condition
    int count=0;
    for(int i=0; i<27; i++){
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
        if(count==27){
            cout<<"It's a Tie!"<<endl;
            exit(10);
            return false;
        }
    }
    
    //2D horizontal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+1] && board[x+1]==board[x+2] && board[x+2]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        } else if(board[x]==board[x+1] && board[x+1]==board[x+2] && board[x+2]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int y=3;
        y=y+9*i;
        if(board[y]==board[y+1] && board[y+1]==board[y+2] && board[y+2]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+1] && board[y+1]==board[y+2] && board[y+2]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int z=6;
        z=z+9*i;
        if(board[z]==board[z+1] && board[z+1]==board[z+2] && board[z+2]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[z]==board[z+1] && board[z+1]==board[z+2] && board[z+2]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    //2D vertical
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+3] && board[x+3]==board[x+6] && board[x+6]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        } else if(board[x]==board[x+3] && board[x+3]==board[x+6] && board[x+6]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int y=1;
        y=y+9*i;
        if(board[y]==board[y+3] && board[y+3]==board[y+6] && board[y+6]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+3] && board[y+3]==board[y+6] && board[y+6]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int z=2;
        z=z+9*i;
        if(board[z]==board[z+3] && board[z+3]==board[z+6] && board[z+6]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[z]==board[z+3] && board[z+3]==board[z+6] && board[z+6]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    //2D diagonal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+4] && board[x+4]==board[x+8] && board[x+8]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        } else if(board[x]==board[x+4] && board[x+4]==board[x+8] && board[x+8]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int y=2;
        y=y+9*i;
        if(board[y]==board[y+2] && board[y+2]==board[y+4] && board[y+4]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+2] && board[y+2]==board[y+4] && board[y+4]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    //3D horizontal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+3*i;
        if(board[x]==board[x+10] && board[x+10]==board[x+20] && board[x+20]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        } else if(board[x]==board[x+10] && board[x+10]==board[x+20] && board[x+20]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int z=2;
        z=z+3*i;
        if(board[z]==board[z+8] && board[z+8]==board[z+16] && board[z+16]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[z]==board[z+8] && board[z+8]==board[z+16] && board[z+16]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    //3D vertical
    for(int i=0; i<3; i++){
        int x=0;
        x=x+3*i;
        if(board[x]==board[x+9] && board[x+9]==board[x+18] && board[x+18]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        } else if(board[x]==board[x+9] && board[x+9]==board[x+18] && board[x+18]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int y=1;
        y=y+3*i;
        if(board[y]==board[y+9] && board[y+9]==board[y+18] && board[y+18]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+9] && board[y+9]==board[y+18] && board[y+18]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int z=2;
        z=z+3*i;
        if(board[z]==board[z+9] && board[z+9]==board[z+18] && board[z+18]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[z]==board[z+9] && board[z+9]==board[z+18] && board[z+18]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    //3D diagonal
    int x=0;
    if(board[x]==board[x+13] && board[x+13]==board[x+26] && board[x+26]=='X'){
        cout << "Player Won\n";
        exit(7);
        return true;
    } else if(board[x]==board[x+13] && board[x+26]==board[x+8] && board[x+26]=='O'){
        cout << "Computer Won\n";
        exit(7);
        return true;
    }
    
    int y=6;
    if(board[y]==board[y+7] && board[y+7]==board[y+14] && board[y+14]=='X'){
        cout << "Player Won\n";
        exit(7);
        return true;
    } else if(board[x]==board[y+7] && board[y+7]==board[y+14] && board[y+14]=='O'){
        cout << "Computer Won\n";
        exit(7);
        return true;
    }
    
    for(int i=0; i<3; i++){
        int y=0;
        y=y+i;
        if(board[y]==board[y+12] && board[y+12]==board[y+24] && board[y+24]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+12] && board[y+12]==board[y+24] && board[y+24]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        int y=6;
        y=y+i;
        if(board[y]==board[y+6] && board[y+6]==board[y+12] && board[y+12]=='X'){
            cout << "Player Won\n";
            exit(7);
            return true;
        }else if(board[y]==board[y+6] && board[y+6]==board[y+12] && board[y+12]=='O'){
            cout << "Computer Won\n";
            exit(7);
            return true;
        }
    }
    return false;
}

//Move method
void Move(char input, int position, char board[]){
    board[position]=input;
}

void computerMove(char board[]){
    if(canWinNext(board)!=0){
        cout<< "Computer played: " << canWinNext(board)+1 << "\n";
        Move('O', canWinNext(board), board);
    } else{
        int x=0;
        while(board[x]!='\0'){
            x++;
        }
        Move('O', x, board);
        cout<< "Computer played: " << x+1 << "\n";
    }
    displayBoard(board);
}

//predict next move
int canWinNext(char board[]){
    //2d horizontal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+1] && board[x]=='X' && board[x+2]!='X' && board[x+2]!='O'){
            return x+2;
        } else if(board[x+1]==board[x+2] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+2] && board[x]=='X' && board[x+1]!='X' && board[x+1]!='O'){
            return x+1;
        }else if(board[x]==board[x+1] && board[x]=='O' && board[x+2]!='O' && board[x+2]!='O'){
            return x+2;
        } else if(board[x]==board[x+2] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+2] && board[x]=='O' && board[x+1]!='O' && board[x+1]!='O'){
            return x+1;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=3;
        x=x+9*i;
        if(board[x]==board[x+1] && board[x]=='X' && board[x+2]!='X' && board[x+2]!='O'){
            return x+2;
        } else if(board[x+1]==board[x+2] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+2] && board[x]=='X' && board[x+1]!='X' && board[x+1]!='O'){
            return x+1;
        }else if(board[x]==board[x+1] && board[x]=='O' && board[x+2]!='O' && board[x+2]!='O'){
            return x+2;
        } else if(board[x]==board[x+2] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+2] && board[x]=='O' && board[x+1]!='O' && board[x+1]!='O'){
            return x+1;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=6;
        x=x+9*i;
        if(board[x]==board[x+1] && board[x]=='X' && board[x+2]!='X' && board[x+2]!='O'){
            return x+2;
        } else if(board[x+1]==board[x+2] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+2] && board[x]=='X' && board[x+1]!='X' && board[x+1]!='O'){
            return x+1;
        }else if(board[x]==board[x+1] && board[x]=='O' && board[x+2]!='O' && board[x+2]!='O'){
            return x+2;
        } else if(board[x]==board[x+2] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+2] && board[x]=='O' && board[x+1]!='O' && board[x+1]!='O'){
            return x+1;
        }
    }
    
    //2d vertical
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+3] && board[x]=='X' && board[x+6]!='X' && board[x+6]!='O'){
            return x+6;
        } else if(board[x+3]==board[x+6] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+6] && board[x]=='X' && board[x+3]!='X' && board[x+3]!='O'){
            return x+3;
        }else if(board[x]==board[x+3] && board[x]=='O' && board[x+6]!='O' && board[x+6]!='O'){
            return x+6;
        } else if(board[x]==board[x+6] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+6] && board[x]=='O' && board[x+3]!='O' && board[x+3]!='O'){
            return x+3;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=1;
        x=x+9*i;
        if(board[x]==board[x+3] && board[x]=='X' && board[x+6]!='X' && board[x+6]!='O'){
            return x+6;
        } else if(board[x+3]==board[x+6] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+6] && board[x]=='X' && board[x+3]!='X' && board[x+3]!='O'){
            return x+3;
        }else if(board[x]==board[x+3] && board[x]=='O' && board[x+6]!='O' && board[x+6]!='O'){
            return x+6;
        } else if(board[x]==board[x+6] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+6] && board[x]=='O' && board[x+3]!='O' && board[x+3]!='O'){
            return x+3;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=2;
        x=x+9*i;
        if(board[x]==board[x+3] && board[x]=='X' && board[x+6]!='X' && board[x+6]!='O'){
            return x+6;
        } else if(board[x+3]==board[x+6] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+6] && board[x]=='X' && board[x+3]!='X' && board[x+3]!='O'){
            return x+3;
        }else if(board[x]==board[x+3] && board[x]=='O' && board[x+6]!='O' && board[x+6]!='O'){
            return x+6;
        } else if(board[x]==board[x+6] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+6] && board[x]=='O' && board[x+3]!='O' && board[x+3]!='O'){
            return x+3;
        }
    }
    
    //2D diagonal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+9*i;
        if(board[x]==board[x+4] && board[x]=='X' && board[x+8]!='X' && board[x+8]!='O'){
            return x+8;
        } else if(board[x+4]==board[x+8] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+8] && board[x]=='X' && board[x+4]!='X' && board[x+4]!='O'){
            return x+4;
        }else if(board[x]==board[x+4] && board[x]=='O' && board[x+8]!='O' && board[x+8]!='O'){
            return x+8;
        } else if(board[x]==board[x+8] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+8] && board[x]=='O' && board[x+4]!='O' && board[x+4]!='O'){
            return x+4;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=2;
        x=x+9*i;
        if(board[x]==board[x+2] && board[x]=='X' && board[x+4]!='X' && board[x+4]!='O'){
            return x+4;
        } else if(board[x+2]==board[x+4] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+4] && board[x]=='X' && board[x+2]!='X' && board[x+2]!='O'){
            return x+2;
        }else if(board[x]==board[x+2] && board[x]=='O' && board[x+4]!='O' && board[x+4]!='O'){
            return x+4;
        } else if(board[x+2]==board[x+4] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+4] && board[x]=='O' && board[x+2]!='O' && board[x+2]!='O'){
            return x+2;
        }
    }
    
    //3D horizontal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+3*i;
        if(board[x]==board[x+10] && board[x]=='X' && board[x+20]!='X' && board[x+20]!='O'){
            return x+20;
        } else if(board[x+10]==board[x+20] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+20] && board[x]=='X' && board[x+10]!='X' && board[x+10]!='O'){
            return x+10;
        }else if(board[x]==board[x+10] && board[x]=='O' && board[x+20]!='O' && board[x+20]!='O'){
            return x+20;
        } else if(board[x+10]==board[x+20] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        }else if(board[x]==board[x+20] && board[x]=='O' && board[x+10]!='O' && board[x+10]!='O'){
            return x+10;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=2;
        x=x+3*i;
        if(board[x]==board[x+8] && board[x]=='X' && board[x+16]!='X' && board[x+16]!='O'){
            return x+16;
        } else if(board[x+8]==board[x+16] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+16] && board[x]=='X' && board[x+8]!='X' && board[x+8]!='O'){
            return x+8;
        } else if(board[x]==board[x+8] && board[x]=='O' && board[x+16]!='O' && board[x+16]!='O'){
            return x+16;
        } else if(board[x+8]==board[x+16] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+16] && board[x]=='O' && board[x+8]!='O' && board[x+8]!='O'){
            return x+8;
        }
    }
    
    //3D vertical
    for(int i=0; i<3; i++){
        int x=0;
        x=x+3*i;
        if(board[x]==board[x+9] && board[x]=='X' && board[x+18]!='X' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='X' && board[x+9]!='X' && board[x+9]!='O'){
            return x+9;
        } else if(board[x]==board[x+9] && board[x]=='O' && board[x+18]!='O' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='O' && board[x+9]!='O' && board[x+9]!='O'){
            return x+9;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=1;
        x=x+3*i;
        if(board[x]==board[x+9] && board[x]=='X' && board[x+18]!='X' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='X' && board[x+9]!='X' && board[x+9]!='O'){
            return x+9;
        } else if(board[x]==board[x+9] && board[x]=='O' && board[x+18]!='O' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='O' && board[x+9]!='O' && board[x+9]!='O'){
            return x+9;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=2;
        x=x+3*i;
        if(board[x]==board[x+9] && board[x]=='X' && board[x+18]!='X' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='X' && board[x+9]!='X' && board[x+9]!='O'){
            return x+9;
        } else if(board[x]==board[x+9] && board[x]=='O' && board[x+18]!='O' && board[x+18]!='O'){
            return x+18;
        } else if(board[x+9]==board[x+18] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+18] && board[x]=='O' && board[x+9]!='O' && board[x+9]!='O'){
            return x+9;
        }
    }
    
    //3D diagonal
    for(int i=0; i<3; i++){
        int x=0;
        x=x+i;
        if(board[x]==board[x+12] && board[x]=='X' && board[x+24]!='X' && board[x+24]!='O'){
            return x+24;
        } else if(board[x+12]==board[x+24] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+24] && board[x]=='X' && board[x+12]!='X' && board[x+12]!='O'){
            return x+12;
        } else if(board[x]==board[x+12] && board[x]=='O' && board[x+24]!='O' && board[x+24]!='O'){
            return x+24;
        } else if(board[x+12]==board[x+24] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+24] && board[x]=='O' && board[x+12]!='O' && board[x+12]!='O'){
            return x+12;
        }
    }
    
    for(int i=0; i<3; i++){
        int x=6;
        x=x+i;
        if(board[x]==board[x+6] && board[x]=='X' && board[x+12]!='X' && board[x+12]!='O'){
            return x+12;
        } else if(board[x+6]==board[x+12] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+12] && board[x]=='X' && board[x+6]!='X' && board[x+6]!='O'){
            return x+6;
        } else if(board[x]==board[x+6] && board[x]=='O' && board[x+12]!='O' && board[x+12]!='O'){
            return x+12;
        } else if(board[x+6]==board[x+12] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
            return x;
        } else if(board[x]==board[x+12] && board[x]=='O' && board[x+6]!='O' && board[x+6]!='O'){
            return x+6;
        }
    }
    
    int x=0;
    if(board[x]==board[x+13] && board[x]=='X' && board[x+26]!='X' && board[x+26]!='O'){
        return x+26;
    } else if(board[x+13]==board[x+26] && board[x]=='X'&& board[x]!='X' && board[x]!='O'){
        return x;
    } else if(board[x]==board[x+26] && board[x]=='X' && board[x+13]!='X' && board[x+13]!='O'){
        return x+13;
    } else if(board[x]==board[x+13] && board[x]=='O' && board[x+26]!='O' && board[x+26]!='O'){
        return x+26;
    } else if(board[x+13]==board[x+26] && board[x]=='O' && board[x]!='O' && board[x]!='O'){
        return x;
    } else if(board[x]==board[x+26] && board[x]=='O' && board[x+13]!='O' && board[x+13]!='O'){
        return x+13;
    }
    
    int y=6;
    if(board[y]==board[y+7] && board[y]=='X' && board[y+14]!='X' && board[y+14]!='O'){
        return y+14;
    } else if(board[y+7]==board[y+14] && board[y]=='X'&& board[y]!='X' && board[y]!='O'){
        return y;
    } else if(board[y]==board[y+14] && board[y]=='X' && board[y+7]!='X' && board[y+7]!='O'){
        return y+7;
    } else if(board[y]==board[x+7] && board[y]=='O' && board[y+14]!='O' && board[y+14]!='O'){
        return y+14;
    } else if(board[y+7]==board[y+14] && board[y]=='O' && board[y]!='O' && board[y]!='O'){
        return y;
    } else if(board[y]==board[y+14] && board[y]=='O' && board[y+7]!='O' && board[y+7]!='O'){
        return y+7;
    }
    return 0;
}
