#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, L, R;
vector<vector<int>> A;
vector<vector<bool>> visited;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int cnt=0;
bool bfs(int r, int c){
    queue<pii> q;
    vector<pii> route;
    int sum = 0;
    q.push({r, c});
    visited[r][c] = true; 
    sum += A[r][c];
    route.push_back({r, c});

    while(!q.empty()){
        pii current = q.front();
        q.pop();
        int cr = current.first;
        int cc = current.second;
        for(int i=0; i<4; ++i){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if(visited[nr][nc]) continue;

            int diff = abs(A[cr][cc] - A[nr][nc]);
            if(diff >= L && diff <= R){
                visited[nr][nc] = true; 
                q.push({nr, nc});
                sum += A[nr][nc];
                route.push_back({nr, nc});
            }
        }
    }

    if(route.size() > 1){
        int avg = sum / route.size();
        for(pii x : route){
            A[x.first][x.second] = avg;
        }
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>L>>R;
    A.assign(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    while(true){
        bool flag = false;
        visited.assign(N, vector<bool>(N, false));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]){
                    if(bfs(i,j)) flag=true;
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout<<cnt;
}