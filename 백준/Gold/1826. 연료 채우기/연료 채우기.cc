#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, goal, gas;
vector<pii> v;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    cin>>N;
    priority_queue<pii, vector<pii>> pq;
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        pq.push({b,a});
    }
    cin>>goal>>gas;
    int cur = 0;
    int cnt = 0;
    while(cur + gas<goal){
        if(pq.empty()) break;
        int fill;
        int loc;
        queue<pii> q;
        int qs = pq.size();
        while(cur+gas<goal && !pq.empty()){
            fill = pq.top().first;
            loc = pq.top().second;
            pq.pop();
            if(loc > cur+gas){
                q.push({fill, loc});
                continue;
            }
            cnt++;
            gas += fill - (loc-cur);
            cur = loc;
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            break;
        }
        if(qs == pq.size()) break;
    }
    if(cur + gas < goal) cout<<-1;
    else cout<<cnt;
}