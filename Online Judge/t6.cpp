#include<bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

long max_index(vector<long>& data, long i, long j){
	long index;
	long temp = 0;
	for(long k = i; k < j; k++){
		if(data[k] > temp){
			temp = data[k];
			index = k;
		}
	}
	return index;
}
int main()
{
	long n, w;
	vector<long> data;
	long temp = 0;
	cin >> n >> w;
	for(long i = 0; i < w ; i++){
		cin >> temp;
		data.push_back(temp);
	}
	long max_index_temp = max_index(data, 0, w);
	cout << data[max_index_temp] << " ";
	for(long j = 1; j < n - w + 1; j++){
		cin >> temp;
		data.push_back(temp);
		if(max_index_temp < j){
			max_index_temp = max_index(data, j, j + w);
		}
		else if(temp > data[max_index_temp]){
			max_index_temp = j + w - 1;
		}
		cout << data[max_index_temp] << " ";
	}
	return 0;
}
