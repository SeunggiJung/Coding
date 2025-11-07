#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
map<int, vector<int>> m;
map<pii, bool> visited;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        m[b].push_back(a);
    }
    queue<vector<int>> q;
    q.push({0,0,0});
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if(visited[{x,y}]) continue;
        visited[{x,y}] = true;
        if(y==M){
            cout<<cnt;
            return 0;
        }
        for(int i=-2;i<=2;i++){
            int height = y + i;
            if(height>M) continue;
            if(m[height].empty()) continue;
            for(int nx : m[height]){
                if(abs(x - nx)<=2){
                    q.push({nx, height, cnt+1});
                }
            }
        }
    }
    cout<<-1;
}