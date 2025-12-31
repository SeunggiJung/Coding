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
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    //vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(2, 0))); //0 : 증가, 1 : 감소
    vector<vector<int>> dp(M+1, vector<int>(2,0));
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int ans=0;
    for(int i=0;i<N;i++){
        vector<vector<int>> tmp(M+1, vector<int>(2,0));
        if(i==0){
            dp[1][0] = v[0];
            continue;
        }
        for(int j=0;j<=M;j++){
            if(j==0){
                tmp[j+1][0] = max(dp[j][0] + v[i], tmp[j+1][0]);
                tmp[j+1][0] = max(dp[j][1] + v[i], tmp[j+1][0]);
                tmp[j][1] = max(dp[j][1], tmp[j][1]);
                continue;
            }
            if(j+1<=M) tmp[j+1][0] = max(dp[j][0] + v[i], tmp[j+1][0]);
            tmp[j-1][1] = max(dp[j][0], tmp[j-1][1]);
            tmp[j-1][1] = max(dp[j][1], tmp[j-1][1]);
        }
        dp = tmp;
    }
    cout<<dp[0][1];
}