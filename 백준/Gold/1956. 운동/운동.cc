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
    vector<vector<long long>> dist(N+1, vector<long long>(N+1, INT_MAX));
    for(int i=0;i<M;i++){
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = c;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    long long mini = INT_MAX;
    for(int i=1;i<=N;i++){
        mini = min(mini, dist[i][i]);
    }
    if(mini == INT_MAX) cout<<-1;
    else cout<<mini;
}