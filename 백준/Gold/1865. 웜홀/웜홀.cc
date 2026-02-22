#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int TC, N, M, W;
int S, E, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>TC;
    while(TC-->0){
        cin>>N>>M>>W;
        map<int, vector<pii>> m;
        vector<vector<int>> dist(N+1, vector<int>(N+1, 25000001));
        for(int i=0;i<M;i++){
            cin>>S>>E>>T;
            dist[S][E] = min(dist[S][E], T);
            dist[E][S] = min(dist[E][S], T);
        }
        for(int i=0;i<W;i++){
            cin>>S>>E>>T;
            dist[S][E] = min(dist[S][E], -T);
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                if(i==k) continue;
                for(int j=1;j<=N;j++){
                    if(k==j) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        bool flag=false;
        for(int i=1;i<=N;i++){
            if(dist[i][i]<0) flag=true;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
