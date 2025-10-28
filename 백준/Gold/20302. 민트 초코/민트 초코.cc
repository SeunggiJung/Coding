#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
vector<bool> isprime(100001, true);
vector<int> primes;
vector<int> ps(100001, 0);
vector<int> mp(100001,0);
map<int, vector<int>> fs;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    isprime[0]=isprime[1] = false;
    for(int i=2;i<=sqrt(100000);i++){
        if(!isprime[i]) continue;
        for(int j=2;j*i<=100000;j++){
            isprime[i*j]=false;
            if(mp[i*j]) continue;
            mp[i*j] = i;
        }
    }
    for(int i=2;i<=100000;i++){
        if(isprime[i]) {
            primes.push_back(i);
            fs[i] = {i};
            continue;
        }
        int num = i;
        fs[i] = {};
        int p = mp[i];
        fs[i].push_back(p);
        for(int x : fs[num/p]){
            fs[i].push_back(x);
        }
    }
    cin>>N;
    bool iszero=false;
    for(int i=0;i<N;i++){
        char op = '*';
        int num;
        if(i) cin>>op;
        cin>>num;
        if(!num){
            iszero=true;
            continue;
        }
        num = abs(num);
        if(num==1) continue;
        for(int x : fs[num]){
            if(op=='*') ps[x]++;
            else ps[x]--;
        }
    }
    if(iszero){
        cout<<"mint chocolate\n";
        return 0;
    }
    bool flag=true;
    for(int i=2;i<=N;i++){
        if(ps[i]<0){
            flag= false;
            break;
        }
    }
    if(!flag) cout<<"toothpaste\n";
    else cout<<"mint chocolate\n";
}