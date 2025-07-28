#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
static int T, N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int i = 0;i < T;i++) {
        cin >> N >> M;
        queue<pii> q;
        vector<int> v;
        for (int j = 0;j < N;j++) {
            int a;
            cin >> a;
            q.push({ j,a });
            v.push_back(a);
        }
        if (N == 1) {
            cout << 1 << "\n";
            continue;
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (value == v.back()) {
                v.pop_back();
                cnt++;
                if (index != M) continue;
                break;
            }
            q.push({ index, value });
        }
        cout << cnt << "\n";
    }
}