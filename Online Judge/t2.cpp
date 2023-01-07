#include <iostream>
#include <algorithm>
int sum(int* x, int n) {
	int total = 0;
	for(int i = 0; i < n; i++){
		total += *(x + i);
	}
	return total;
}
int main()
{
	int n, t;
	int a[1000], b[1000];
	std::cin >> n >> t;
	for(int i = 0; i < n ; i++){
		std::cin >> a[i];
	}
	for(int i = 0; i < n ; i++){
		std::cin >> b[i];
	}
	bool flag = false;
	int i;
	for(i = 2 * n; i > 0; i--){
		for(int j = std::max(i - n, 0); j <= std::min(n, i); j++){
			if(sum(a, j) + sum(b, i - j) <= t){
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	std::cout << i;
	return 0;
} 
