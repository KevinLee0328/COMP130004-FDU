#include <iostream>
#include <queue>
using namespace std;

struct child {
	int num;
	int times;
};
int main() {
	queue<child> q;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		child c;
		cin >> c.num;
		c.times = 0;
		q.push(c);
	}
	while (1) {
		child tmp;
		child f = q.front();
		q.pop();
		if (f.num > q.front().num) {
			tmp = q.front();
			q.front() = f;
			q.front().times++;
			tmp.times = 0;
			q.push(tmp);
		}
		else {
			q.push(f);
			q.front().times++;
		}
		if (q.front().times >= k) {
			break;
		}
	}
	cout << q.front().num;
}
