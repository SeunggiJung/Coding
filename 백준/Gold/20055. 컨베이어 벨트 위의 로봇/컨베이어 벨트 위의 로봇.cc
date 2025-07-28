#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, K;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    vector<pair<int, bool>> v(N * 2, { 0,false });
    for (int i = 0; i < N * 2; i++) {
        cin >> v[i].first;
    }
    int up = 0;
    int down = 0;
    int res = 1;
    while (true) {
        up = (up + N * 2 - 1) % (N * 2);
        down = (up + N - 1) % (N * 2);
        if (v[down].second) v[down].second = false;
        for (int i = up + N - 1; i >= up; i--) {
            int now = i % (N * 2);
            int next = (now + 1) % (N * 2);
            if (v[now].second && (!v[next].second && v[next].first > 0)) {
                v[now].second = false;
                v[next] = {v[next].first-1, true};
            }
        }
        if (v[down].second) v[down].second = false;
        if (v[up].first > 0) v[up] = { v[up].first - 1,true };
        int cnt = 0;
        for (auto& x : v) {
            if (!x.first)
                cnt++;
        }
        if (cnt >= K) break;
        res++;
    }
    cout << res;
}