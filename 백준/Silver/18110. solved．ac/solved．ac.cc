#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    if (N == 0) {
        cout << 0; return 0;
    }
    vector<int> difi;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        difi.push_back(d);
    }
    sort(difi.begin(), difi.end());
    int sum = 0;
    if (N == 1) {
        cout << difi[0];
        return 0;
    }
    int m = 0;
    int diff = floor((double)N * 0.15 + 0.5);
    for (int i = diff; i < N - diff; i++) {
        sum += difi[i];
        m++;
    }
    cout << floor((double)sum / m + 0.5);
}