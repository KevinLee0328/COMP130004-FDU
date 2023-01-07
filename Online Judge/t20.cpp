#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];
    double speed = 0;
    while (1) {
        speed += 0.001;
        double time = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            time += s[i] / speed;
            if (time < x[i]) time = x[i];
            if (time > y[i]) {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }
    printf("%.2lf", speed);
    return 0;
}