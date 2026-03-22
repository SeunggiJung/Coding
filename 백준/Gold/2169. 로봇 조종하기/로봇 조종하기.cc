#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<int>> board;
vector<vector<int>> dist;
int dr[] = {0, 0, 1};
int dc[] = {-1, 1, 0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N, vector<int>(M));
    dist.assign(N, vector<int>(M, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    dist[0][0] = board[0][0];
    for(int i=1;i<M;i++){
        dist[0][i] = dist[0][i-1] + board[0][i];
    }
    for(int i=1;i<N;i++){
        vector<int> toleft(M), toright(M);
        toright[0] = dist[i-1][0] + board[i][0];
        for(int j=1;j<M;j++){
            toright[j] = max(toright[j-1], dist[i-1][j]) + board[i][j];
        }

        toleft[M-1] = dist[i-1][M-1] + board[i][M-1];
        for(int j=M-2;j>=0;j--){
            toleft[j] = max(toleft[j+1], dist[i-1][j]) + board[i][j];
        }
        for(int j=0;j<M;j++){
            dist[i][j] = max(toleft[j], toright[j]);
        }
    }
    cout<<dist[N-1][M-1];
}