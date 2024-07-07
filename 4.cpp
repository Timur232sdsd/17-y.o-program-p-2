#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;}
    return a.first > b.first;}
int main() {
  int n, score, id; cin >> n; vector <pair <int, int>> s(n);
  for(int i=0; i<n; i++){
      cin >> id >> score;
      s[i] = make_pair(score, id);
    }
    sort(s.begin(), s.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << s[i].second << " " << s[i].first << endl;
    }
  return 0;
}