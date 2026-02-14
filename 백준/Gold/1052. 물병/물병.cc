#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int p = 1;
    // while(pow(2,p)<10000000){
    //     p++;
    // }
    // cout<<pow(2,p-1)<<" "<<p-1;
    vector<int> b(24, 0);
    cin>>N>>K;
    while(N>0){
        int p=0;
        while((1<<p) <= N){
            p++;
        }
        p--;
        if(p<0) p=0;
        b[p] = 1;
        N-=(1<<p);
    }
    int cnt = 0;
    for(int a : b){
        if(a) cnt++;
    }
    int ecnt = 0;
    while(cnt>K){
        ecnt++;
        b[0]++;
        int idx = 0;
        while(b[idx]>=2){
            b[idx] = 0;
            b[idx+1]++;
            idx++;
        }
        cnt = 0;
        for(int a : b) if(a) cnt++;
        if(cnt==25){
            cout<<-1;
            exit(0);
        }
    }
    cout<<ecnt;
}