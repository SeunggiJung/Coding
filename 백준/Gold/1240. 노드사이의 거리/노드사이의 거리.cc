#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int N, M;
map<int, vector<pii>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0;i<N-1;i++){
        int a, b, d;
        cin>>a>>b>>d;
        m[a].push_back({b,d});
        m[b].push_back({a,d});
    }
    while(M-->0){
        int a, b;
        cin>>a>>b;
        vector<bool> visited(N+1, false);
        queue<pii> q;
        q.push({a,0});
        while(!q.empty()){
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(cur==b){
                cout<<dist<<"\n";
                break;
            }
            if(visited[cur]) continue;
            visited[cur] = true;
            for(auto& next : m[cur]){
                if(visited[next.first]) continue;
                q.push({next.first, dist + next.second});
            }
        }
    }
}