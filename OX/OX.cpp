#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>

char** MatrixOX( int& size);
char** PlrsMove(char** matrix, int& size, int& x, int& y);
void fillwithZeros(char** matrix, int& size);
void printMatrix(char** matrix, int& size);
void printBoard(char** matrix);
bool possibleWin(char** matrix, int& size);
char** BotMove(char** matrix, int& size, int& rnd1, int& rnd2, int& move);




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
    if (possibleWin(matrixOX, size) == true) {
        std::cout << "Wygrana" << std::endl;
        break:
    }
    else {
        while (true) {
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
                possibleWin(matrixOX, size);

                BotMove(matrixOX, size, rnd1, rnd2, move);
                move++;
                system("cls");
                possibleWin(matrixOX, size);
            }
            printBoard(matrixOX);
        }
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
                   // system("cls");
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

char** BotMove(char** matrix, int& size,int& rnd1,int& rnd2,int& move) {
        rnd1 = rand() % 3;
        rnd2 = rand() % 3;
        std::cout << rnd1 + 1 << " pierwszy " << rnd2 + 1 << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == rnd1 && j == rnd2 && move<9) {
                    if (matrix[i][j] == 'X' || matrix[i][j] == 'O') {
                       int rnd3 = rand() % 3;
                        int rnd4 = rand() % 3;
                        if (rnd1 == rnd3 || rnd2 == rnd4) {
                            rnd3 = rand() % 3;
                            rnd4 = rand() % 3;
                            BotMove(matrix, size, rnd3, rnd4, move);
                        }
                        else {
                            BotMove(matrix, size, rnd3, rnd4,move);
                            std::cout << rnd1 + 1 << " drugi " << rnd2 + 1 << std::endl;
                        }
                    }
                    else {
                        matrix[i][j] = 'O';
                    }
                }
                else {
                    std::cout << "Remis" << std::endl;
                }
            }
        }
        return matrix;
    
}

bool possibleWin(char** matrix,int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[0][0]=='X'&& matrix[0][1] == 'X'&& matrix[0][2] == 'X') {
               return true;
            }
            else {
                return false;
            }
        }
    }
}







