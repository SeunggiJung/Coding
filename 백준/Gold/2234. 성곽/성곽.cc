#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<vector<bool>> linked(2501, vector<bool>(2501, false));
vector<vector<int>> visited;
vector<vector<int>> board;
vector<int> divs = {8,4,2,1};
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
vector<int> counts = {0};
int max1 = 0;
void bfs(int R, int C, int num){
    queue<pii> q;
    int cnt=1;
    q.push({R, C});
    visited[R][C] = num;
    vector<bool> tmp(num, false);
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            bool flag=false;
            if((board[r][c] & divs[i])) flag = true;
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(visited[nr][nc]){
                int next = visited[nr][nc];
                linked[next][num] = true;
                linked[num][next] = true;
                flag=true;
            }
            if(flag) continue;
            q.push({nr, nc});
            visited[nr][nc] = num;
            cnt++;
        }
    }
    counts.push_back(cnt);
    max1 = max(max1, cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>M>>N;
    visited.assign(N, vector<int>(M, 0));
    board.assign(N, vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]) continue;
            cnt++;
            bfs(i, j, cnt);
        }
    }
    int max2 = 0;
    for(int i=1;i<cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(linked[i][j]) {
                max2 = max(max2, counts[i] + counts[j]);
            }
        }
    }
    cout<<cnt<<"\n"<<max1<<"\n"<<max2;
}
