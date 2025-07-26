#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> v;
int T, M, N, x, y;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (N < 3) {
        cout << 0;
        return 0;
    }
    map<int, vector<pii>> m;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (i == j) continue;
            m[v[i] + v[j]].push_back({ i,j });
        }
    }
    for (int i = 0; i < N; i++) {
        if (m[v[i]].size()) {
            for (auto& a : m[v[i]]) {
                if (i != a.first && i != a.second) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
}