#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int countPrograms(int n) {
    if (n == 2) {
        return 1;
    }

    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int result = countPrograms(n - 1) + countPrograms(n - 3);
    if (n % 2 == 0) {
        result += countPrograms(n / 2);
    }

    memo[n] = result;
    return result;
}

int main() {
    const int target = 20;

    int result = countPrograms(target);

    std::cout << "Количество программ: " << result << std::endl;

    return 0;
}
