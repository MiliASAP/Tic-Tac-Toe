#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

std::string** MatrixOX( int& size);
std::string** PlrsMove(std::string** matrix, int& size, int& x, int& y);
void fillwithZeros(std::string **matrix, int& size);
void printMatrix(std::string** matrix, int& size);
void printBoard(std::string** matrix);
std::string** BotMove(std::string** matrix, int& size);

int main()
{
    int x;
    int y;
    int size = 3;
    std::string** matrixOX = MatrixOX(size);
    fillwithZeros(matrixOX, size);
    printBoard(matrixOX);
    while (1==true) {
        std::cout << "Wprowadz kordy znaku: " << std::endl;
        std::cin >> x;
        std::cin >> y;
        if (x > 3 || y > 3) {
            std::cout << "Zle kordy smieciu" << std::endl;
        }
        else {
            PlrsMove(matrixOX, size, x, y);
           // printMatrix(matrixOX, size);
           // std::chrono::milliseconds timespan(3600);
           // std::this_thread::sleep_for(timespan);
            BotMove(matrixOX, size);
            system("cls");
        }
        printBoard(matrixOX);
    }
   
    
   
    
}

std::string** MatrixOX(int& size) {
    std::string** matrixOX = new std::string* [size];
    for (int i = 0; i < size; i++) {
        matrixOX[i] = new std::string[size];
    }
    return matrixOX;
}

void printBoard(std::string** matrix) {
    std::cout << "         |         |        " << std::endl;
    std::cout << "    "<<matrix[0][0]<<"    |    " << matrix[0][1] << "    |    " << matrix[0][2] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "---------|---------|---------" << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "    " << matrix[1][0] << "    |    " << matrix[1][1] << "    |    " << matrix[1][2] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "---------|---------|---------" << std::endl;
    std::cout << "         |         |        " << std::endl;
    std::cout << "    " << matrix[2][0] << "    |    " << matrix[2][1] << "    |    " << matrix[2][2] << "     " << std::endl;
    std::cout << "         |         |        " << std::endl;
}

std::string** PlrsMove(std::string** matrix,int& size,int&x,int&y) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == y-1 && j == x-1) {
                 matrix[i][j]="X";
            }
        }
    }
    return matrix;
}
void fillwithZeros(std::string** matrix, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = " ";
       }
   }
}

void printMatrix(std::string** matrix,int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
                std::cout<< matrix[i][j]<<" ";
        }std::cout << std::endl;
    }std::cout << std::endl;
}

std::string** BotMove(std::string** matrix, int& size) {
    srand(time(NULL));
    int rnd = rand() % 3;
    int rnd2 = rand() % 3;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i ==rnd && j == rnd2) {
                if (matrix[i][j] == "X") {
                    BotMove(matrix, size);
                }
                else {
                    matrix[i][j] = "O";
                }
                
            }
        }
    }
    return matrix;
}

std::string** possibleWin() {
    return 0;
}


