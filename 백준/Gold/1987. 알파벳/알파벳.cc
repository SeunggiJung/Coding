#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<vector<int>> v;
static vector<vector<int>> num;
static vector<bool> visited;
static vector<bool> isprime;
static vector<int> out;
static int max_value;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bt(int r, int c, int depth) {
    visited[v[r][c]] = true;
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,1,-1 };
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M ) continue;
        if (visited[v[nr][nc]])continue;
        flag = true;
        visited[v[nr][nc]] = true;
        bt(nr,nc,depth+1);
        visited[v[nr][nc]] = false;
    }
    if (!flag) {
        max_value = max(max_value, depth);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    max_value = 0;
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M));
    visited = vector<bool>(26, false);
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < M; j++) {
            v[i][j] = in[j] - 'A';
        }
    }
    bt(0,0,1);
    cout << max_value;
}
