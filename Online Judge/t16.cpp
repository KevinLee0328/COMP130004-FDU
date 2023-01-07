#include <iostream>
#include <vector>
using namespace std;

class UFSets {
private:
	int* parent;
	int size;
public:
	UFSets(int sz) {
		size = sz;
		parent = new int[sz];
		for (int i = 0; i < sz; i++) {
			parent[i] = -1;
		}
	}
	~UFSets() {
		delete[] parent;
	}
	int Find(int x) {
		while (parent[x] >= 0) {
			x = parent[x];
		}
		return x;
	}
	void Union(int root1, int root2) {
		if (root1 == root2) {
			return;
		}
		if (parent[root1] < parent[root2]) {
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}
		else {
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
	}
};

bool allin(UFSets& ufs, int n) {
	for (int i = 1; i <= n; i++) {
		if (ufs.Find(i) != ufs.Find(1)) {
			return false;
		}
	}
	return true;
}

struct line {
	int x, y, t;
};

int main() {
	int n, m;
	cin >> n >> m;
	UFSets ufs(n + 1);
	vector<line> lines;
	for (int i = 0; i < m; i++) {
		line temp;
		cin >> temp.x >> temp.y >> temp.t;
		lines.push_back(temp);
	}
	int maxt = 0;
	int count = 0;
	while (count < m) {
		maxt++;
		for (int i = 0; i < m; i++)
			if (lines[i].t == maxt) {
				ufs.Union(ufs.Find(lines[i].x), ufs.Find(lines[i].y));
				count++;
			}
		if (allin(ufs, n)) break;
	}
	if (!allin(ufs, n)) cout << -1;
	else cout << maxt;
	return 0;
}
