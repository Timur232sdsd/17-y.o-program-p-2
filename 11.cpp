#include <iostream>
#include <string>
#include <unordered_map>

int main(){
    
    int a[33]; a[0] = 0; a[1] = 1; 
    for(int i = 2; i < 33; ++i){
        a[i] = a[i - 1];
        if(i % 4 == 0)
            a[i] = a[i] + a[i/4]; 
    }
    std::cout<<a[32];}
