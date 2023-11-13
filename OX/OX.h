#pragma once
#ifndef OXFUN
#define OXFUN
char** MatrixOX( int& size);
char** PlrsMove(char** matrix, int& size, int& x, int& y, int& move);
void fillwithZeros(char** matrix, int& size);
void printMatrix(char** matrix, int& size);
void printBoard(char** matrix);
bool possibleWin(char** matrix, int& size);
bool possibleBotWin(char** matrix, int& size);
char** BotMove(char** matrix, int& size, int& rnd1, int& rnd2, int& move);
void releaseMem(char** matrix, int& size);
#endif // !OXFUN

