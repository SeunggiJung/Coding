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
vector<int> primes(4000001, true);
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    primes[0] = primes[1] = false;
    vector<int> p;
    for(int i=2;i<=2000;i++){
        if(!primes[i]) continue;
        for(int j = i*2;j<=4000000;j+=i){
            primes[j] = false;
        }
    }
    for(int i=2;i<4000000;i++){
        if(primes[i]) p.push_back(i);
    }
    cin>>N;
    if(N==1){
        cout<<0;
        return 0;
    }
    if(N==2){
        cout<<1;
        return 0;
    }
    int sum = 2;
    int cnt = 0;
    int left=0, right=1;
    while(left<=right){
        if(right==p.size()) break;
        if(p[right]>N) break;
        sum += p[right];
        while(sum>N){
            if(left==right) break;
            sum -= p[left];
            left++;
        }
        if(sum > N){
            cout<<0;
            return 0;
        }
        if(sum == N){
            cnt++;
        }
        right++;
    }
    cout<<cnt;
}