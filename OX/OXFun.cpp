#include <iostream>
#include "OX.h"

char** MatrixOX(int& size) {
    char** matrixOX = new char* [size];
    for (int i = 0; i < size; i++) {
        matrixOX[i] = new char[size];
    }
    return matrixOX;
}

void printBoard(char** matrix) {
    std::cout << "         |         |        " << std::endl;
    std::cout << "    " << matrix[0][0] << "    |    " << matrix[1][0] << "    |    " << matrix[2][0] << "     " << std::endl;
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

char** PlrsMove(char** matrix, int& size, int& x, int& y, int& move) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == y - 1 && j == x - 1) {

                if (matrix[i][j] == 'O') {
                    system("cls");
                    printBoard(matrix);
                    std::cout << "Zle kordynaty. Podaj nowe: " << std::endl;
                    std::cin >> x;
                    std::cin >> y;
                    PlrsMove(matrix, size, x, y, move);
                }
                else {
                    matrix[i][j] = 'X';
                    move++;
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

void printMatrix(char** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }std::cout << std::endl;
    }std::cout << std::endl;
}

char** BotMove(char** matrix, int& size, int& rnd1, int& rnd2, int& move) {
    rnd1 = rand() % 3;
    rnd2 = rand() % 3;
    std::cout << rnd1 + 1 << " pierwszy " << rnd2 + 1 << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == rnd1 && j == rnd2) {
                if (matrix[i][j] == 'X' || matrix[i][j] == 'O') {
                    int rnd3 = rand() % 3;
                    int rnd4 = rand() % 3;
                    if (rnd1 == rnd3 || rnd2 == rnd4) {
                        rnd3 = rand() % 3;
                        rnd4 = rand() % 3;
                        BotMove(matrix, size, rnd3, rnd4, move);
                    }
                    else {
                        BotMove(matrix, size, rnd3, rnd4, move);
                        std::cout << rnd1 + 1 << " drugi " << rnd2 + 1 << std::endl;
                    }
                }
                else {
                    matrix[i][j] = 'O';
                    move++;
                }
            }
        }
    }
    return matrix;

}

bool possibleWin(char** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X' ||
                matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X' ||
                matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X' ||
                matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X' ||
                matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X' ||
                matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X' ||
                matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X' ||
                matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
            {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool possibleBotWin(char** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O' ||
                matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O' ||
                matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O' ||
                matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O' ||
                matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O' ||
                matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O' ||
                matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O' ||
                matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
            {
                return true;
            }
        }
    }
}

void releaseMem(char** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}