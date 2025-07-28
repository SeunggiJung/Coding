#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<int> v;
static vector<bool> visited1;
static vector<bool> visited2;
static vector<int> visited;
static vector<int> out;
static vector<bool> kn;
static int mini;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};
void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == M) return;
        int next[3] = { 1,-1,x };
        for (int i = 0; i < 3; i++) {
            int nx = x + next[i];
            if (nx<0 || nx>=visited.size()) continue;
            if (!visited[nx]) {
                q.push(nx);
                visited[nx] = visited[x] + 1;
            }
            else if (visited[nx] && visited[nx] > visited[x] + 1) {
                q.push(nx);
                visited[nx] = visited[x] + 1;
            }
            else continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    mini = 9999999;
    int size = max(N, M);
    visited = vector<int>(size + 2, 0);
    bfs(N);
    cout << visited[M];
}
