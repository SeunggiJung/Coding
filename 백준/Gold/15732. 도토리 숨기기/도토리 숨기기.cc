#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii;
bool flag = false;
int N, K, D, A, B, C;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K >> D;
    vector<vector<int>> rules(K);
    int i = 0;
    while (K-- > 0) {
        cin >> A >> B >> C;
        rules[i++] = { A,B,C };
    }
    int s = 0;
    int e = N;
    while (s + 1 < e) {
        int mid = (s + e) / 2;
        long long int cnt = 0;
        for (auto& rule : rules) {
            if (mid < rule[0]) continue;
            long long int dtr = (min(rule[1], mid) - rule[0]) / rule[2] + 1;
            cnt += dtr;
        }
        if (cnt >= D) {
            e = mid;
        }
        else
            s = mid;
    }
    cout << e;
}
