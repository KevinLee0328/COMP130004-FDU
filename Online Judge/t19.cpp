#include <iostream>
#include <vector>
using namespace std;

int time(const vector<int>& z, int m, int k) {
	int t = 0;
	for (int i = 0; i < m; i++) t += (z[i] - 1) / k + 1;
	return t;
}

int main()
{
	int m, h;
	cin >> m >> h;
	vector<int> z(m);
	for (int i = 0; i < m; i++) cin >> z[i];
	int k;
	for (k = 1; time(z, m, k) > h; k++);
	cout << k;
}