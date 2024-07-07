#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream fin("26-50.txt");
    int n;
    fin >> n;
    vector<int> N(n);
    for (int i = 0; i < n; i++) {
        fin >> N[i];
    }
    sort(N.begin(), N.end());
    vector<int> a;
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((N[i] + N[j]) % 2 == 0 ) {
                int avg = (int)(N[i] + N[j]) / 2;
                a.push_back(avg);
                c++;
            }
        }
    }
    for(int i=0; i < a.size() - 1; ++i){
        for (int j = i + 1; j < n; j++){
            if(N[i] < (N[i] + N[j]) / 2 && N[j] > (N[i] + N[j]) / 2);
            
        }
    }
    sort(a.begin(), a.end());
    cout << c << " " << a[0] << endl;
    return 0;
} 