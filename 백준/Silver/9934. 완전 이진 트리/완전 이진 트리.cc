#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
vector<int> nodes(11);
vector<int> node;
vector<vector<int>> d_ns(11);
void tree(int depth, int start){
    if(depth==0) return;
    int mid = start + nodes[depth] / 2;
    d_ns[depth].push_back(node[mid]);
    tree(depth-1, start);
    tree(depth-1, mid+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    nodes[1] = 1;
    for(int i=2;i<=10;i++){
        nodes[i] = nodes[i-1]*2 + 1;
    }
    cin>>N;
    for(int i=0;i<nodes[N];i++){
        cin>>M;
        node.push_back(M);
    }
    tree(N, 0);
    for(int i=N;i>0;i--){
        for(int x : d_ns[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
