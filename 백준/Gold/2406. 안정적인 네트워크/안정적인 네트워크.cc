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
vector<vector<pii>> v;
static int N, M, K;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void solution() {
    if (N == 1) {
        cout << "0 0";
        return;
    }
    vector<bool> visited(N + 1, false); // 방문 처리
    vector<int> dist(N + 1, INT32_MAX); // 가중치
    vector<pii> link;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int res = 0;
    int cnt = 0;
    dist[2] = 0;
    pq.push({ 0,2,2 });
    while (!pq.empty()) {
        int w = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if (visited[y]) continue;
        visited[y] = true;
        res += w;
        if (w) {
            cnt++;
            link.push_back({ x,y });
        }

        for (auto& linked : v[y]) {
            if (!visited[linked.second] && linked.first < dist[linked.second]) {
                pq.push({ linked.first, y, linked.second });
                dist[linked.second] = linked.first;
            }
        }
    }
    if (res == 0) {
        cout << "0 0";
        return;
    }
    cout << res << " " << cnt << "\n";
    for (auto& a : link) {
        cout << a.first << " " << a.second << "\n";
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<pii>>(N + 1); // 노드 간 연결 정보 + 가중치 (이미 연결 0)

    vector<pii> linked; // 이미 연결
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        linked.push_back({ x,y });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int w;
            cin >> w;
            if (i <= 1 || j <= 1) continue;
            v[i].push_back({ w,j });
            v[j].push_back({ w,i });
        }
    }
    for (auto& l : linked) {
        v[l.first].push_back({ 0,l.second });
        v[l.second].push_back({ 0,l.first });
    }
    solution();
}