#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N;
void stop(){
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> dp(31, 0);
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4;i<=30;i++){
        dp[i] += dp[i-2] * 3;
        for(int j=i-4;j>=0;j-=2){
            dp[i] += dp[j]*2;
        }
    }
    cout<<dp[N];
}
