#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int INF = 99999999;
vector<pii> ac;
vector<int> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    ac.assign(N, {});
    int sum=0;
    int ans=INF;
    dp.assign(M + 1, INF);
    dp[0]=0;
    for(int i=0;i<N;i++){
        cin>>ac[i].first;
        sum+=ac[i].first;
    }
    for(int i=0;i<N;i++){
        cin>>ac[i].second;
        for(int j=M-1;j>=0;j--){
            if(dp[j]==INF) continue;
            if(ac[i].first+j>=M){
                ans = min(ans, dp[j] + ac[i].second);
                continue;
            }
            dp[ac[i].first+j] = min(dp[ac[i].first+j], dp[j] + ac[i].second);
        }
    }
    cout<<ans;
}

