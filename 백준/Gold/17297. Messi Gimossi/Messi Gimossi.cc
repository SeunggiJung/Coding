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
int N, M;
string one = " Messi";
string two = " Messi Gimossi";
vector<long long> dp(41, 0);
void dc(int loc, int level){
    if(level==1){
        cout<<one[loc];
        return;
    }
    if(level==2){
        if(two[loc]==' ') cout<<"Messi Messi Gimossi";
        else cout<<two[loc];
        return;
    }
    if(loc == dp[level-1] + 1){
        cout<<"Messi Messi Gimossi";
        return;
    }
    if(loc > dp[level-1]){
        dc(loc - (dp[level-1] + 1), level-2);
    }
    else{
        dc(loc, level-1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[1] = 5;
    dp[2] = 13;
    for(int i=3;i<=40;i++){
        dp[i] = dp[i-1] + dp[i-2] + 1;
    }
    cin>>N;
    for(int i=1;i<=40;i++){
        if(N<=dp[i]){
            dc(N, i);
            break;
        }
    }
}
