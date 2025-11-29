#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int N, S;
int INF = 100001;
vector<vector<int>> board;
void toleft(vector<vector<int>>& v){ // 왼쪽으로 밀기
    for(int i=0;i<N;i++){
        queue<int> q;
        for(int j=0;j<N;j++){
            if(v[i][j]) q.push(v[i][j]);
            v[i][j] = 0;
        }

        int idx = 0;
        while(!q.empty()){
            int data = q.front();
            q.pop();

            if(v[i][idx] == 0){
                v[i][idx] = data;
            }
            else if(v[i][idx] == data){
                v[i][idx] *= 2;
                idx++;
            }
            else{
                idx++;
                v[i][idx] = data;
            }
        }
    }
}

// 오른쪽으로 밀기
void toright(vector<vector<int>>& v){
    for(int i=0;i<N;i++){
        queue<int> q;
        for(int j=N-1;j>=0;j--){
            if(v[i][j]) q.push(v[i][j]);
            v[i][j] = 0;
        }

        int idx = N-1;
        while(!q.empty()){
            int data = q.front();
            q.pop();

            if(v[i][idx] == 0){
                v[i][idx] = data;
            }
            else if(v[i][idx] == data){
                v[i][idx] *= 2;
                idx--;
            }
            else{
                idx--;
                v[i][idx] = data;
            }
        }
    }
}

// 위로 밀기
void toup(vector<vector<int>>& v){
    for(int j=0;j<N;j++){
        queue<int> q;
        for(int i=0;i<N;i++){
            if(v[i][j]) q.push(v[i][j]);
            v[i][j] = 0;
        }

        int idx = 0;
        while(!q.empty()){
            int data = q.front();
            q.pop();

            if(v[idx][j] == 0){
                v[idx][j] = data;
            }
            else if(v[idx][j] == data){
                v[idx][j] *= 2;
                idx++;
            }
            else{
                idx++;
                v[idx][j] = data;
            }
        }
    }
}

// 아래로 밀기
void todown(vector<vector<int>>& v){
    for(int j=0;j<N;j++){
        queue<int> q;
        for(int i=N-1;i>=0;i--){
            if(v[i][j]) q.push(v[i][j]);
            v[i][j] = 0;
        }

        int idx = N-1;
        while(!q.empty()){
            int data = q.front();
            q.pop();

            if(v[idx][j] == 0){
                v[idx][j] = data;
            }
            else if(v[idx][j] == data){
                v[idx][j] *= 2;
                idx--;
            }
            else{
                idx--;
                v[idx][j] = data;
            }
        }
    }
}
vector<vector<bool>> visited(5, vector<bool>(4, false)); // depth, direction
int maxi = 0;
void bt(int depth, vector<int> dir){
    if(depth==5){
        vector<vector<int>> copy = board;
        for(int d : dir){
            if(d==0) toleft(copy);
            if(d==1) toright(copy);
            if(d==2) toup(copy);
            if(d==3) todown(copy);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                maxi = max(maxi, copy[i][j]);
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(visited[depth][i]) continue;
        visited[depth][i] = true;
        dir.push_back(i);
        bt(depth+1, dir);
        dir.pop_back();
        visited[depth][i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    board.resize(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    bt(0, {});
    cout<<maxi;
}
