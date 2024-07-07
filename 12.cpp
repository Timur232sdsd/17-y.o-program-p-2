#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    ifstream fin("26-j8.txt");
    vector<int> p; int z; long long x; 

    while(fin>>x) {
        fin >> z;
        p.push_back(z);

    }
    for(int i=0; i < p.size(), i++){
        
    }
    sort(p.begin(), p.end());

    return 0;
}