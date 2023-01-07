#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

void accumulate(bool& rhs_flag, bool& plus_flag, bool& equal_flag, int k[], int pow, int value) {
	if (!equal_flag) {
		if (plus_flag && rhs_flag || (!plus_flag) && (!rhs_flag)) k[pow] -= value;
		else k[pow] += value;
	}
	equal_flag = false;
}

int main()
{
	string equation;
	cin >> equation;
	bool rhs_flag = false;
	bool plus_flag = true;
	bool equal_flag = false;
	int pow = 0;
	int value = 0;
	int k[3] = { 0,0,0 };
	for (int i = 0; i < equation.length(); i++) {
		if (equation[i] == '=') {
			accumulate(rhs_flag, plus_flag, equal_flag, k, pow, value);
			rhs_flag = true;
			equal_flag = true;
		}
		else if (equation[i] == '+') {
			accumulate(rhs_flag, plus_flag, equal_flag, k, pow, value);
			plus_flag = true;
			pow = 0;
		}
		else if (equation[i] == '-') {
			accumulate(rhs_flag, plus_flag, equal_flag, k, pow, value);
			plus_flag = false;
			pow = 0;
		}
		else if (equation[i] == 'x') {
			pow = 1;
		}
		else if (equation[i] == '^') {
			pow = 2;
			i++;
		}
		else {
			value = equation[i] - '0';
		}
	}
	accumulate(rhs_flag, plus_flag, equal_flag, k, pow, value);
	int delta = k[1] * k[1] - 4 * k[0] * k[2];
	double answer = 0;
	if (k[2] == 0) {
		answer = -(double)k[0] / k[1];
		printf("%.2lf\n", answer);
	}
	else if (delta < 0) {
		cout << "No solution" << endl;
	}
	else if (delta == 0) {
		answer = -(double)k[1] / (2 * k[2]);
		printf("%.2lf\n", answer);
	}
	else {
		answer = (-k[1] - sqrt(delta)) / (2 * k[2]);
		printf("%.2lf\n", answer);
		answer = (-k[1] + sqrt(delta)) / (2 * k[2]);
		printf("%.2lf\n", answer);
	}
	return 0;
}