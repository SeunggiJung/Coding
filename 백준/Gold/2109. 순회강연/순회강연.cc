#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    priority_queue<pii, vector<pii>, compare> pq;
    for(int i=0;i<N;i++){
        int p,d;
        cin>>p>>d;
        pq.push({p,d});
    }
    int bef=0;
    int sum=0;
    vector<int> visited(10001,0);
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        int diff=0;
        int index;
        for(int i=1;i<=cur;i++){
            if(cost-visited[i]>diff){
                diff = cost-visited[i];
                index = i;
            }
        }
        visited[index] = cost;
        sum+=diff;
    }
    cout<<sum;
}