#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int max = 0;
	for (int i = 1; i <= min(s1.size(), s2.size()); i++) {
		string temp1 = s1.substr(s1.size() - i);
		string temp2 = s2.substr(0, i);
		if (temp1 == temp2) max = i;
	}
	string s3 = s1 + s2.substr(max);
	cout << s3;
}