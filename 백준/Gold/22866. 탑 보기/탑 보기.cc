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
static int N, M, T;
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
    vector<int> v(N + 1);
    vector<pii> cnt(N + 1, {0,100001});
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    vector<pii> tall;
    tall.push_back({ v[1], 1 });
    for (int i = 2; i <= N; i++) {
        if (tall.empty()) continue;
        if(tall.back().first<=v[i]) {
            while (tall.back().first <= v[i]) {
                tall.pop_back();
                if (tall.empty()) break;
            }
        }
        if (!tall.empty()) cnt[i].second = tall.back().second;
        tall.push_back({ v[i],i });
        cnt[i].first += tall.size()-1;
    }
    tall.clear();
    tall.push_back({ v[N], N });
    for (int i = N-1; i >= 1; i--) {
        if (tall.empty()) continue;
        if (tall.back().first <= v[i]) {
            while (tall.back().first <= v[i]) {
                tall.pop_back();
                if (tall.empty()) break;
            }
        }
        if (!tall.empty()) {
            if (abs(cnt[i].second - i) > abs(tall.back().second - i))
                cnt[i].second = tall.back().second;
        }
        tall.push_back({ v[i],i });
        cnt[i].first += tall.size() - 1;
    }
    for (int i = 1; i <= N; i++) {
        cout << cnt[i].first;
        if (cnt[i].first) {
            cout << " " << cnt[i].second;
        }
        cout << "\n";
    }
}