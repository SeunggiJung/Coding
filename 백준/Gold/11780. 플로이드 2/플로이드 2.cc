#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<vector<pii>> bus;
vector<vector<int>> board;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    bus.assign(N+1, vector<pii>(N+1, {10000001, 0}));
    for(int i=0;i<M;i++){
        int s, e, c;
        cin>>s>>e>>c;
        if(bus[s][e].first > c){
            bus[s][e] = {c, s};
        }
    }
    for(int k=0;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j) {bus[i][j].first = 0; continue;}
                if(bus[i][j].first>bus[i][k].first + bus[k][j].first){
                    bus[i][j] = {bus[i][k].first + bus[k][j].first, bus[k][j].second};
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(bus[i][j].first==10000001) bus[i][j].first = 0;
            cout<<bus[i][j].first<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(bus[i][j].first==0) {cout<<"0\n"; continue;}
            vector<int> route = {j};
            int cur = j;
            while(cur!=i){
                cur = bus[i][cur].second;
                route.push_back(cur);
            }
            cout<<route.size()<<" ";
            while(!route.empty()){
                cout<<route.back()<<" ";
                route.pop_back();
            }
            cout<<"\n";
        }
    }
}
