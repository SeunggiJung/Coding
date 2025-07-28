#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
#include <list>
using namespace std;
static long long int N, M;
static vector<vector<int>> v;
static vector<int> visited;
static int maxi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < M; j++) {
            v[i][j] = in[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    v[0][0] = 1;
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        if (r == N - 1 && c == M - 1) break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M ||v[nr][nc]!=1) continue;
            q.push({ nr,nc });
            v[nr][nc] = v[r][c] + 1;
        }
    }
    cout << v[N - 1][M - 1];
}
