#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    long long ans = 0;
    vector<int> num(N+1);
    vector<int> div(M,0);
    int bef = 0;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        bef = (bef + num[i])%M;
        int d = bef;
        if(!d) ans++;
        ans += div[d];
        div[d]++;
    }
    cout<<ans;
}