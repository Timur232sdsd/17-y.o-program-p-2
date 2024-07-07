#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    vector<int> vec;

    while (cin >> x) {
        vec.push_back(x);
        if(x==0){break;}
    }

    int mn = INT_MAX; 
    int mx = INT_MIN; 

    for (int i = 0; i < vec.size(); ++i) {
        if (i % 2 == 0) { 
            mx = max(mx, vec[i]);
        } else { 
            mn = min(mn, vec[i]);
        }
    }

    cout << mx + mn;
    return 0;
}
