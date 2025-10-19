#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    v.assign(N, 0);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    vector<int> dp(N,1);
    int ans=2001;
    for(int i=0;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(v[j]>v[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = min(ans, N-dp[i]);
    }
    cout<<ans;
}