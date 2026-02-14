#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, int> pdi;
vector<int> popul;
vector<bool> visited;
map<int, vector<int>> m;
int sum = 0;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> weight(N);
    for(int i=0;i<N;i++){
        cin>>weight[i];
    }
    sort(weight.rbegin(), weight.rend());
    vector<bool> dp(80001, false); //(1~40000 -> -) ~ 80000 -> +
    for(int w : weight){
        vector<bool> ndp = dp;
        ndp[w+40000] = true;
        for(int i=1;i<=80000;i++){
            if(dp[i]){
                if(i+w<=80000) ndp[i+w] = true;
                if(i-w>0) ndp[i-w] = true;
            }
        }
        dp = ndp;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int ch;
        cin>>ch;
        if(dp[ch+40000]) cout<<"Y ";
        else cout<<"N ";
    }
}
