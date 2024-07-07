#include <iostream>
#include <vector>
int count_odd_divisors(int n) {
    int odd_divisors = 1;
    for (int i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt % 2 == 1) {
            odd_divisors *= i;
        }
    }
    if (n > 1) {
        odd_divisors *= n;
    }
    return odd_divisors;
}
int main() {
    int lower_bound = 105000000;
    int upper_bound = 115000000;
    std::vector<std::pair<int, int>> result;
    for (int num = lower_bound; num <= upper_bound; ++num) {
        if (count_odd_divisors(num) == 5) {
            result.push_back(std::make_pair(num, count_odd_divisors(num)));
        }
    }
    for (const auto& pair : result) {
        std::cout << "Число: " << pair.first << ", Наибольший нечётный делитель: " << pair.second << std::endl;
    }

    return 0;
}
