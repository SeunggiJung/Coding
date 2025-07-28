#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> arr;
vector<pair<int, int>> cctv;
int mini = INT32_MAX;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir){
    dir %= 4;
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if(arr[nx][ny] == 6) return;
        if(arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

void dfs(int depth){
    if(depth == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(!arr[i][j]) cnt++;

        mini = min(mini, cnt);
        return;
    }
    
    int x = cctv[depth].first;
    int y = cctv[depth].second;
    vector<vector<int>> tmp(N, vector<int>(M));

    for(int dir = 0; dir < 4; dir++){
        tmp=arr;

        if(arr[x][y] == 1)
            check(x, y, dir);
        else if(arr[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if (arr[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2); 
        }
        else if (arr[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }
        dfs(depth+1);
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                arr[i][j] = tmp[i][j];
    }    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({i, j});
        }
    }

    dfs(0);
    cout << mini;

    return 0;
}