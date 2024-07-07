#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int S, N, z = 0, c = 0, x = 0;
    ifstream f("26_813.txt");
    f >> S >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        f >> p[i];
    }
    sort(p.begin(), p.end());

    for(int i=0; i<N; i++){
        z+=p[N-1-i];
        if(z > S){
            x = i*2;
            c = p[i-1];
            break;
        }
        z+=p[i];
        if(z > S){
            x = (i)*2 + 1;
            c = p[N-i-1];
            break;
        }
    }

    cout << x << " " <<c;
    return 0;
}
