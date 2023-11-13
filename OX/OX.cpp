#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

char** MatrixOX( int& size);
char** PlrsMove(char** matrix, int& size, int& x, int& y);
void fillwithZeros(char** matrix, int& size);
void printMatrix(char** matrix, int& size);
void printBoard(char** matrix);
char** BotMove(char** matrix, int& size, int& rnd1, int& rnd2,bool& again);
char** BotMoveAgain(char** matrix, int& size, int& rnd1, int& rnd2, bool& again);



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
    while (move<9) {
        std::cout << "Wybierz rzad: " << std::endl;
        std::cin >> x;
        std::cout << "Wybierz kolumne: " << std::endl;
        std::cin >> y;
        if (x > 3 || y > 3) {
            std::cout << "Kordynaty nieprawidlowe" << std::endl;
        }
        else {
            PlrsMove(matrixOX, size, x, y);
            move++;
           // printMatrix(matrixOX, size);
           // std::chrono::milliseconds timespan(3600);
           // std::this_thread::sleep_for(timespan);
            BotMove(matrixOX, size,rnd1,rnd2,again);
            move++;
          //system("cls");
        }
        printBoard(matrixOX);
    } 
}

char** MatrixOX(int& size) {
    char** matrixOX = new char* [size];
    for (int i = 0; i < size; i++) {
        matrixOX[i] = new char[size];
    }
    return matrixOX;
}

void printBoard(char** matrix) {
    std::cout << "         |         |        " << std::endl;
    std::cout << "    "<<matrix[0][0]<<"    |    " << matrix[1][0] << "    |    " << matrix[2][0] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "---------|---------|---------" << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "    " << matrix[0][1] << "    |    " << matrix[1][1] << "    |    " << matrix[2][1] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "---------|---------|---------" << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "    " << matrix[0][2] << "    |    " << matrix[1][2] << "    |    " << matrix[2][2] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
}

char** PlrsMove(char** matrix,int& size,int&x,int&y) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == y-1 && j == x-1) {
                
                if (matrix[i][j]=='O') {
                    system("cls");
                    printBoard(matrix);
                    std::cout << "Zle kordynaty. Podaj nowe: " << std::endl;
                    std::cin >> x;
                    std::cin >> y;
                    PlrsMove(matrix, size, x, y);
                }
                else {
                    matrix[i][j] = 'X';
                }
               

            }
        }
    }
    return matrix;
}
void fillwithZeros(char** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = ' ';
       }
   }
}

void printMatrix(char** matrix,int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
                std::cout<< matrix[i][j]<<" ";
        }std::cout << std::endl;
    }std::cout << std::endl;
}

char** BotMove(char** matrix, int& size,int& rnd1,int& rnd2,bool& again) {
        rnd1 = rand() % 3;
        rnd2 = rand() % 3;
        std::cout << rnd1 + 1 << " pierwszy " << rnd2 + 1 << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == rnd1 && j == rnd2) {
                    if (matrix[i][j] == 'X' || matrix[i][j] == 'O') {
                        std::cout << rnd1 + 1 << " drugi " << rnd2 + 1 << std::endl;
                        again = true;
                        BotMove(matrix, size, rnd1, rnd2, again);
                    }
                    else {
                        matrix[i][j] = 'O';
                        again = false;
                    }
                }
            }
        }
   
    return matrix;
}

char** possibleWin(char** matrix,int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[0][0]=='X'&& matrix[0][1] == 'X'&& matrix[0][2] == 'X') {
                std::cout << "Wygrales";
            }
        }
    }
    return 0;
}

char** BotMoveAgain(char** matrix, int& size, int& rnd1, int& rnd2, bool& again) {
    if(again==true){
    rnd1 = rand() % 3;
    rnd2 = rand() % 3;
    std::cout << rnd1 + 1 << " pierwszy " << rnd2 + 1 << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == rnd1 && j == rnd2) {
                if (matrix[i][j] == 'X' || matrix[i][j] == 'O') {
                    std::cout << rnd1 + 1 << " drugi " << rnd2 + 1 << std::endl;
                    again = true;
                    BotMove(matrix, size, rnd1, rnd2, again);
                }
                else {
                    matrix[i][j] = 'O';
                    again = false;
                }
            }
        }
    }
}
    else {
        std::cout << rnd1 + 1 << " pierwszy " << rnd2 + 1 << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == rnd1 && j == rnd2) {
                    if (matrix[i][j] == 'X' || matrix[i][j] == 'O') {
                        std::cout << rnd1 + 1 << " drugi " << rnd2 + 1 << std::endl;
                        again = true;
                        BotMoveAgain(matrix, size, rnd1, rnd2, again);
                    }
                    else {
                        matrix[i][j] = 'O';
                        again = false;
                    }
                }
            }
        }
    }
    return matrix;
}



