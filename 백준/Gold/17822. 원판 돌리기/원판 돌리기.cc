#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector<vector<int>> board;
typedef pair<int, int> pii;
int N, M, T;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
void rotate(int r, int d, int t){
    vector<int> nrow = board[r];
    if(!d){
        for(int i=1;i<=M;i++){
            int nextc = i + t;
            if(nextc>M) nextc -= M;
            nrow[nextc] = board[r][i];
        }
    }
    else{
        for(int i=1;i<=M;i++){
            int nextc = i-t;
            if(nextc<1) nextc += M;
            nrow[nextc] = board[r][i];
        }
    }
    board[r] = nrow;
}
void check(){
    bool flag=false;
    vector<vector<int>> nboard = board;
    int sum = 0;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sum += board[i][j];
            if(board[i][j]) cnt++;
            for(int k=0;k<4;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr<1||nr>N) continue;
                if(nc<1) nc = M;
                if(nc>M) nc = 1;
                if(board[i][j] && (board[i][j] == board[nr][nc])){
                    nboard[i][j]=nboard[nr][nc]=0;
                    flag=true;
                }
            }
        }
    }
    if(flag) {
        board = nboard;
        return;
    }
    if(!cnt) return;
    double avg = (double)sum / (double)(cnt);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!board[i][j]) continue;
            if(board[i][j] < avg) nboard[i][j]++;
            if(board[i][j] > avg) nboard[i][j]--; 
        }
    }
    board = nboard;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>T;
    board.assign(N+1, vector<int>(M+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<T;i++){
        int r, d, t;
        cin>>r>>d>>t;
        for(int k=r;k<=N;k+=r){
            rotate(k, d, t);
        }
        check();
    }
    int sum = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sum += board[i][j];
        }
    }
    cout<<sum;
}