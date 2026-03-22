#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, M, K;
int h, w;
vector<vector<int>> board;
vector<vector<bool>> hsg;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    cin>>h>>w;
    board.assign(N+1, vector<int>(M+1));
    hsg.assign(N+1, vector<bool>(M+1, false));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    cin>>K;
    queue<pii> q;
    for(int i=0;i<K;i++){
        int x, y;
        cin>>x>>y;
        hsg[x][y] = true;
        q.push({x, y});
    }
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1||nc<1||nr>N||nc>M) continue;
            if(hsg[nr][nc]) continue;
            if(board[nr][nc] < board[r][c]) continue;
            hsg[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    vector<vector<int>> nsum(N+1, vector<int>(M+1, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            nsum[i][j] = nsum[i-1][j] + nsum[i][j-1] - nsum[i-1][j-1] + hsg[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=N-h+1;i++){
        for(int j=1;j<=M-w+1;j++){
            int x = i+h-1, y = j+w-1;
            int sum = nsum[x][y] - nsum[i-1][y] - nsum[x][j-1] + nsum[i-1][j-1];
            if(sum==w*h) cnt++;
        }
    }
    cout<<cnt;
}
