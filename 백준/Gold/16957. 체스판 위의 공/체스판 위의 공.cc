#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int R,C;
int dr[] = {0,1,1,1,0,-1,-1,-1};
int dc[] = {1,1,0,-1,-1,-1,0,1};
vector<int> parent(300001);
map<int, pii> m;
int find(int child){
    if(parent[child] == child) return child;
    return parent[child] = find(parent[child]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>R>>C;
    for(int i=1;i<=300000;i++) parent[i] = i;
    vector<vector<int>> board(R, vector<int>(C));
    priority_queue<vector<int>> pq;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
            pq.push({board[i][j], i, j});
            m[board[i][j]] = {i,j};
        }
    }
    while(!pq.empty()){
        int i = pq.top()[1];
        int j = pq.top()[2];
        pq.pop();
        for(int k=0;k<8;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr<0||nc<0||nr>=R||nc>=C) continue;
            if(board[nr][nc]>board[i][j]) continue;
            if(parent[board[nr][nc]]<find(board[i][j])){
                parent[board[i][j]] = find(parent[board[nr][nc]]);
            }
        }
    }
    vector<vector<int>> cnt(R, vector<int>(C,0));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            pii rc = m[find(parent[board[i][j]])];
            cnt[rc.first][rc.second]++;
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<"\n";
    }
}