#include<bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

int max(int* array, int w){
	int temp = 0;
	for(int i = 0; i < w; i++){
		if(*(array + i) > temp) temp = *(array + i);
	}
	return temp;
}

int main()
{
	int n,w;
	int a[1000];
	cin >> n >> w;
	for(int i = 0; i < n ; i++){
		cin >> a[i];
	}
	for(int j = 0; j < n - w + 1; j++){
		cout << max(a + j, w) << " ";
	}
	return 0;
}
