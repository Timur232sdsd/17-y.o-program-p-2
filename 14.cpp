#include <iostream>
#include <vector>


int a(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1; 

    for (int i = 2; i <= n; i++) {
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
        
        if (i >= 3) {
            dp[i] += dp[i - 3];
        }
    }

    return dp[n];
}

int main() {
    int n = 4;
    int result = a(n);
    std::cout << result << std::endl;
    return 0;
}
