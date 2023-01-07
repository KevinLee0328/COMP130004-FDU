#include<iostream>

int main()
{
	int n;
	std::cin >> n;
	long long fact = 1;
	long long x = 1e9 + 7;
	for(int i = 1; i <= n; i++){
		fact *= i;
		if(fact > x) fact %= x;
	}
	std::cout << fact % x;
	return 0;
}
