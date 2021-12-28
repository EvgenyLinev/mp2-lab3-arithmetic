// реализация пользовательского приложения

#include <..\include\arithmetic.h>

#include <iostream>

using namespace std;

int main()
{
	try
	{
		cout<< "Please, enter math expression" << endl;
		cin >> s;
		s = DeleteSpaces(s);
		switch (exam(s))
		{
		case true: 
			cout << "correct expression" << endl;
			break;
		case false: 
		{
			cout << "incorrect expression";
			return 0;
		}
		}
		vector <string> str = start(s);
		double f = Polish(str);
		cout << "Result = " << f << endl;
		return 0;
	}
	catch (char* error)
	{
		cout<< error<< endl;
	}
}