#include <iostream>
#include <algorithm>
struct Node{
	int x;
	bool valid;
};
int main()
{
	int m, n;
	Node a[100], b[100];
	int c[100];
	std::cin >> m >> n;
	for(int i = 0; i < m ; i++){
		std::cin >> a[i].x;
		a[i].valid = true;
	}
	for(int i = 0; i < n ; i++){
		std::cin >> b[i].x;
		b[i].valid = true;
	}
	int t = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i].x == b[j].x && b[j].valid){
				c[t++] = a[i].x;
				b[j].valid = false; 
			}
		}
	}
	std::sort(c, c + t);
	for(int i = 0; i < t; i++){
		std::cout << c[i] << " " ;
	}
	return 0;
} 
