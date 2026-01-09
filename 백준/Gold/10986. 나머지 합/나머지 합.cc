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
    long long ans = 0;
    vector<int> num(N+1);
    vector<long long> sum(N+1, 0);
    vector<int> div(M,0);
    for(int i=1;i<=N;i++){
        cin>>num[i];
        sum[i] = sum[i-1] + num[i];
        int d = sum[i] % M;
        if(!d) ans++;
        ans += div[d];
        div[d]++;
    }
    cout<<ans;
}