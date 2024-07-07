#include <iostream>
#include <string>
#include <unordered_map>



int main(){
    int a[27]; 
    for(int i = 0; i < 2; i++ ) a[i] = 0; a[2] = 1;
    for(int i = 3; i <= 15; ++i){
        a[i] = a[i - 1];
        if(i>5){a[i] = a[i] + a[i - 5]; 
        }
        a[10] = 0;
    }
    for(int i = 2; i < 15; ++i){
        a[i] = 0;
    }
    for(int i = 16; i < 27; ++i){
        a[i] = a[i - 1] + a[i - 5]; 
    }
    std::cout<<a[26];
}