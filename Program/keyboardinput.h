#pragma once
#include "board.h"
#include "calculation.h"

void init() {
	if (!calcTempPrintMode) {
		calcTempPrintMode = true;
	}
	if (calcTemp == "INVALID INPUT" || clear_flag) {
		calcTemp = "";
		clear_flag = false;
	}
}

void input(char c) {
	if (calcTemp.size() > MAXLEN) {
		cout << "EXCEED CALCULATION LENGTH";
		return;
	}
	calcTemp += c;
}

void keyboardinput() {
	if (GetAsyncKeyState(VK_BACK) & 0x001) {
		init();
		Delete();
	}
	if (GetAsyncKeyState(VK_CLEAR) & 0x001) {
		init();
		Clear();
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x001) {
		init();
		calculate();
	}
	if (GetAsyncKeyState(0x30) & 0x001) {
		init();
		input('0');
	}
	if (GetAsyncKeyState(0x31) & 0x001) {
		init();
		input('1');
	}
	if (GetAsyncKeyState(0x32) & 0x001) {
		init();
		input('2');
	}
	if (GetAsyncKeyState(0x33) & 0x001) {
		init();
		input('3');
	}
	if (GetAsyncKeyState(0x34) & 0x001) {
		init();
		input('4');
	}
	if (GetAsyncKeyState(0x35) & 0x001) {
		init();
		input('5');
	}
	if (GetAsyncKeyState(0x36) & 0x001) {
		init();
		input('6');
	}
	if (GetAsyncKeyState(0x37) & 0x001) {
		init();
		input('7');
	}
	if (GetAsyncKeyState(0x38) & 0x001) {
		init();
		input('8');
	}
	if (GetAsyncKeyState(0x39) & 0x001) {
		init();
		input('9');
	}
	if (GetAsyncKeyState(0x50) & 0x001) {
		init();
		input('.');
	}
	if (GetAsyncKeyState(0x44) & 0x001) { // d : divide
		init();
		input('/');
	}
	if (GetAsyncKeyState(0x4D) & 0x001) {
		init();
		input('*');
	}
	if (GetAsyncKeyState(0x53) & 0x001) {
		init();
		input('-');
	}
	if (GetAsyncKeyState(0x41) & 0x001) {
		init();
		input('+');
	}
	if (GetAsyncKeyState(0x41) & 0x001) {
		init();
		input('+');
	}
	if (GetAsyncKeyState(0x41) & 0x001) {
		init();
		input('+');
	}
	if (GetAsyncKeyState(219) & 0x001) {
		init();
		input('(');
	}
	if (GetAsyncKeyState(221) & 0x001) {
		init();
		input(')');
	}
}