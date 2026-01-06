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
vector<int> node;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    node.resize(N);
    for(int i=0;i<N;i++){
        cin>>node[i];
    }
    sort(node.begin(), node.end());
    int left = 0;
    int right = node.back() - node[0] + 1;
    while(left+1<right){
        int mid = (left + right) / 2;
        int cnt = 0;
        int cur = 0;
        while(true){
            cnt++;
            if(cnt>=M) break;
            bool flag=false;
            for(int i=cur+1;i<node.size();i++){
                if(node[i] - node[cur] >= mid){
                    cur = i;
                    flag=true;
                    break;
                }
            }
            if(!flag) break;
        }
        if(cnt>=M) left = mid;
        else right = mid;
    }
    cout<<left;
}