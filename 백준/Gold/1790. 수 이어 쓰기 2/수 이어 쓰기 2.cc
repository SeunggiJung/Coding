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
    if(M==1){
        cout<<1;
        return 0;
    }
    long long cnt = 1;
    int div = 0;
    vector<int> v = {10,100,1000,10000,100000,1000000,10000000,100000000};
    for(int i=2;i<=N;i++){
        if(i>=v[div]){
            div++;
        }
        cnt+=(div+1);
        if(cnt>=M){
            while(cnt>M){
                cnt--;
                i/=10;
            }
            cout<<i%10;
            return 0;
        }
    }
    cout<<-1;
}