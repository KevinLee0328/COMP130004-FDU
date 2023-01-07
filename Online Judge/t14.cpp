#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct value {
	int left;
	int right;
	bool used = false;
};

int main()
{
	int n = 0;
	cin >> n;
	int maxn = pow(2, int(log(n) / log(2)) + 1);
	vector<int> tree(maxn, -1);
	cin >> tree[1];
	vector<value> value(n);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> value[i].left >> value[i].right;
	}
	for (int i = 1; i < maxn / 2; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (value[j].left == tree[i] && !value[j].used)
			{
				tree[2 * i] = value[j].right;
				value[j].used = true;
			}
			if (value[j].right == tree[i] && !value[j].used)
			{
				tree[2 * i + 1] = value[j].left;
				value[j].used = true;
			}
		}
	}
	int max = 0;
	for (int i = 1; i < maxn; i++) {
		if (tree[i] != -1) max = i;
	}
	for (int i = 1; i <= max; i++) {
		if (tree[i] == -1) {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}