#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<int> ind;
vector<vector<pii>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    ind.assign(N+1, 0);
    v.resize(N+1);
    for(int i=0;i<M;i++){
        int x, y, k;
        cin>>x>>y>>k;
        v[x].push_back({y, k});
        ind[y]++;
    }
    vector<int> cnt(N+1, 0);
    queue<int> q;
    q.push(N);
    cnt[N] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto &next : v[cur]){
            cnt[next.first] += cnt[cur]*next.second;
            ind[next.first]--;
            if(!ind[next.first]) q.push(next.first);
        }
    }
    for(int i=1;i<=N;i++){
        if(v[i].empty()){
            cout<<i<<" "<<cnt[i]<<"\n";
        }
    }
}