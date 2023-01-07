#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int maxn = pow(2, n);
	vector<int> Tree(maxn);
	for (int i = 1; i < maxn; i++) {
		cin >> Tree[i];
	}
	int i = 1;
	cout << Tree[1];
	while (i * 2 + 1 < maxn) {
		while (Tree[i * 2] == -1 && Tree[i * 2 + 1] == -1) i--;
		if (Tree[i * 2 + 1] != -1) i = i * 2 + 1;
		else i = i * 2;
		cout << " " << Tree[i];
	}
	return 0;
}
