#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(int n, vector<int> tops) {
    int N = n*2 + 1;
    vector<int> dp(N, 0);
    dp[0] = 1;
    dp[1] = 2;
    if(tops[0]) dp[1]++;
    for(int i=2;i<N;i++){
        dp[i] = dp[i-1] + dp[i-2];
        if(i%2==1 && tops[i/2]==1) dp[i] += dp[i-1];
        dp[i] %= 10007;
    }
    int answer = dp[N-1];
    return answer;
}