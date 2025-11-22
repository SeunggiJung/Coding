#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, L;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>L;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0;i<N;i++){
        int s, e;
        cin>>s>>e;
        pq.push({s,e});
    }
    int bef=0;
    int cnt=0;
    while(!pq.empty()){
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();
        s = max(s, bef);
        if(e<=bef) continue;
        int c = (e-s-1)/L+1;
        cnt += c;
        bef = s + c*L; 
    }
    cout<<cnt;
}