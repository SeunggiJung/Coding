#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> work(N);
    vector<bool> dp(7, false);
    dp[0] = true;
    for(int i=0;i<N;i++){
        cin>>work[i];
        int w = work[i] % 7;
        if(!w) continue;
        vector<bool> ndp = dp;
        for(int j=0;j<7;j++){
            if(dp[j]) ndp[(j+w)%7] = true;
        }
        dp = ndp;
    }
    if(dp[4]) cout<<"YES";
    else cout<<"NO";
}