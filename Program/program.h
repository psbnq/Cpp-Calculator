#pragma once

#include "keyboardinput.h"
#include "calculation.h"
#include "function.h"
#include "board.h"
#include <Windows.h>

void PROGRAM_RUN() {
  system("mode con cols=44 lines=30 | title Calculator");
  while (1) {
    if (GetAsyncKeyState(VK_ESCAPE)) { // press ESC keyboard to terminate program
      return;
    }
    keyboardinput();
    movePointer(x, y);
    printBoard();
    gotoxy(x, y);
    printf("¢¡");
    Sleep(15);
    system("cls");
  }
}
