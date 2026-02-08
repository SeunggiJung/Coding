#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, int> pdi;
vector<int> popul;
vector<bool> visited;
map<int, vector<int>> m;
int sum = 0;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    popul.assign(N+1, 0);
    visited.assign(N+1, 0);
    for(int i=1;i<=N;i++){
        cin>>popul[i];
        sum += popul[i];
    }
    for(int i=1;i<=N;i++){
        cin>>M;
        for(int j=0;j<M;j++){
            int a;
            cin>>a;
            m[i].push_back(a);
            m[a].push_back(i);
        }
    }
    int res = 1001;
    for(int i=0;i<(2<<N);i++){
        vector<bool> g(N+1, false);
        for(int j=0;j<N;j++){
            if(i & (2<<j)){
                g[j+1] = true;
            }
        }
        int s1 = 0, s2 = 0;
        for(int j=1;j<=N;j++){
            if(g[j]) s1+=popul[j];
            else s2+=popul[j];
        }
        vector<bool> visited1(N+1, false);
        vector<bool> visited2(N+1, false);
        for(int j=1;j<=N;j++){
            if(g[j]){
                queue<int> q;
                q.push(j);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    visited1[cur] = true;
                    for(int next : m[cur]){
                        if(!g[next]) continue;
                        if(visited1[next]) continue;
                        q.push(next);
                    }
                }
                break;
            }
        }
        for(int j=1;j<=N;j++){
            if(!g[j]){
                queue<int> q;
                q.push(j);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    visited2[cur] = true;
                    for(int next : m[cur]){
                        if(g[next]) continue;
                        if(visited2[next]) continue;
                        q.push(next);
                    }
                }
                break;
            }
        }
        bool flag = true;
        for(int j=1;j<=N;j++){
            if(g[j] && !visited1[j]) flag=false;
            if(!g[j] && !visited2[j]) flag=false;
        }
        if(flag){
            res = min(res, abs(s1 - s2));
        }
    }
    if(res==1001){
        cout<<-1;
    }
    else{
        cout<<res;
    }
}
