#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> board;
int N, M;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    int r, c, d;
    cin>>r>>c>>d;
    board.assign(N, vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    queue<vector<int>> q;
    q.push({r, c, d});
    int cnt = 0;
    while(!q.empty()){
        int R = q.front()[0];
        int C = q.front()[1];
        int D = q.front()[2];
        q.pop();
        if(!board[R][C]){
            board[R][C]=2;
            cnt++;
        }
        bool flag = false;
        for(int i=1;i<=4;i++){
            int nr, nc, nd;
            nd = (D-i+4)%4;
            nr = R + dr[nd];
            nc = C + dc[nd];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(board[nr][nc]) continue;
            flag = true;
            q.push({nr, nc, nd});
            break;
        }
        if(!flag){
            int nr = R - dr[D];
            int nc = C - dc[D];
            if(nr<0||nc<0||nr>=N||nc>=M) break;
            if(board[nr][nc]==1) break;
            q.push({nr, nc, D});
        }
    }
    cout<<cnt;
}
