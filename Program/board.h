#pragma once
#include <iostream>
#include <windows.h>
#include "function.h"

using namespace std;

const int COL = 44;
const int ROW = 32;
// ROW ▼ COL display

extern void calculate(); // calculate.h
extern bool path(int x1, int x2, int y1, int y2); // function.h

const int MAXLEN = 33;
// All letters must be less than 33 characters, including operations

string calcTemp;
bool clear_flag = false;
bool calcTempPrintMode = true;

int x = 1;
int y = 1;
// cursor position (x, y)
int X[8] = { 1, 9, 11, 19, 21, 29, 31, 39 };
int Y[12] = { 12, 14, 15, 17, 18, 20, 21, 23, 24, 26, 27, 29 };
// Mark the bounds of a rectangular area (X[], Y[])

double res = 0;


void gotoxy(int x, int y) { // Move the cursor to (x, y)
  COORD Pos = { x, y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Clear() { // function is executed when the clear button is pressed.
  calcTemp = "";
}

void outputPrint(bool print_mode, double res) {
  gotoxy(5, 8);
  if (print_mode) cout << calcTemp; // print_mode = 1:calc, 0:res
  else cout << res;
}

void printBoard() {
  cout << "\n\n";
  printf("%28s", "Calculator\n\n");
  printf("%43s", "made by psbnq\n\n");
  cout << "  " << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
  cout << "  " << "弛                                     弛\n";
  cout << "  " << "弛                                     弛\n";
  cout << "  " << "弛                                     弛\n";
  cout << "  " << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n";
  cout << "  " << "忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖\n";
  cout << "  " << "弛   (   弛 弛   )   弛 弛   .   弛 弛 CLEAR 弛\n";
  cout << "  " << "戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎\n";
  cout << "  " << "忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖\n";
  cout << "  " << "弛   7   弛 弛   8   弛 弛   9   弛 弛  DEL  弛\n";
  cout << "  " << "戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎\n";
  cout << "  " << "忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖\n";
  cout << "  " << "弛   4   弛 弛   5   弛 弛   6   弛 弛   /   弛\n";
  cout << "  " << "戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎\n";
  cout << "  " << "忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖\n";
  cout << "  " << "弛   1   弛 弛   2   弛 弛   3   弛 弛   *   弛\n";
  cout << "  " << "戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎\n";
  cout << "  " << "忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖 忙式式式式式式式忖\n";
  cout << "  " << "弛   -   弛 弛   0   弛 弛   +   弛 弛   =   弛\n";
  cout << "  " << "戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎 戌式式式式式式式戎\n\n";
  cout << "  " << " 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n";
  outputPrint(calcTempPrintMode, res);
}

void pressNum(int num) {
  calcTemp += '0' + num;
}

void Delete() {
  string ret;
  for (int i = 0; i < (int)calcTemp.size() - 1; i++) {
    ret += calcTemp[i];
  }
  calcTemp = ret;
}

void input_error() {
  clear_flag = true;
  calcTempPrintMode = true;
  calcTemp = "INVALID INPUT";
}

void AreaSelect(int& x, int& y) {
  if (!calcTempPrintMode) calcTempPrintMode = true;
  if (clear_flag) {
    clear_flag = false;
    calcTemp = "";
  }
  if (path(X[6], X[7], Y[0], Y[1])) {
    Clear();
  }
  else if (path(X[6], X[7], Y[2], Y[3])) {
    Delete();
  }
  else if (path(X[6], X[7], Y[8], Y[9])) {
    calculate();
  }
  if (calcTemp.size() > MAXLEN) {
    cout << "EXCEED CALCULATION LENGTH";
    return;
  }
  if (path(X[0], X[1], Y[0], Y[1])) {
    calcTemp += '(';
  }
  else if (path(X[2], X[3], Y[0], Y[1])) {
    calcTemp += ')';
  }
  else if (path(X[4], X[5], Y[0], Y[1])) {
    calcTemp += '.';
  }
  else if (path(X[0], X[1], Y[2], Y[3])) {
    pressNum(7);
  }
  else if (path(X[2], X[3], Y[2], Y[3])) {
    pressNum(8);
  }
  else if (path(X[4], X[5], Y[2], Y[3])) {
    pressNum(9);
  }
  else if (path(X[2], X[3], Y[4], Y[5])) {
    pressNum(5);
  }
  else if (path(X[4], X[5], Y[4], Y[5])) {
    pressNum(6);
  }
  else if (path(X[6], X[7], Y[4], Y[5])) {
    calcTemp += '/';
  }
  else if (path(X[0], X[1], Y[6], Y[7])) {
    pressNum(1);
  }
  else if (path(X[2], X[3], Y[6], Y[7])) {
    pressNum(2);
  }
  else if (path(X[4], X[5], Y[6], Y[7])) {
    pressNum(3);
  }
  else if (path(X[6], X[7], Y[6], Y[7])) {
    calcTemp += '*';
  }
  else if (path(X[0], X[1], Y[8], Y[9])) {
    calcTemp += '-';
  }
  else if (path(X[2], X[3], Y[8], Y[9])) {
    pressNum(0);
  }
  else if (path(X[4], X[5], Y[8], Y[9])) {
    calcTemp += '+';
  }
}

void movePointer(int& x, int& y) {
  if (GetAsyncKeyState(VK_LEFT)) { // left
    if (x <= 2)	return;
    x -= 2;
  }
  if (GetAsyncKeyState(VK_RIGHT)) { // right
    if (x >= COL - 3)	return;
    x += 2;
  }
  if (GetAsyncKeyState(VK_UP)) { // up
    if (y <= 0)	return;
    y--;
  }
  if (GetAsyncKeyState(VK_DOWN)) { // down
    if (y >= ROW - 2)	return;
    y++;
  }
  if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
    AreaSelect(x, y);
  }
}

// Gets the arrow key that entered in real time
// by GetAsyncKeyState() function (#include <windows.h>)
// and move the pointer.