#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
static int N, M;
static int A, B;
vector<vector<int>> board;
vector<vector<int>> visited;
int dr[] = {1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
static int t = 0;
void bfs(int x, int y) {
    
    int s = 2;
    int cnt = 0;
    int posx = x, posy = y;
    while (true) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        visited = vector<vector<int>>(N, vector<int>(N, 0));
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] && board[i][j] < s) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) break;
        queue<pair<int, int>> q;
        q.push({ posx,posy });
        int mini = 999999;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (visited[r][c] > mini) continue;
            if (board[r][c] && board[r][c] < s) {
                if (visited[r][c] < mini) {
                    mini = min(mini, visited[r][c]);
                    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
                }
                pq.push({ r,c });
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (visited[nr][nc]) continue;
                if (board[nr][nc] > s)continue;
                visited[nr][nc] = 1 + visited[r][c];
                q.push({ nr,nc });
            }
        }
        if (pq.empty()) break;
        t += mini;
        board[pq.top().first][pq.top().second] = 0;
        posx = pq.top().first;
        posy = pq.top().second;
        cnt++;
        if (cnt == s) {
            cnt = 0; s++;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N));
    int r=0, c=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                r = i;
                c = j;
                board[i][j] = 0;
            }
        }
    }
    bfs(r, c);
    cout << t;
}
