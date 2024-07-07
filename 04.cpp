#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    ifstream fin("26-j8.txt");
    if (!fin) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }
    fin >> N;
    vector<int> prices(N);

    for (int i = 0; i < N; ++i) {
        fin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    int profitAction1 = 0;
    int profitAction2 = 0;

    for (int i = 0; i < N; ++i) {
        if (i < N * 0.7) {
            profitAction1 += (prices[i] * 7) / 10; // 70% скидки
            profitAction2 += (prices[i] * 5) / 10; // 50% скидки
        } else {
            profitAction1 += (prices[i] * 6) / 10; // 60% скидки
            profitAction2 += (prices[i] * 65) / 100; // 65% скидки
        }
    }

    int chosenAction = (profitAction1 > profitAction2) ? 1 : 2;

    int maxPrice = 0;
    for (int i = 0; i < N; ++i) {
        if (chosenAction == 1 && i < N * 0.7) {
            maxPrice = max(maxPrice, prices[i]);
        } else if (chosenAction == 2 && i >= N * 0.7) {
            maxPrice = max(maxPrice, prices[i]);
        }
    }

    int diffProfit = abs(profitAction1 - profitAction2) - maxPrice;

    ofstream fout("output.txt");
    fout << chosenAction << " " << diffProfit << endl;
    fout.close();

    cout << "Результат записан в output.txt" << endl;

    return 0;
}
