#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, M;
/*
1. 백트래킹을 통해 확인 -> 탈출 타이밍? -> 이전에 나왔던 배열(map) -> 메모리 감당 ㄱㄴ?
2. N행의 합, M열의 합을 기록하는 배열 -> board[N][M] 변경 시 P 배열 체크 용이
*/
vector<int> rowsum;
vector<int> colsum;
vector<vector<int>> board;
vector<bool> rv;
vector<bool> cv;
int mini=INT_MAX;
void rowcon(int r){
    for(int i=0;i<M;i++){
        board[r][i] *= -1;
        rowsum[r] += board[r][i] * 2;
        colsum[i] += board[r][i] * 2;
    }
}
void colcon(int c){
    for(int i=0;i<N;i++){
        board[i][c] *= -1;
        rowsum[i] += board[i][c] * 2;
        colsum[c] += board[i][c] * 2;
    }
}
void bt(int depth){
    if(depth==N){
        int cnt = 0;
        for(int i=0;i<N;i++) if(rv[i]) cnt++;

        vector<bool> tmp(M, false);
        for(int i=0;i<M;i++){
            if(colsum[i]==0) return;
            if(colsum[i]<0){
                tmp[i] = true;
                cnt++;
            }
        }

        for(int i=0;i<N;i++){
            int cur = rowsum[i];
            for(int j=0;j<M;j++){
                if(tmp[j]){
                    cur -= board[i][j] * 2;
                }
            }
            if(cur<=0) return;
        }
        mini = min(mini, cnt);
        return;
    }

    bt(depth + 1);

    rowcon(depth);
    rv[depth] = true;
    bt(depth+1);
    rv[depth] = false;
    rowcon(depth);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    rowsum.assign(N, 0);
    colsum.assign(M, 0);
    board.assign(N, vector<int>(M));
    rv.assign(N, false);
    cv.assign(M, false);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            rowsum[i]+=board[i][j];
            colsum[j]+=board[i][j];
        }
    }
    bt(0);
    if(mini == INT_MAX) cout<<-1;
    else cout<<mini;
}
