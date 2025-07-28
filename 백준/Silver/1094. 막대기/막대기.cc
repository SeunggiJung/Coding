#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
static int X;
vector<vector<int>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> X;
    int stick = 64;
    vector<int> v;
    v.push_back(stick);
    int sum = 64;
    while (sum!=X) {
        sum = 0;
        sort(v.rbegin(), v.rend());
        int half = v[v.size()-1] / 2;
        v.pop_back();
        v.push_back(half);
        v.push_back(half);
        for (int i = 0; i < v.size()-1; i++) {
            sum += v[i];
        }
        if (sum >= X) {
            v.pop_back();
        }
    }
    cout << v.size();
}