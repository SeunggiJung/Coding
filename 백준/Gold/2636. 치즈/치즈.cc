#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    vector<vector<int>> board(N, vector<int>(M));
    int cheese = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]) cheese++;
        }
    }
    vector<vector<bool>> visited;
    int cnt = 0;
    while(cheese>0){
        cnt++;
        visited.assign(N, vector<bool>(M, false));
        queue<pii> q;
        q.push({0,0});
        vector<pii> chs;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0||nc<0||nr>=N||nc>=M) continue;
                if(visited[nr][nc]) continue;
                if(board[nr][nc]){
                    chs.push_back({nr, nc});
                }else {
                    q.push({nr, nc});
                }
                visited[nr][nc] = true;
            }
        }
        if(cheese - chs.size() == 0){
            cout<<cnt<<"\n"<<cheese;
            return 0;
        }
        cheese -= chs.size();
        while(!chs.empty()){
            int r = chs.back().first;
            int c = chs.back().second;
            chs.pop_back();
            board[r][c] = 0;
        }
    }
}
