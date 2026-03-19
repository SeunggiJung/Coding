#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, M;
pii st, en;
vector<vector<int>> board;
vector<vector<vector<int>>> visited;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int toleft[] = {3, 2, 0, 1};
int toright[] = {2, 3, 1, 0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<vector<int>>(M, vector<int>(4, false)));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    queue<vector<int>> q;
    vector<int> st(3), en(3);
    for(int i=0;i<3;i++){
        cin>>st[i];
        st[i]-=1;
    }
    for(int i=0;i<3;i++){
        cin>>en[i];
        en[i]-=1;
    }
    q.push({st[0], st[1], st[2], 0});
    visited[st[0]][st[1]][st[2]] = true;
    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int d = q.front()[2];
        int cnt = q.front()[3];
        q.pop();
        if(r==en[0] && c==en[1] && d==en[2]){
            cout<<cnt;
            exit(0);
        }
        for(int i=1;i<=3;i++){
            int nr = r + i * dr[d];
            int nc = c + i * dc[d];
            if(nr<0||nc<0||nr>=N||nc>=M) break;
            if(board[nr][nc]) break;
            if(visited[nr][nc][d]) continue;
            visited[nr][nc][d] = true;
            q.push({nr, nc, d, cnt+1});
        }
        // left = 0 -> 3, 1 -> 2, 2 -> 0, 3 -> 1
        // right= 0 -> 2, 1 -> 3, 2 -> 1, 3 -> 0
        int ld = toleft[d];
        int rd = toright[d];
        if(!visited[r][c][ld]){
            q.push({r, c, ld, cnt+1});
            visited[r][c][ld] = true;
        }
        if(!visited[r][c][rd]){
            q.push({r, c, rd, cnt+1});
            visited[r][c][rd] = true;
        }
    }
}
