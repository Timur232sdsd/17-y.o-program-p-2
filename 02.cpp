#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    ifstream fin("26-j8.txt");
    fin >> N;

    vector<int> p(N);

    for (int i = 0; i < N; ++i) {
        fin >> p[i];
    }

    sort(p.begin(), p.end());

    int profit1 = 0;
    int profit2 = 0;

    for (int i = 0; i < N; ++i) {
        if (i < N) {
            profit1 += p[i] * 0.7;
            profit2 += p[i] * 0.5;
        } 
        else if(i < N*0.5){
            profit1 += p[i] * 0.6;
            profit2 += p[i] * 0.65;
        }
    }
    int c = (profit1 > profit2) ? 1 : 2;

    int maxP = 0;
    for (int i = 0; i < N; ++i) {
        if (c == 1 && i < N * 0.7) {
            maxP = max(maxP, p[i]);
        } 
        else if (c == 2 && i >= N * 0.5) {
            maxP = max(maxP, p[i]);
        }
    }

    int dprofit = abs(profit1 - profit2) - maxP;
    ofstream fout("output.txt");
        fout << c << " " << dprofit << endl;
    return 0;
}