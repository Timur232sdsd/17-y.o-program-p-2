#include <iostream>
#include <vector>
#include <algorithm>
bool c(int n, int m, const std::string& s) {
    std::vector<int> f(26, 0);
    for (char ch : s) {
        f[ch - 'a']++;
    }
    int oddCount = 0;
    for (int freq : f) {
        if (freq % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount <= m;
}
int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m;
        std::cin >> n >> m;

        std::string s;
        std::cin >> s;

        bool result = c(n, m, s);

        if (result) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
    }
    return 0;
}


