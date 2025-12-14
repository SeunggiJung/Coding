#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, T;
map<string, bool> visited;
map<int, vector<int>> dir;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dir[0] = {1, 3};
    dir[1] = {-1, 1, 3};
    dir[2] = {-1, 3};
    dir[3] = {-3, 1, 3};
    dir[4] = {-3, -1, 1, 3};
    dir[5] = {-3, -1, 3};
    dir[6] = {-3, 1};
    dir[7] = {-3, -1, 1};
    dir[8] = {-3, -1};
    string goal = "123456780";
    string b;
    vector<vector<char>> board(3, vector<char>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>board[i][j];
            b.push_back(board[i][j]);
        }
    }
    visited[b] = true;
    queue<pair<string, int>> q;
    q.push({b, 0});
    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur==goal){
            cout<<cnt;
            return 0;
        }
        int zero;
        for(int i=0;i<9;i++) if(cur[i] == '0') zero = i;
        string next;
        for(int d : dir[zero]){
            next = cur;
            int n = zero + d;
            swap(next[zero], next[n]);
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, cnt+1});
        }
    }
    cout<<-1;
}
