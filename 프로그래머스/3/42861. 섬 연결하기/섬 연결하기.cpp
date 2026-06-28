#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<vector<pii>> link;
int solution(int n, vector<vector<int>> costs) {
    link.resize(n);
    visited.assign(n, false);
    for(auto& cost : costs){
        int a = cost[0];
        int b = cost[1];
        int c = cost[2];
        link[a].push_back({c, b});
        link[b].push_back({c, a});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int answer = 0;
    pq.push({0,0});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        answer+=cost;
        for(auto& next : link[cur]){
            int nnode = next.second;
            int ncost = next.first;
            if(visited[nnode]) continue;
            pq.push({ncost, nnode});
        }
    }
    return answer;
}