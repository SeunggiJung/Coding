#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N;
vector<vector<long long>> dp(53, vector<long long>(53, 0));
long long comb(int n, int r){
    if(r < 0 || r > n) return 0;
    if(r == 0 || r == n) return 1;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = (comb(n-1, r-1) + comb(n-1, r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    if(N<4){
        cout<<0;
        return 0;
    }
    int t = N/4;
    int cur=1;
    long long res = 0;
    while(cur<=t){
        long long x = comb(13, cur) * comb(52-cur*4, N-cur*4);
        if(cur%2==0) x*=-1;
        res += x;
        cur++;
    }
    cout<<res%10007;
}