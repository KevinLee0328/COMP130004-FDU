#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long number(vector<int>& tree, int n)
{
	long long sum = 0;
	long long pown = 1;
	while (n > 0) {
		sum += tree[n] * pown;
		n /= 2;
		pown *= 10;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	int maxn = pow(2, int(log(n) / log(2)) + 1);
	vector<int> tree(maxn, -1);
	for (int i = 1; i <= n; i++) cin >> tree[i];
	int i = maxn / 2;
	bool flag = true;
	long long xiaowu = 0, xiaoming = 0;
	do {
		if (flag) xiaowu += number(tree, i);
		else xiaoming += number(tree, i);
		flag = !flag;
		if (i == n) i = i / 2 + 1;
		else i++;
	} while (i != maxn / 2);
	if (xiaowu >= xiaoming) cout << 0;
	else cout << 1;
}