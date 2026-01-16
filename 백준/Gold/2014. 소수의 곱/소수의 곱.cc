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
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
        pq.push(v[i]);
    }
    while(true){
        int n = pq.top();
        pq.pop();

        s.insert(n);
        if(s.size()==M){
            cout<<n;
            break;
        }
        for(int x : v){
            if(n > INT_MAX/x) continue;
            pq.push(n*x);
            if(n%x==0) break;
        }
    }
}