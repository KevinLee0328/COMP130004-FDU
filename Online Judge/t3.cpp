#include<iostream>

int main()
{
	int m, n;
	int a[100], b[100];
	std::cin >> m >> n;
	for(int i = 0; i < m ; i++){
		std::cin >> a[i];
	}
	for(int i = 0; i < n ; i++){
		std::cin >> b[i];
	}
	int i = 0, j = 0;
	while(i < m && j < n){
		if(a[i] < b[j]) std::cout << a[i++] << " ";
		else std::cout << b[j++] << " ";
	}
	while(i < m){
		std::cout << a[i++] << " ";
	}
	while(j < n){
		std::cout << b[j++] << " ";
	}
}
