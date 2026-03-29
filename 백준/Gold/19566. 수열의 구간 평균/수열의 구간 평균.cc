#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
long long N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K;
    long long nsum = 0;
    map<long long, long long> m;
    long long cnt = 0;
    for(int i=1;i<=N;i++){
        long long x;
        cin>>x;
        nsum += x;
        long long goal = i*K;
        long long diff = nsum - goal;
        if(!diff) cnt++;
        cnt += m[diff];
        m[diff]++;
    }
    cout<<cnt;
}