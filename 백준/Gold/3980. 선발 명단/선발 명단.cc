#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int T;
vector<vector<int>> player(11, vector<int>(11));
vector<int> visited;
int maxi;
void bt(int depth){
    if(depth==11){
        int sum = 0;
        for(int i=0;i<11;i++) {
            sum += visited[i];
        }
        maxi = max(sum, maxi);
        return;
    }
    for(int i=0;i<11;i++){
        if(visited[i]) continue;
        if(!player[depth][i]) continue;
        visited[i] = player[depth][i];
        bt(depth+1);
        visited[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T-->0){
        maxi = 0;
        visited.assign(11, 0);
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                cin>>player[i][j];
            }
        }
        bt(0);
        cout<<maxi<<"\n";
    }
}