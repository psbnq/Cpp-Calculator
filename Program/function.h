#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

extern int x, y;

bool path(int x1, int x2, int y1, int y2) { // x1 < x < x2 && y1 < y < y2
  if (x1 < x && x < x2 && y1 < y && y < y2) return true;
  return false;
}

bool isNum(char c) {
  if ((c >= '0' && c <= '9') || c == '.')	return true;
  return false;
}

bool isNum(string& s) {
  for (int i = 0; i < s.size(); i++) {
    if (!isNum(s[i])) {
      return false;
    }
    if (s[i] == '.') {
      if (i == 0 || i == s.size() - 1 || !isNum(s[i - 1]) || !isNum(s[i + 1])) {
        return false;
      }
    }
  }
  return true;
}

bool include_operation(string& s) {
  for (auto x : s) {
    if (!isNum(x)) return true;
  }
  return false;
}

string ctos(char c) {
  string temp;
  temp += c;
  return temp;
}


double stod(string& s) {
  string temp1, temp2;
  bool point = false;
  int idx = 0, expCnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      idx = i;
      point = true;
      break;
    }
  } // 123.456
  if (point) {
    expCnt = s.size() - idx - 1;
    for (int i = 0; i < s.size(); i++) {
      if (i < idx)	temp1 += s[i]; // integer part
      else if (i == idx)	continue;
      else temp2 += s[i]; // decimal part
    }
    long long num = stoll(temp1);
    for (int i = 0; i < expCnt; i++) {
      num = num * 10 + temp2[i] - '0';
    }
    double res = (double)num;
    while (expCnt--) {
      res /= 10;
    }
    return res;
  }
  return stoll(s);
}
