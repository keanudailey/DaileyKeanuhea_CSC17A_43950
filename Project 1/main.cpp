/* 
 * File:   main.cpp
 * Author: Keanu Dailey
 * Created on April 26, 2015, 11:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#include "stats.h"
/*
 * 
 */
enum Checker {blackKing = 'B', black = 'b', redKing = 'R', red = 'r', empty = '-'};
enum Players {playerOne = true, playerTwo = false};
vector<int> move(bool);
void outputBoard();
bool validateMove(vector<int>&,bool);
void fillBoard();
bool isPlayer(bool, int);
bool isKing(int);
Stats game;
int main(int argc, char** argv) {
    //Fill structure with null values
    game.board = new char[64];
    game.p1Jumps = 0;
    game.p1Kings = 0;
    game.p1Moves = 0;
    game.p2Jumps = 0;
    game.p2Kings = 0;
    game.p2Moves = 0;
    //Fill game.board with initial values
    fillBoard();
    //Output Board
    outputBoard();
    bool curPlayer = playerOne;
    while(1){
        vector<int> moveList;
        moveList = move(curPlayer);
        if(validateMove(moveList,curPlayer) == false){
            cerr << "Invalid move\n";
            //continue;
        }
        else{
            outputBoard();
            curPlayer = !curPlayer; 
        }
    }
    delete[]game.board;
    return 0; 
}
vector<int> move(bool curPlayer){
    cout << "Enter a pair of coordinates, first letter then number(ex. A1B2)\n";
    if(curPlayer)cout << "Player 1 turn\n";
    else cout << "Player 2 turn\n";
    string pos;
    getline(cin,pos);
    int idx = 0;
    int value = 0;
    vector<int> num;
    while(idx < pos.size()){
        if(idx%2 == 0){
            value = (toupper(pos[idx])-'A')*8;
            
        }
        else{
            value += pos[idx] - '1';
            num.push_back(value);
        }
        ++idx;
    }
    return num;
    
    
}
bool validateMove(vector<int>& move, bool curPlayer){
    int boardCopy[64];
    int curPos = move[0];
    isPlayer(curPlayer,curPos);
    int nextPos;
    int diff = 0;
    int nextDiff = 0;
    bool validMove = false;
    for(int i = 1; i < move.size(); ++i){
        curPos = move[i-1];
        nextPos = move[i];
        diff = nextPos - curPos;
        nextDiff = (move[i+1] - nextPos);
        if(curPlayer == playerOne){
            if(curPos <= 63 && curPos >= 56){
                game.board[curPos] = redKing;
                ++game.p1Kings;
            }
        }
        else{
            if(curPos <= 7 && curPos >= 0){
                game.board[curPos] = blackKing;
                ++game.p2Kings;
            }
        }
        if(game.board[nextPos] != empty){
            cout << "Not an empty position\n";
        }
        else if(isPlayer(curPlayer,curPos)){
            cout << "Not your piece\n";
        }
        else if(curPos%8 == 0){
            if(isKing(curPos)){
                if(curPlayer == playerOne){
                    if(diff == -7 || diff == +9){
                        game.board[curPos+diff] == redKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == -14 || diff == +18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = redKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == -7 || diff == +9){
                        game.board[curPos+diff] == blackKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == -14 || diff == +18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = blackKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                }
            }
            else if(curPlayer == playerOne){
                if(diff == +9){
                    game.board[curPos+diff] = red;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +18){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = red;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }                
            }
            else{
                if(diff == -7){
                    game.board[curPos+diff] = black;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -14){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = black;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }
                }                
            }
        }
        else if(curPos%8 == 7){
            if(isKing(curPos)){
                if(curPlayer == playerOne){
                    if(diff == +7 || diff == -9){
                        game.board[curPos+diff] == redKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == +14 || diff == -18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = redKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == +7 || diff == -9){
                        game.board[curPos+diff] == blackKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == +14 || diff == -18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = blackKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                } 
            }
            else if(curPlayer == playerOne){
                if(diff == +7){
                    game.board[curPos+diff] = red;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +14){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = red;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }                
            }
            else{
                if(diff == -9){
                    game.board[curPos+diff] = black;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -18){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = black;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }
                }
            }
        }
        else{
            if(isKing(curPos)){
                if(curPlayer == playerOne){
                    if(diff == +7 || diff == -7 || diff == +9 || diff == -9){
                        game.board[curPos+diff] == redKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = redKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == +7 || diff == -7 || diff == +9 || diff == -9){
                        game.board[curPos+diff] == blackKing;
                        game.board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
                        if(game.board[curPos+(diff/2) != empty]){
                            if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                game.board[curPos+diff] = blackKing;
                                game.board[curPos+(diff/2)] = empty;
                                game.board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                }                
            }
            else if(curPlayer == playerOne){
                if(diff == +7){
                    game.board[curPos+diff] = red;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +14){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = red;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }
                else if(diff == +9){
                    game.board[curPos+diff] = red;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +18){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == red || game.board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = red;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }                    
                }
            }
            else{
                if(diff == -7){
                    game.board[curPos+diff] = black;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -14){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = black;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }
                }
                else if(diff == -9){
                    game.board[curPos+diff] = black;
                    game.board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -18){
                    if(game.board[curPos+(diff/2)] != empty){
                        if(game.board[curPos+(diff/2)] == black || game.board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            game.board[curPos+diff] = black;
                            game.board[curPos+(diff/2)] = empty;
                            game.board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }                    
                }                
            }
        }
                if(curPlayer == playerOne){
            if(nextPos <= 63 && nextPos >= 56){
                game.board[nextPos] = redKing;
                ++game.p1Kings;
            }
        }
        else{
            if(nextPos <= 7 && nextPos >= 0){
                game.board[nextPos] = blackKing;
                ++game.p2Kings;
            }
        }
        if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
            if(nextDiff == +7 || nextDiff == -7 || nextDiff == +9 || nextDiff == -9){
                break;
            }
        }
        if(diff == +7 || diff == -7 || diff == +9 || diff == -9){
            break;
        }
    }
    if(!validMove){
        memcpy(game.board,boardCopy,sizeof(game.board));
    }
    return validMove;
}
bool isKing(int pos){
    return(game.board[pos] == blackKing || game.board[pos] == redKing);
}
void outputBoard(){
    int row = 0;
    cout << "      Player 1\n";
    cout << "  1 2 3 4 5 6 7 8\n";
    char xAxis= 'A' , yAxis = 'A';
    for(int i = 0; i < 8; ++i){ 
        for(int j = 0; j < 8; ++j){
            if(j == 0){
                cout << xAxis<< " ";
                ++xAxis;
        }
            cout << game.board[i*8 +j] << " ";
            if(j == 7){
                cout << yAxis << " ";
                ++yAxis;
            }
        }
        cout << endl;
    }
    cout << "  1 2 3 4 5 6 7 8\n";
    cout << "      Player 2\n";
}
bool isPlayer(bool curPlayer, int pos){
    if(curPlayer == playerOne){
        return(pos == red || pos == redKing);
    }
    else{
        return(pos == black || pos == blackKing);
    } 
}
void fillBoard(){
    for(int i = 0; i < 64; ++i){
        game.board[i] = empty;
    }
    game.board[0] = red;
    game.board[2] = red;
    game.board[4] = red;
    game.board[6] = red;
    game.board[9] = red;
    game.board[11] = red;
    game.board[13] = red;
    game.board[15] = red;
    game.board[16] = red;
    game.board[18] = red;
    game.board[20] = red;
    game.board[22] = red;
    game.board[41] = black;
    game.board[43] = black;
    game.board[45] = black;
    game.board[47] = black;
    game.board[48] = black;
    game.board[50] = black;
    game.board[52] = black;
    game.board[54] = black;
    game.board[57] = black;
    game.board[59] = black;
    game.board[61] = black;
    game.board[63] = black;
}
