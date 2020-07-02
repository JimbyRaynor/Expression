// Expression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


string digits = "0123456789";

string BODMAS(string subexp)
{
	int i,minj,maxj;
	string buildstr;
	string test;
	while (subexp.find("*") != string::npos)
	{
		buildstr = "";
		int leftnum, rightnum;
		i = subexp.find("*");
		minj = i-1;
		do
		{
			if (digits.find(subexp[minj]) == string::npos)
			{
				break;
			}
			minj = minj - 1;
		} while (minj >= 0);
		if (minj < 0) { minj = 0; }
		//cout << "j="<<j << "  j-i+1=" << i-j << "\n";
		leftnum =  stoi(subexp.substr(minj, i - minj));
		maxj = i + 1;
		do
		{
			if (digits.find(subexp[maxj]) == string::npos)
			{
				break;
			}
			maxj = maxj + 1;
		} while (maxj <= subexp.length() -1 );
		rightnum = stoi(subexp.substr(i+1, maxj-i));
		if (minj > 0) 
		{
			buildstr = subexp.substr(0,minj+1);
		}
		buildstr = buildstr + to_string(leftnum * rightnum);
		if (maxj < subexp.length() - 1)
		{
			buildstr = buildstr + subexp.substr(maxj, subexp.length() - maxj);
		}
		subexp =  buildstr;
		cout << buildstr << "   press c <enter> to continue" ;
		cin >> test;
	}
	return subexp;
}

int main()
{
	string Expr;
	Expr = "2*3*5+7*3+7*2*3";
    cout << "exp = " << BODMAS(Expr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
