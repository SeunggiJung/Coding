#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    vector<int> cnt(N+1, 0);
    map<int, vector<int>> st; // smaller than
    for(int i=0;i<M;i++){
        int A, B;
        cin>>A>>B;
        cnt[B]++;
        st[A].push_back(B);
    }
    queue<int> q; // first : who, second : cur_cnt
    for(int i=1;i<=N;i++){
        if(!cnt[i]) q.push(i);
    }
    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        for(int next : st[n]){
            if(cnt[next]<1) continue;
            cnt[next]--;
            if(!cnt[next]) q.push(next);
        }
    }
}