#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<vector<bool>> ispal;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    ispal.assign(N+1, vector<bool>(N+1, false));
    v.assign(N+1, 0);
    for(int i=1;i<=N;i++){
        cin>>v[i];
        ispal[i][i] = true;
        for(int j=i;j>0;j--){
            if(ispal[j][i-1]){
                if(j==i-1 && v[j]==v[i]) ispal[j][i] = true;
                if(v[j-1]==v[i]) ispal[j-1][i]=true;
            }
        }
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int S, E;
        cin>>S>>E;
        if(ispal[S][E]) cout<<"1\n";
        else cout<<"0\n";
    }
}
