#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<int> train;
vector<int> sums;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    train.resize(N+1, 0);
    sums.resize(N+1, 0);
    vector<int> dp(N+1,0); // dp[a] = 1 ~ a 까지 M칸의 최대값
    vector<int> rev(N+1, 0); // rev[a] = N ~ a 까지 M칸의 최대값
    for(int i=1;i<=N;i++){
        cin>>train[i];
        sums[i] = sums[i-1] + train[i];
    }
    cin>>M;
    for(int i=M;i<=N;i++){
        dp[i] = max(dp[i-1], sums[i] - sums[i-M]);
    }
    for(int i=N-M+1;i>0;i--){
        rev[i] = max(rev[i+1], sums[i+M-1]-sums[i-1]);
    }
    int maxi = 0;
    for(int i=2*M;i<N-M+1;i++){
        int mid = sums[i] - sums[i-M];
        int left = dp[i-M];
        int right = rev[i+1];
        maxi = max(maxi, left + mid + right);
    }
    cout<<maxi;
}
