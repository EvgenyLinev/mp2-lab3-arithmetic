// реализация функций и классов для вычисления арифметических выражений
#include "..\include\arithmetic.h"
#include <cstdlib>
#include <cmath>

bool PolishHelp(string& m, string& stack)
{
	if ((m == ")") && ((stack == "(") || (stack == ")") || (stack == "-") || (stack == "+") || (stack == "*") || (stack == "/") || (stack == "~")))
		return true;
	else
		if ((m == "(") && ((stack == "(") || (stack == "-") || (stack == "+") || (stack == "*") || (stack == "/") || (stack == "~")))
			return true;
		else
			if (((m == "+") || (m == "-")) && ((stack == "-") || (stack == "+") || (stack == "*") || (stack == "/") || (stack == "~")))
				return true;
			else
				if (((m == "*") || (m == "/")) && ((stack == "*") || (stack == "/") || (stack == "~")))
					return true;
				else
					if ((m == "~") && (stack == "~"))
						return true;
					else
						return false;
}

string DeleteSpaces(string s)
{
	string str("");
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ')
		{
			str = str + s[i];
		}
	return str;
}

bool exam(string& s)
{
	int j = 0;
	int t = 0;
	int open = 0;
	int close = 0;
	int n = s.length();
	for (int i = 0; i < n - 1; i++)
	{
		j = i;
		switch (s[i])
		{
		case 'x':
			if ((s[i + 1] == '0') || (s[i + 1] == '1') || (s[i + 1] == '2'))
				continue;
			else
				return false;
		case'.':
			if (i == 0)
				return false;
			else
				if ((s[i + 1] <= '9') && (s[i + 1] >= '0'))
				{
					t = 1;
					continue;
				}
				else
					return false;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if ((t == 1) && (s[i + 1] == '.'))
				return false;
			else
				if ((s[i + 1] == '.') || ((s[i + 1] <= '9') && (s[i + 1] >= '0')) && ( (i==0) || (s[i - 1] != 'x')))
					continue;
				else
					if ((s[i + 1] == '+') || (s[i + 1] == '-') || (s[i + 1] == '/') || (s[i + 1] == '*') || (s[i + 1] == ')'))
					{
						t = 0;
						continue;
					}
					else
						return false;
		case '+':
		case '/':
		case'*':
			if (i == 0)
				return false;
			else
				if ((s[i + 1] == '(') || (s[i + 1] == 'x') || ((s[i + 1] <= '9') && (s[i + 1] >= '0')))
					continue;
				else
					return false;

		case '-':
			if ((s[i + 1] == '(') || (s[i + 1] == 'x') || ((s[i + 1] <= '9') && (s[i + 1] >= '0')))
				continue;
			else
				return false;
		case '(':

			if ((s[i + 1] == '(') || (s[i + 1] == 'x') || (s[i + 1] == '-') || ((s[i + 1] <= '9') && (s[i + 1] >= '0')))
			{
				open++;
				continue;
			}
			else
				return false;
		case ')':
		{
			if (i == 0)
				return false;
			else
				if ((s[i + 1] == ')') || (s[i + 1] == '+') || (s[i + 1] == '-') || (s[i + 1] == '*') || (s[i + 1] == '/'))
				{
					close++;
					continue;
				}
				else
					return false;
			if (close > open)
				return false;
		}
		default:
			return false;
		}

	}
	if (s[j + 1] == '(' || s[j + 1] == '+' || s[j + 1] == '-' || s[j + 1] == '/' || s[j + 1] == '*')
		return false;
	if (s[j + 1] == ')')
		close++;
	if (close != open)
		return false;
	else
		return true;
}

