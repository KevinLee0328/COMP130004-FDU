#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(const stack<int>& s, const vector<int>& value) {
	stack<int> temp1 = s;
	stack<int> temp2;
	while (!temp1.empty()) {
		temp2.push(temp1.top());
		temp1.pop();
	}
	while (!temp2.empty()) {
		cout << value[temp2.top()];
		temp2.pop();
		if(!temp2.empty()) cout << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> value;
	value.push_back(0);
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		value.push_back(temp);
	}
	int target;
	cin >> target;
	stack<int> s;
	int i = 1;
	int sum = 0;
	while (n > 0) {
		while (i <= n) {
			s.push(i);
			sum += value[i];
			i *= 2;
		}
		if (sum == target) {
			print(s, value);
		}
		i = s.top();
		s.pop();
		sum -= value[i];
		if (i == n) {
			i = s.top();
			s.pop();
			sum -= value[i];
		}
		while (i / 2 * 2 != i && !s.empty()) {
			i = s.top();
			s.pop();
			sum -= value[i];
		}
		if (s.empty()) return 0;
		i++;
	}
	return 0;
}
