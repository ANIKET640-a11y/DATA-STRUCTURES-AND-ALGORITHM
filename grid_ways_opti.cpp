#include <iostream>
using namespace std;

long long factorial(int x) {
    long long ans = 1;
    for (int i = 2; i <= x; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n = 3, m = 3;

    long long totalWays = factorial(n + m - 2) /
                          (factorial(n - 1) * factorial(m - 1));

    cout << totalWays;

    return 0;
}