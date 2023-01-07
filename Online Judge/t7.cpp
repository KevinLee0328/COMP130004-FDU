#include <iostream>
#include <string>

using namespace std;

bool comp(string& s, string& source, int index) {
	for (int i = 0; i < source.size(); i++) {
		if (s[index + i] != source[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	string s;
	int n;
	cin >> s >> n;
	int s_len = s.size();
	int index[1000];
	string source[1000], target[1000];
	for (int i = 0; i < n; i++) {
		cin >> index[i] >> source[i] >> target[i];
	}
	int index_index[10000];
	for (int i = 0; i < s_len; i++) {
		index_index[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		index_index[index[i]] = i;
	}
	char new_s[10000];
	int j = 0;
	for (int i = 0; i < s_len; i++) {
		if (index_index[i] != -1) {
			if (comp(s, source[index_index[i]], i)) {
				for (int k = 0; k < target[index_index[i]].size(); k++) {
					new_s[j++] = target[index_index[i]][k];
				}
				i += source[index_index[i]].size() - 1;
				continue;
			}
		}
		new_s[j++] = s[i];
	}
	for (int i = 0; i < j; i++) {
		cout << new_s[i];
	}
}