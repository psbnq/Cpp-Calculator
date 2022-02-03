#pragma once
#include "board.h"
#include <vector>

void calculate() {
	if (calcTempPrintMode) {
		calcTempPrintMode = false;
	}
	if (calcTemp.size() == 0) {
		return;
	}
	if (calcTemp[0] == '-') {
		calcTemp = '0' + calcTemp;
	}
	string exp[MAXLEN*2];
	string voexp;
	string numTemp;
	stack<string> op;
	int idx = 0;
	int lCnt = 0, rCnt = 0;
	for (int i = 0; i < calcTemp.size(); i++) {
		if (isNum(calcTemp[i])) {
			numTemp += calcTemp[i];
			if (i == calcTemp.size() - 1 && numTemp != "") {
				exp[idx++] = numTemp;
				voexp += 'v';
			}
		}
		else {
			if (numTemp != "") {
				exp[idx++] = numTemp;
				voexp += 'v';
				numTemp = "";
			}
			if (calcTemp[i] == '(') {
				lCnt++;
				op.push(ctos(calcTemp[i]));
				voexp += '(';
			}
			else if (calcTemp[i] == '*' || calcTemp[i] == '/') {
				voexp += 'o';
				while (!op.empty() && (op.top() == "*" || op.top() == "/")) {
					exp[idx++] = op.top();
					op.pop();
				}
				op.push(ctos(calcTemp[i]));
			}
			else if (calcTemp[i] == '+' || calcTemp[i] == '-') {
				voexp += 'o';
				while (!op.empty() && op.top() != "(") {
					exp[idx++] = op.top();
					op.pop();
				}
				op.push(ctos(calcTemp[i]));
			}
			else if (calcTemp[i] == ')') {
				rCnt++;
				voexp += ')';
				while (!op.empty() && op.top() != "(") {
					exp[idx++] = op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	if (rCnt != lCnt) {
		input_error();
		return;
	}
	int len = calcTemp.size() - 1;
	while (len--) {
		for (int i = 0; i < voexp.size(); i++) {
			if (i + 2 < voexp.size()) {
				if (voexp[i] == 'v' && voexp[i + 1] == 'o' && voexp[i + 2] == 'v') {
					string temp;
					for (int j = 0; j < i; j++) {
						temp += voexp[j];
					}
					temp += 'v';
					for (int j = i + 3; j < voexp.size(); j++) {
						temp += voexp[j];
					}
					voexp = temp;
				}
				else if (voexp[i] == '(' && voexp[i] == 'v' && voexp[i] == ')') {
					string temp;
					for (int j = 0; j < i; j++) {
						temp += voexp[i];
					}
					temp += 'v';
					for (int j = i + 3; j < voexp.size(); j++) {
						temp += voexp[i];
					}
					voexp = temp;
				}
			}
		}
	}
	if (!(voexp.size() == 1 && voexp[0] == 'v')) {
		input_error();
		return;
	}
	while (!op.empty()) {
		exp[idx++] = op.top();
		op.pop();
	}
	stack<double> value;
	for (int i = 0; i < idx; i++) {
		if (isNum(exp[i])) {
			value.push(stod(exp[i]));
		}
		else {
			if (value.size() < 2) {
				input_error();
				return;
			}
			double back = value.top(); value.pop();
			double front = value.top(); value.pop();
			if (exp[i] == "+") {
				value.push(front + back);
			}
			else if (exp[i] == "-") {
				value.push(front - back);
			}
			else if (exp[i] == "*") {
				value.push(front * back);
			}
			else {
				if (back == 0) {
					input_error();
					return;
				}
				value.push(front / back);
			}
		}
	}
	if (value.size() >= 2 || value.empty()) {
		input_error();
		return;
	}
	res = value.top();
	clear_flag = true;
}