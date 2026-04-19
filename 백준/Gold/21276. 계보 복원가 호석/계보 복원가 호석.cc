#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
// 위상 정렬 다시 풀기 (indegree 이용)
int N, M;
vector<int> indegree;
vector<vector<string>> childs;
vector<string> toname;
map<string, int> tonum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    indegree.assign(N, 0);
    childs.assign(N, {});
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        tonum[name] = i;
        toname.push_back(name);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        string c, p;
        cin>>c>>p;
        childs[tonum[p]].push_back(c);
        indegree[tonum[c]]++;
    }
    priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, greater<pair<string, vector<string>>>> pq;
    queue<int> q;
    for(int i=0;i<N;i++){
        if(!indegree[i]) q.push(i);
    }
    int qs = q.size();
    cout<<qs<<"\n";
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        if(cnt<qs){
            cout<<toname[cur]<<" ";
            cnt++;
        }
        q.pop();
        pair<string, vector<string>> a = {toname[cur], {}};
        for(auto& x : childs[cur]){
            indegree[tonum[x]]--;
            if(!indegree[tonum[x]]){
                a.second.push_back(x);
                q.push(tonum[x]);
            }
        }
        pq.push(a);
    }
    cout<<"\n";
    while(!pq.empty()){
        cout<<pq.top().first<<" ";
        cout<<pq.top().second.size()<<" ";
        for(auto& x : pq.top().second){
            cout<<x<<" ";
        }
        cout<<"\n";
        pq.pop();
    }
}