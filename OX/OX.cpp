#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>
#include "OX.h"

int main()
{
    int x;
    int y;
    int size = 3;
    int move = 0;
    bool again = false;
    srand(time(NULL));
    int rnd1 = rand() % 3;
    int rnd2 = rand() % 3;
    char** matrixOX = MatrixOX(size);
    fillwithZeros(matrixOX, size);
    printBoard(matrixOX);
        
        
     while (true) {
         if (possibleWin(matrixOX, size) == true) {
             system("cls");
             std::cout << "---------|-WYGRANA-|---------" << std::endl;
             printBoard(matrixOX);
             break;
         }
         else if (possibleBotWin(matrixOX, size) == true) {
             system("cls");
             std::cout << "---------|PRZEGRANA|---------" << std::endl;
             printBoard(matrixOX);
             break;
         }
         else {
             std::cout << "Wybierz rzad: " << std::endl;
             std::cin >> x;
             std::cout << "Wybierz kolumne: " << std::endl;
             std::cin >> y;
             if (x > 3 || y > 3) {
                 std::cout << "Kordynaty nieprawidlowe" << std::endl;
             }
             else {
                 PlrsMove(matrixOX, size, x, y, move);
                 //std::cout << "move: " << move << std::endl;
                 possibleWin(matrixOX, size);
                 possibleBotWin(matrixOX, size);
                 if (move < 9) {
                     BotMove(matrixOX, size, rnd1, rnd2, move);
                     //std::cout << "move: " << move << std::endl;
                     system("cls");
                     possibleWin(matrixOX, size);
                     possibleBotWin(matrixOX, size);
                 }
                 else {
                     system("cls");
                     std::cout << "---------|--REMIS--|---------" << std::endl;
                     printBoard(matrixOX);
                     break;
                 }
             }
         }
         printBoard(matrixOX);
     }
     releaseMem(matrixOX,size);
        
}