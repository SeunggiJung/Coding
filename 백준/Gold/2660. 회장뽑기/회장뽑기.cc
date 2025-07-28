#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <random>
using namespace std;
static int N, x;
static vector<vector<int>> v;
static vector<int> scores;
int mini;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vector<int> move(N + 1, 999999999);
    move[start] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int a : v[x]) {
            if (move[a] < 1 + move[x]) continue;
            move[a] = 1 + move[x];
            q.push(a);
        }
    }
    int maxi = 0;
    for (int i = 1; i < N + 1; i++) {
        if (i == start) continue;
        maxi = max(maxi, move[i]);
    }
    scores[start] = maxi;
    mini = min(mini, maxi);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mini = 999999999;
    cin >> N;
    scores = vector<int>(N + 1,999999999);
    v = vector<vector<int>>(N + 1);
    while (true) {
        int A, B;
        cin >> A >> B;
        if (A == -1 && B == -1) break;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for (int i = 1; i <= N; i++) {
        bfs(i);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (scores[i] == mini) cnt++;
    }
    cout << mini << " " << cnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (scores[i] == mini) cout << i << " ";
    }
}
