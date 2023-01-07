#include <iostream>
#include <vector>
using namespace std;

bool check(int n, const vector<int>& max, int m) {
	if (n == m - 1) return true;
	for (int i = 1; i <= max[n] && n + i < m; i++) {
		if (check(n + i, max, m)) return true;
	}
	return false;
}

int main()
{
	int m;
	cin >> m;
	vector<int> max;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		max.push_back(temp);
	}
	cout << check(0, max, m);
	return 0;
}