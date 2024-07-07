#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    ifstream f("26_2149.txt");
    f >> N;
    int k=0, n=0, z=N;
    vector<int> p;
    for(int i=0; i<N; ++i){
        f >> p[i];
    }
    sort(p.rbegin(), p.rend());
    
    for(int i=0; i<N; i++){
        if(z==i){break;}
        else{
            k += p[i];
            while((z>i) || (k<n)){
            n+=p[z];
            z--;
        }}

    }
    cout << z << " "<<N-z;
    
}