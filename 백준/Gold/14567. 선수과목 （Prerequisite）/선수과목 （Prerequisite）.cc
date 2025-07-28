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
static int cnt;
map<int, vector<pair<int,int>>> m;
static int maxi;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void find(int child, int depth) {
    if (v[child].empty()) {
        maxi = max(depth, maxi);
        return;
    }
    for (int i = 0; i < v[child].size(); i++) {
        find(v[child][i], depth + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<int>>(N+1);
    for (int i = 0; i < M; i++) {
        int pre, post;
        cin >> pre >> post;
        v[pre].push_back(post);
    }
    visited = vector<int> (N + 1, 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            visited[v[i][j]] = max(visited[i] + 1, visited[v[i][j]]);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << " ";
    }
}
