#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, L, R, X;
vector<int> prob;
vector<bool> visited;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};
int cnt = 0;
void bt(vector<int> depth, int index) {
    if (depth.size() >= 2) {
        int sum = 0;
        for (int i = 0; i < depth.size(); i++) sum += depth[i];
        if (sum >= L && sum <= R && (depth.back() - depth.front()) >= X) cnt++;
    }
    if (index == N - 1) return;
    for (int i = index; i < N; i++) {
        if (visited[i])continue;
        depth.push_back(prob[i]);
        visited[i] = true;
        bt(depth, i);
        visited[i] = false;
        depth.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> L >> R >> X;
    prob = vector<int>(N);
    visited = vector<bool>(N, false);
    for (int i = 0; i < N; i++) {
        cin >> prob[i];
    }
    sort(prob.begin(), prob.end());
    vector<int> v;
    bt(v, 0);
    cout << cnt;
}