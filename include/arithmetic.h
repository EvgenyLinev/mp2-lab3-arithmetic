// ���������� ������� � ������� ��� ���������� �������������� ���������
#ifndef __ARITHMETIC_H__

#define __ARITHMETIC_H__

#include <iostream>
#include "stack.h"
#include <string>

double Polish(vector <string>& m); // �������� ������ � ���������� ����������
vector <string> start(string s); // ������� ������ � ������
bool exam(string& s);
string DeleteSpaces(string s); // �������� �������� �� �������� ������
bool PolishHelp(string& m, string& stack);
#endif

