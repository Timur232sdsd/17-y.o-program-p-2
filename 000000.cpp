#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> f(int x) {
    int s = std::trunc(std::sqrt(std::sqrt(x)));
    std::vector<bool> a(s + 1, true);
    a[1] = false;
    std::vector<int> sols;
    for (int i = 2; i <= s; ++i) {
        if (a[i]) {
            sols.push_back(i);
            int j = i + i;
            while (j <= s) {
                a[j] = false;
                j += i;
            }
        }
    }
    return sols;
}
int main() {
    std::vector<int> a = f(115000000);
    for (int i = 0; i < a.size(); ++i) {
        int p = a[i];
        int n = p * p * p * p;
        while (n < 105000000) {n *= 2;}if (n <= 115000000) {std::cout << n << " " << p*p*p*p;}
    }
    return 0;
}
