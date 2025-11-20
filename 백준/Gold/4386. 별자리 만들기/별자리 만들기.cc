#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,double> p;
typedef pair<double, double> pdd;
map<int, vector<p>> m;
int N;
double calc(pdd a, pdd b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second,2));
}
void mst(){
    vector<bool> visited(N, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0,0});
    double weight=0;
    while(!pq.empty()){
        int node = pq.top().second;
        double w = pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        weight += w;
        for(p xy : m[node]){
            if(visited[xy.first]) continue;
            pq.push({xy.second, xy.first});
        }
    }
    printf("%.2f", weight);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pdd> v;
    cin>>N;
    for(int i=0;i<N;i++){
        double x, y;
        cin>>x>>y;
        v.push_back({x,y});
        for(int j=0;j<i;j++){
            double dist = calc(v[i], v[j]);
            m[i].push_back({j, dist});
            m[j].push_back({i, dist});
        }
    }
    mst();
}
