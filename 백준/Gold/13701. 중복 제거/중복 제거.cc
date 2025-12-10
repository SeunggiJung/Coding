#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bitset<33554432> bs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num;
    while(cin>>num){
        if(cin.eof())  break;
        if(!bs[num]){
            cout<<num<<" ";
            bs[num] = 1;
        }
    }
}