vector <string> start(string s)
{
	int i = 0, j = 0;
	string y[3] = {"", "", ""};
	bool f[3] = {false, false, false};
	vector <string> m(0);
	while (i < s.length())
	{
		if ((s[i] >= '0' && s[i] <= '9'))
		{
			string str("");
			while ((s[i] >= '0' && s[i] <= '9'))
			{
				str = str + s[i];
				i++;
			}
			if (s[i]=='.')
			{
				str = str + s[i];
				i++;
				while ((s[i] >= '0' && s[i] <= '9'))
				{
					str = str + s[i];
					i++;
				}				
			}
			m.push_back(str);
			if (i == s.length())
				break;
		}
		switch (s[i])
		{
		case 'x':
		{
			i++;
			switch (s[i])
			{
			case '0':
			case'1':
			case'2':
				if (f[s[i]-'0'] == false)
				{
					f[(s[i] - '0')]=true;
					cout << "Please, enter x"<< s[i]<< endl;
					cin >> y[s[i] - '0'];
					int k = 0;
					while (k < y[s[i] - '0'].size())
					{
						if (((y[s[i] - '0'][k] >= '0') && (y[s[i] - '0'][k] <= '9')) || (y[s[i] - '0'][k] == '.'))
						{
							k++;
							continue;
						}
						else
							throw "incorrect expression during input x";
					}
				}
				m.push_back(y[s[i]-'0']);
				i++;
				break;
			}	
			break;
		}
		case '+':
		{
			m.push_back("+");
			i++;
			break;
		}
		case '*':
		{
			m.push_back("*");
			i++;
			break;
		}
		case '/':
		{
			m.push_back("/");
			i++;
			break;
		}
		case '(':
		{
			m.push_back("(");
			i++;
			break;
		}
		case ')':
		{
			m.push_back(")");
			i++;
			break;
		}
		case '-':
		{
			if (i == 0)
			{
				m.push_back("~");
				i++;
				break;
			}
			if (s[i-1]=='(')
			{
				m.push_back("~");
				i++;
				break;
			}
			m.push_back("-");
			i++;
			break;
		}
		default:
			throw "incorrect expression";		
		}
	}
	return (m);

}

double Polish (vector <string>& m)
{
	vector <string> pol(0);
	TStack <string> stack1(m.size());
	for (int i = 0; i < m.size(); i++)
	{
		if ((m[i] != "+") && (m[i] != "-") && (m[i] != "/") && (m[i] != "*") && (m[i] != "(") && (m[i] != ")") && (m[i] != "~"))
		{
			pol.push_back(m[i]);
		}
		else if (m[i] == "(")
			stack1.push(m[i]);
		else if (stack1.IsEmpty())
			stack1.push(m[i]);
		else
		{
			while (!(stack1.IsEmpty()) && (PolishHelp(m[i],stack1.peek())))
			{
				if (stack1.peek() == "(")
					{
						stack1.pop();
						break;
					}
					pol.push_back(stack1.pop());
				}
				if (m[i] != ")")
					stack1.push(m[i]);
		}
	}
	while (!stack1.IsEmpty())
		pol.push_back(stack1.pop());
	for (int i = 0; i < pol.size(); i++)
		cout << pol[i];
	cout << endl;

	TStack <string> stack2(m.size());
	double l, r, up;
	string res;
	for (int i = 0; i < pol.size(); i++)
	{
		if ((pol[i] != "+") && (pol[i] != "-") && (pol[i] != "/") && (pol[i] != "*") &&  (pol[i] != "~"))
		{
			stack2.push(pol[i]);
			continue;
		}
		if (pol[i] == "~")
		{
			up = atof((stack2.pop()).c_str());
			up = -up;
			res = to_string(up);
			stack2.push(res);
			continue;
		}
		if (pol[i] == "+")
		{
			r = atof((stack2.pop()).c_str());
			l = atof((stack2.pop()).c_str());
			up = l + r;
			res = to_string(up);
			stack2.push(res);
			continue;
		}
		if (pol[i] == "-")
		{
			r = atof((stack2.pop()).c_str());
			l= atof((stack2.pop()).c_str());
			up = l - r;
			res = to_string(up);
			stack2.push(res);
			continue;
		}
		if (pol[i] == "/")
		{
			r = atof((stack2.pop()).c_str());
			l = atof((stack2.pop()).c_str());
			up = l/r;
			res = to_string(up);
			stack2.push(res);
			continue;
		}
		if (pol[i] == "*")
		{
			r = atof((stack2.pop()).c_str());
			l = atof((stack2.pop()).c_str());
			up = l * r;
			res = to_string(up);
			stack2.push(res);
			continue;
		}
	}
	double result = atof((stack2.pop()).c_str());

		//return res(pol, pol.size());
	return(result);
}
