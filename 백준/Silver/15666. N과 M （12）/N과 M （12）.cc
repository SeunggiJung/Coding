#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<int> num;
vector<int> visited;
map<vector<int>, bool> m;
void bt(int depth, vector<int> v, int index){
    if(depth==M){
        if(!m[v]){
            m[v] = true;
            for(int i : v) cout<<i<<" ";
            cout<<"\n";
        }
        return;
    }
    for(int i=index;i<num.size();i++){
        vector<int> tmp = v;
        tmp.push_back(num[i]);
        bt(depth+1, tmp, i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    num.resize(N);
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());
    visited.assign(num.size(), false);
    bt(0,{},0);
}
