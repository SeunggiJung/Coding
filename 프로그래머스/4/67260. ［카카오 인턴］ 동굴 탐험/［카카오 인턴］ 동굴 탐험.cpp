#include <string>
#include <vector>
#include <queue>
using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<vector<int>> board(n);
    for(auto& p : path){
        board[p[0]].push_back(p[1]);
        board[p[1]].push_back(p[0]);
    }
    vector<bool> visited(n, false);
    vector<int> bef(n, 0);
    vector<int> after(n, 0);
    for(auto& ord : order){
        bef[ord[1]] = ord[0];
        after[ord[0]] = ord[1];
    }
    if(bef[0]) return false;
    queue<int> q;
    vector<int> wait(n, 0);
    q.push(0);
    visited[0] = true;
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cnt++;
        if(wait[cur]){
            q.push(wait[cur]);
            visited[wait[cur]] = true;
        }
        for(int next : board[cur]){
            if(visited[next]) continue;
            if(!visited[bef[next]]){
                wait[bef[next]] = next;
                continue;
            }
            q.push(next);
            visited[next] = true;
        }
    }
    return cnt==n ? true : false;
}