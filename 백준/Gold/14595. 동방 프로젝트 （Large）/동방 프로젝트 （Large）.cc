#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, M, x, y;
vector<int> parent;
int find(int child) {
    if (parent[child] == child)
        return child;
    return parent[child] = find(parent[child]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    parent = vector<int>(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;
    int bef_front = 0;
    int bef_back = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        pq.push({ x,y });
    }
    while (!pq.empty()) {
        int f = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        if (f > bef_back) {
            for (int i = bef_front; i <= bef_back; i++) {
                parent[i] = bef_front;
            }
            bef_front = f;
            bef_back = b;
            continue;
        }
        bef_back = max(bef_back, b);
    }
    for (int i = bef_front; i <= bef_back; i++) {
        parent[i] = bef_front;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) cnt++;
    }
    cout << cnt;
}