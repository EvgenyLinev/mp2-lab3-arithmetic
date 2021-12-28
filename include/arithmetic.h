// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#ifndef __ARITHMETIC_H__

#define __ARITHMETIC_H__

#include <iostream>
#include "stack.h"
#include <string>

double Polish(vector <string>& m); // польска€ запись и вычисление результата
vector <string> start(string s); // перенос строки в массив
bool exam(string& s);
string DeleteSpaces(string s); // ”даление пробелов из исходной строки
bool PolishHelp(string& m, string& stack);
#endif

