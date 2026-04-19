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
int N, M, Q;
vector<vector<int>> sum;
vector<vector<int>> board;
vector<vector<int>> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>Q;
    sum.assign(N+1, vector<int>(M+1, 0));
    board.assign(N+1, vector<int>(M+1, 0));
    ans.assign(N+1, vector<int>(M+1, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
            sum[i][j] = board[i][j] + sum[i-1][j];
            ans[i][j] = sum[i][j] + ans[i-1][j-1];
        }
    }
    for(int i=0;i<Q;i++){
        int w, p;
        cin>>w>>p;
        cout<<ans[w][p]<<"\n";
    }
}
