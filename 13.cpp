#include <iostream>
#include <vector>

int main() {
    int n,i; std::cin >> n;
    std::vector <int> a(n + 1);
    a[0] = 0; a[1] = 0; a[2] = 0; a[3]=1;
    for(int i = 4; i <= 20; ++i){
        a[i] = a[i - 1];
        if(i % 2 == 0){
            a[i] = a[i] + a[i/2];
        }
        a[12] = 0;
    }
    
    for(int i = 3; i < 20; i++){
        a[i] = 0;}
    for(int i = 21; i < a.size(); i++)
        a[i] = a[i - 1];
        if(i % 2 == 0){
            a[i] = a[i] + a[i/2];
        }
    std::cout << a[n];
    return 0;
}