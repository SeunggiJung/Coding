#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    vector<int> coins(N);
    vector<int> dp(M+1,0);
    for(int i=0;i<N;i++){
        cin>>coins[i];
        if(coins[i]>M) continue;
    }
    dp[0] = 1;
    for(int coin : coins){
        for(int i=coin;i<=M;i++){
            dp[i]=dp[i]+dp[i-coin];
        }
    }
    cout<<dp[M];
}