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
bool validateMove(vector<int>&,bool,Stats);
void fillBoard();
bool isPlayer(bool, int);
bool isKing(int);
char board[64];
int main(int argc, char** argv) {
    //Fill structure with null values
    Stats game;
    game.p1Jumps = 0;
    game.p1Kings = 0;
    game.p1Moves = 0;
    game.p2Jumps = 0;
    game.p2Kings = 0;
    game.p2Moves = 0;
    //Fill board with initial values
    fillBoard();
    //Output Board
    outputBoard();
    bool curPlayer = playerOne;
    while(1){
        vector<int> mList;
        mList = move(curPlayer);
        if(validateMove(mList,curPlayer,game) == false){
            cerr << "Invalid move\n";
            continue;
        }
        else{
            outputBoard();
            curPlayer = !curPlayer; 
        }
    }
    return 0; 
}
vector<int> move(bool curPlayer){
    cout << "Enter a pair of coordinates, first letter then number(ex. A1B2)\n";
    if(curPlayer)cout << "Player 1 turn\n";
    else cout << "Player 2 turn\n";
    string pos;
    getline(cin,pos);
    int idx = 0;
    int val = 0;
    vector<int> num;
    while(idx < pos.size()){
        if(idx%2 == 0){
            val = (toupper(pos[idx])-'A')*8;
            
        }
        else{
            val += pos[idx] - '1';
            num.push_back(val);
        }
        ++idx;
    }
    return num;
    
    
}
bool validateMove(vector<int>& move, bool curPlayer, Stats game){
    int boardCopy[64];
    memcpy(boardCopy,board,sizeof(boardCopy));
    int curPos = move[0];
    isPlayer(curPlayer,curPos);
    int nextPos;
    int diff = 0;
    int diffy = 0;
    bool validMove = false;
    for(int i = 1; i < move.size(); ++i){
        curPos = move[i-1];
        nextPos = move[i];
        diff = nextPos - curPos;
        diffy = (move[i+1] - nextPos);
        if(curPlayer == playerOne){
            if(curPos <= 63 && curPos >= 56){
                board[curPos] = redKing;
                ++game.p1Kings;
            }
        }
        else{
            if(curPos <= 7 && curPos >= 0){
                board[curPos] = blackKing;
                ++game.p2Kings;
            }
        }
        if(board[nextPos] != empty){
            cout << "Not an empty position\n";
        }
        else if(isPlayer(curPlayer,curPos)){
            cout << "Not your piece\n";
        }
        else if(curPos%8 == 0){
            if(isKing(curPos)){
                if(curPlayer == playerOne){
                    if(diff == -7 || diff == +9){
                        board[curPos+diff] == redKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == -14 || diff == +18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = redKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == -7 || diff == +9){
                        board[curPos+diff] == blackKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == -14 || diff == +18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = blackKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                }
            }
            else if(curPlayer == playerOne){
                if(diff == +9){
                    board[curPos+diff] = red;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +18){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = red;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }                
            }
            else{
                if(diff == -7){
                    board[curPos+diff] = black;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -14){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = black;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
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
                        board[curPos+diff] == redKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == +14 || diff == -18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = redKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == +7 || diff == -9){
                        board[curPos+diff] == blackKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == +14 || diff == -18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = blackKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                } 
            }
            else if(curPlayer == playerOne){
                if(diff == +7){
                    board[curPos+diff] = red;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +14){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = red;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }                
            }
            else{
                if(diff == -9){
                    board[curPos+diff] = black;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -18){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = black;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
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
                        board[curPos+diff] == redKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p1Moves;
                    }
                    else if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = redKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p1Jumps;
                            }
                        }
                    }
                }
                else{
                    if(diff == +7 || diff == -7 || diff == +9 || diff == -9){
                        board[curPos+diff] == blackKing;
                        board[curPos] = empty;
                        validMove = true;
                        ++game.p2Moves;
                    }
                    else if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
                        if(board[curPos+(diff/2) != empty]){
                            if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                                cout << "Cannot remove own piece\n";
                            }
                            else{
                                board[curPos+diff] = blackKing;
                                board[curPos+(diff/2)] = empty;
                                board[curPos] = empty;
                                validMove = true;
                                ++game.p2Jumps;
                            }
                        }
                    }                    
                }                
            }
            else if(curPlayer == playerOne){
                if(diff == +7){
                    board[curPos+diff] = red;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +14){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = red;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }
                }
                else if(diff == +9){
                    board[curPos+diff] = red;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p1Moves;
                }
                else if(diff == +18){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == red || board[curPos+(diff/2)] == redKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = red;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p1Jumps;
                        }
                    }                    
                }
            }
            else{
                if(diff == -7){
                    board[curPos+diff] = black;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -14){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = black;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }
                }
                else if(diff == -9){
                    board[curPos+diff] = black;
                    board[curPos] = empty;
                    validMove = true;
                    ++game.p2Moves;
                }
                else if(diff == -18){
                    if(board[curPos+(diff/2)] != empty){
                        if(board[curPos+(diff/2)] == black || board[curPos+(diff/2)] == blackKing){
                            cout << "Cannot remove own piece\n";
                        }
                        else{
                            board[curPos+diff] = black;
                            board[curPos+(diff/2)] = empty;
                            board[curPos] = empty;
                            validMove = true;
                            ++game.p2Jumps;
                        }
                    }                    
                }                
            }
        }
                if(curPlayer == playerOne){
            if(nextPos <= 63 && nextPos >= 56){
                board[nextPos] = redKing;
                ++game.p1Kings;
            }
        }
        else{
            if(nextPos <= 7 && nextPos >= 0){
                board[nextPos] = blackKing;
                ++game.p2Kings;
            }
        }
        if(diff == +14 || diff == -14 || diff == +18 || diff == -18){
            if(diffy == +7 || diffy == -7 || diffy == +9 || diffy == -9){
                cout << "diffy: " << diffy << endl;
                break;
            }
        }
        if(diff == +7 || diff == -7 || diff == +9 || diff == -9){
            cout << "diff: " << diff << endl;
            break;
        }
    }
    if(!validMove){
        memcpy(board,boardCopy,sizeof(board));
    }
    return validMove;
}
bool isKing(int pos){
    return(board[pos] == blackKing || board[pos] == redKing);
}
void outputBoard(){
    int row = 0;
    cout << "      Player 1\n";
    cout << "  1 2 3 4 5 6 7 8\n";
    char x = 'A' , y = 'A';
    for(int i = 0; i < 8; ++i){ 
        for(int j = 0; j < 8; ++j){
            if(j == 0){
                cout << x << " ";
                ++x;
        }
            cout << board[i*8 +j] << " ";
            if(j == 7){
                cout << y << " ";
                ++y;
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
        board[i] = empty;
    }
    board[0] = red;
    board[2] = red;
    board[4] = red;
    board[6] = red;
    board[9] = red;
    board[11] = red;
    board[13] = red;
    board[15] = red;
    board[16] = red;
    board[18] = red;
    board[20] = red;
    board[22] = red;
    board[41] = black;
    board[43] = black;
    board[45] = black;
    board[47] = black;
    board[48] = black;
    board[50] = black;
    board[52] = black;
    board[54] = black;
    board[57] = black;
    board[59] = black;
    board[61] = black;
    board[63] = black;
}
