#include <iostream>
#include <cmath>
#include <set>
std::set<int> a; 
void f(int n, int r) {
    if (r == 0) {
        a.insert(n);
        return;
    }
    f(n - 5, r - 1);
    f(n + 2, r - 1);
    f(pow(n, 2), r - 1);
}
int main() {
    int start = 3; 
    int commands = 7;
    f(start, commands);
    std::cout << a.size() << std::endl;
    return 0;
}
