#include <iostream>
using namespace std;

int fibonacci(int n) {
    int dp[n + 1];
    dp[0] = 0;
    if (n > 0) {
        dp[1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;
    
    if (n < 0) {
        cout << "n harus bilangan non-negatif!" << endl;
    } else {
        cout << "Fibonacci ke-" << n << " adalah: " << fibonacci(n) << endl;
    }

    return 0;
}
