#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    ifstream f("26_838.txt");
    f >> N;
    vector<int> files(N);

    for (int i = 0; i < N; ++i) {
        f >> files[i];
    }

    sort(files.rbegin(), files.rend());

    int disk1_sum = 0, disk2_sum = 0;
    int disk1_count = 0, disk2_count = 0;

    for (int i = 0; i < N; ++i) {
        if (disk1_sum <= disk2_sum) {
            disk1_sum += files[i];
            disk1_count++;
        } else {
            disk2_sum += files[i];
            disk2_count++;
        }
    }

    cout << disk1_count << " " << disk2_count << endl;

    return 0;
}
