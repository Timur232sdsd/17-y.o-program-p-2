#include <iostream>
#include <fstream>
#include <vector>
int main() {
    std::ifstream fileA("18-114.txt");
    int a[15][15];
    for(int j = 0; j < 15; ++j)
    for (int i = 0; i < 15; ++i)
     {
        fileA >> a[j][i];
    }
    int i; int j; i = 0; j = 0;
    while(a[i][j] <= 15 && a[i][j] >= 1 || (i <= 15 && j <= 15)){
        if()
    }
        
    
}
