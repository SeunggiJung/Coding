#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<pair<set<int>, set<int>>> comp(N + 1); // first = heavy, second = light
    for (int i = 0; i < M; i++) {
        int light, heavy;
        cin >> heavy >> light;
        comp[heavy].second.insert(light);
        for (auto& x : comp[light].second) comp[heavy].second.insert(x);
        comp[light].first.insert(heavy);
        for (auto& x : comp[heavy].first) comp[light].first.insert(x);
    }
    for (int i = 1; i <= N; i++) {
        for (auto& big : comp[i].first) {
            for (auto& small : comp[i].second)
                comp[big].second.insert(small);
        }
        for (auto& small : comp[i].second) {
            for (auto& big : comp[i].first)
                comp[small].first.insert(big);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << N - 1 - (comp[i].first.size() + comp[i].second.size()) << "\n";
    }
}