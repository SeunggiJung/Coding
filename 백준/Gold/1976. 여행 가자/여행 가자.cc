#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<vector<int>> board;
vector<int> p;
vector<int> travel;
long long int maxi = 0;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int parent(int child) {
    if (p[child] == child)
        return child;
    else {
        p[child] = parent(p[child]);
        return p[child];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<int>>(N+1, vector<int>(N+1));
    p = vector<int>(N + 1);
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                if (i > j) p[parent(j)] = p[parent(i)];
                else p[parent(i)] = p[parent(j)];
            }
        }
    }
    vector<int> so(M);
    for (int i = 0; i < M; i++) {
        cin >> so[i];
    }
    for (int i = 0; i < M-1; i++) {
        if (parent(p[so[i]]) != parent(p[so[i+1]])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}