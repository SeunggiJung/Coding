#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, int> pdi;
int N, M;
map<int, vector<pii>> m;
vector<bool> visited;
//'a' = 97, 'A' = 65
int mst(int start){
    int sum = 0;
    visited.assign(N, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({start, 0});
    while(!pq.empty()){
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        sum += w;
        for(pii next : m[cur]){
            if(next.second==cur) continue;
            if(visited[next.second]) continue;
            pq.push(next);
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    string in;
    int sum = 0;
    for(int i=0;i<N;i++){
        cin>>in;
        for(int j=0;j<N;j++){
            if(in[j] - '0' == 0) continue;
            int dist;
            if(in[j]>'Z') {
                dist = (int)(in[j] - 'a' + 1);
                m[i].push_back({dist, j});
                m[j].push_back({dist, i});
                sum += dist;
            }
            else{
                dist = (int)(in[j] - 'A' + 27);
                m[i].push_back({dist, j});
                m[j].push_back({dist, i});
                sum += dist;
            }
        }
    }
    for(int i=0;i<N;i++){
        int d = mst(i);
        bool flag=true;
        for(int j=0;j<N;j++){
            if(!visited[j]) flag = false;
        }
        if(!flag) continue;
        cout<<sum - d;
        exit(0);
    }
    cout<<-1;
}
