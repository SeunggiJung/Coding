#include <string>
#include <vector>

using namespace std;
vector<vector<long long>> comb(301, vector<long long>(301));
int mod = 10000019;
void init(int R){
    for(int i=0;i<=R;i++){
        comb[i][0] = 1;
        for(int j=1;j<=i;j++){
            comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
}
int solution(vector<vector<int>> a) {
    int R = a.size();
    int C = a[0].size();
    init(R);
    vector<int> cnt(C, 0);
    for(int i=0;i<C;i++){
        for(int j=0;j<R;j++){
            if(a[j][i]) cnt[i]++;
        }
    }
    vector<long long> dp(R + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < C; i++) {
        int K = cnt[i];
        vector<long long> ndp(R + 1, 0);
        
        for(int j=0;j<=R;j++) {
            if(dp[j]==0) continue;
            for(int k=0;k<=K;k++) {
                if(k>j) break;
                if(K-k>R-j) continue;
                int odd = (j-k)+(K-k);
                long long cases = (comb[j][k]*comb[R-j][K-k])%mod;
                long long total_cases = (dp[j]*cases)%mod;
                ndp[odd] = (ndp[odd] + total_cases) % mod;
            }
        }
        dp = ndp;
    }
    return dp[0];
}