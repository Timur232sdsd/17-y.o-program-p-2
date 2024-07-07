#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Shop {
    string firm;
    string street;
    int fat;
    int price;
};

int main() {
    int N;
    cin >> N;

    vector<Shop> shops(N);
    map<int, int> min_prices;

    for (int i = 0; i < N; i++) {
        cin >> shops[i].firm >> shops[i].street >> shops[i].fat >> shops[i].price;

        if (min_prices.find(shops[i].fat) == min_prices.end() || shops[i].price < min_prices[shops[i].fat]) {
            min_prices[shops[i].fat] = shops[i].price;
        }
    }

    int count_15 = 0, count_20 = 0, count_25 = 0;

    for (const auto& shop : shops) {
        if (shop.price == min_prices[shop.fat]) {
            if (shop.fat == 15) {
                count_15++;
            } else if (shop.fat == 20) {
                count_20++;
            } else if (shop.fat == 25) {
                count_25++;
            }
        }
    }

    cout << count_15 << " " << count_20 << " " << count_25 << endl;

    return 0;
}
