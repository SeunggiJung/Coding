#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N, M, K;
struct compare{
    bool operator()(const vector<int> &a, const vector<int> &b){
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];
        return a[2] > b[2];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>K;
    vector<queue<vector<int>>> q(M);
    int line = 0;
    for(int i=0;i<N;i++){
        int day, hurry;
        cin>>day>>hurry;
        q[line].push({day, hurry, line, i});
        line++;
        line %= M;
    }
    int cnt = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    for(int i=0;i<M;i++){
            if(q[i].empty()) continue;
            pq.push(q[i].front());
        }
    while(true){
        if(pq.top()[3] == K){
            cout<<cnt;
            exit(0);
        }
        cnt++;
        int l = pq.top()[2];
        pq.pop();
        q[l].pop();
        if(!q[l].empty()) pq.push(q[l].front());
    }
}
