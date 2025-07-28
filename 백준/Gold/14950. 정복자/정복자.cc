#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,t;
static vector<int> v;
static vector<bool> visited;
static map<int, vector<pair<int,int>>> m;
static int mini;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void mst() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ 1,0 });
    int weight = 0;
    int len = 0;
    while (!pq.empty()) {
        int A = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        if (visited[A]) continue;
        visited[A] = true;
        weight += w + t * (len - 1);
        len++;
        for (int i = 0; i < m[A].size(); i++) {
            pq.push({ m[A][i] });
        }
    }
    cout << weight + t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> t;
    visited = vector<bool>(N + 1,false);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        m[A].push_back({ B,C });
        m[B].push_back({ A,C });
    }
    mst();
}
