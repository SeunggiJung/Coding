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
    string a;
    int b,c;
    vector<pair<string, string>> v;
    while(true){
        cin>>a>>b>>c;
        if(a[0] == '#') break;
        if(b>17 || c>=80){
            v.push_back({a, "Senior"});
        }
        else{
            v.push_back({a, "Junior"});
        }
    }
    for(auto a : v){
        cout<<a.first<<" "<<a.second<<"\n";
    }
}