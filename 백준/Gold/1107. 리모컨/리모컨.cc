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
vector<bool> broken(10, false);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        broken[a] = true;
    }
    int res = 500000;
    if(N==0) goto result;
    for(int i=N;i>=0;i--){
        if(i==0){
            if(!broken[0]) res = min(res, 1 + N);
            break;
        }
        int x = i;
        bool flag=true;
        int cnt = 0;
        while(x>0){
            cnt++;
            int y = x%10;
            if(broken[y]){
                flag=false;
            }
            x/=10;
        }
        if(flag){
            res = min(N-i+cnt, res);
            break;
        }
    }
    for(int i=N;i<N+499894;i++){
        int x = i;
        bool flag=true;
        int cnt = 0;
        while(x>0){
            cnt++;
            int y = x%10;
            if(broken[y]){
                flag=false;
            }
            x/=10;
        }
        if(flag){
            res = min(i-N+cnt, res);
            break;
        }
    }
    result:
    for(int i=0;i<10;i++){
        if(!broken[i]){
            res = min(res, abs(N-i) + 1);
        }
    }
    res=min(res, abs(N-100));
    cout<<res;
}