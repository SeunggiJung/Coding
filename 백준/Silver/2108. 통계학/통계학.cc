#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, K;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<pii> cnt(8001);
    for (int i = 0; i < 8001; i++) {
        cnt[i] = { 0,i };
    }
    vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum+=v[i];
        cnt[v[i] + 4000].first++;
    }
    sort(v.begin(), v.end());
    cout << floor((double)sum / (double)N + 0.5) << "\n";
    cout << v[N / 2] << "\n";
    sort(cnt.rbegin(), cnt.rend());
    if (cnt[0].first == cnt[1].first) {
        for (int i = 2; i <= 8000; i++) {
            if (cnt[i].first < cnt[0].first) {
                cout << cnt[i - 2].second-4000 << "\n";
                break;
            }
        }
    }
    else cout << cnt[0].second-4000 << "\n";
    cout << v.back() - v.front() << "\n";
}