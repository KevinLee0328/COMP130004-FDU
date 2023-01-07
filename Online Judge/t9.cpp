#include <iostream>
#include <vector>
using namespace std;

void GetNext(vector<int>& next, const vector<int>& xiaowu)
{
	long i = 0, j = -1;
	next[0] = -1;
	while (i < xiaowu.size()) {
		if (j == -1 || xiaowu[i] == xiaowu[j]) {
			i++; j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

int FastFind(const vector<int>& xiaomin, const vector<int>& xiaowu, const vector<int>& next)
{
	long i = 0, j = 0;
	while (i < xiaomin.size() && j < xiaowu.size()) {
		if (j == -1 || xiaomin[i] == xiaowu[j]) {
			i++; j++;
		}
		else if (j == 0) {
			i++;
		}
		else {
			j = next[j];
		}
	}
	if (j < xiaowu.size()) {
		return -1;
	}
	else {
		return i - j + 1;
	}
}

int main()
{
	long m, n;
	int temp;
	cin >> n >> m;
	vector<int> xiaomin, xiaowu;
	for (long i = 0; i < n; i++) {
		cin >> temp;
		xiaomin.push_back(temp);
	}
	for (long i = 0; i < m; i++) {
		cin >> temp;
		xiaowu.push_back(temp);
	}
	vector<int> next(m + 1);
	GetNext(next, xiaowu);
	cout << FastFind(xiaomin, xiaowu, next);
	return 0;
}