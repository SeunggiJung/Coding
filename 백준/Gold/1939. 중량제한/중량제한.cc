#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, M;
static int f1, f2;
vector<int> value;
vector<vector<pair<int, int>>>m;
void bfs() {
    priority_queue<pair<int, int>> q;
    q.push({ 1000000001, f1 });
    value[f1] = 1000000001;
    while (!q.empty()) {
        int w = q.top().first;
        int A = q.top().second;
        q.pop();
        if (w < value[A]) continue;
        for (auto& p : m[A]) {
            int mini= min(w, p.second);

            if (mini > value[p.first]) {
                value[p.first] = mini;
                q.push({ mini, p.first });
            }
        }
    }
    cout << value[f2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    value = vector<int>(N + 1, 0);
    m = vector<vector<pair<int, int>>>(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        m[A].push_back({ B,C });
        m[B].push_back({ A,C });
    }
    cin >> f1 >> f2;
    bfs();
}