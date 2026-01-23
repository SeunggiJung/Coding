#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N;
bool compare(pii a, pii b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    cin>>N;
    int l, h, r;
    vector<pii> buildings;
    for(int i=0;i<N;i++){
        cin>>l>>h>>r;
        buildings.push_back({l, h});
        buildings.push_back({r, -h});
    }
    sort(buildings.begin(), buildings.end(), compare);
    priority_queue<int> pq;
    map<int, int> m;
    int pre = -1;
    pq.push(0);
    for(pii b : buildings){
        if(b.second > 0) pq.push(b.second);
        else m[-b.second]++;
        while(!pq.empty()){
            if(!m[pq.top()]) break;
            m[pq.top()]--;
            pq.pop();
        }
        int cur = pq.top();
        if(cur != pre){
            cout<<b.first<<" "<<cur<<" ";
            pre = cur;
        }
    }
}