#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector<vector<char>> board;
typedef pair<int, int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
/*
1. 사방 탐색 구현
1-1. 상하좌우에 따라 먼저 움직여야 하는 구슬 체크
2. 방문 처리?
4차원짜리 빨, 파 구슬 동시 처리
3. 큐
빨, 파
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N, vector<char>(M));
    pii red, blue;
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        for(int j=0;j<M;j++){
            board[i][j] = in[j];
            if(in[j]=='R') red = {i,j};
            if(in[j]=='B') blue = {i,j};
        }
    }
    vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M, false))));
    // 빨r, 빨c, 파r, 파c
    int time = 0;
    queue<vector<int>> q;
    q.push({red.first, red.second, blue.first, blue.second});
    while(!q.empty()){
        int qs = q.size();
        for(int t=0;t<qs;t++){
            int redr = q.front()[0], redc = q.front()[1];
            int bluer = q.front()[2], bluec = q.front()[3];
            q.pop();
            visited[redr][redc][bluer][bluec] = true;
            for(int i=0;i<4;i++){
                queue<vector<int>> rb;
                if(i==0){
                    if(redr<bluer){
                        rb.push({bluer, bluec, 1});
                        rb.push({redr, redc, 0});
                    }
                    else{
                        rb.push({redr, redc, 0});
                        rb.push({bluer, bluec, 1});
                    }
                }
                if(i==1){
                    if(redr>bluer){
                        rb.push({bluer, bluec, 1});
                        rb.push({redr, redc, 0});
                    }
                    else{
                        rb.push({redr, redc, 0});
                        rb.push({bluer, bluec, 1});
                    }
                }
                if(i==2){
                    if(redc>bluec){
                        rb.push({bluer, bluec, 1});
                        rb.push({redr, redc, 0});
                    }
                    else{
                        rb.push({redr, redc, 0});
                        rb.push({bluer, bluec, 1});
                    }
                }
                if(i==3){
                    if(redc<bluec){
                        rb.push({bluer, bluec, 1});
                        rb.push({redr, redc, 0});
                    }
                    else{
                        rb.push({redr, redc, 0});
                        rb.push({bluer, bluec, 1});
                    }
                }
                int n_redr = redr, n_redc = redc;
                int n_bluer = bluer, n_bluec = bluec;

                for(int j=0;j<2;j++){
                    int r = rb.front()[0];
                    int c = rb.front()[1];
                    int rorb = rb.front()[2];
                    rb.pop();
                    
                    int nr = r, nc = c;
                    while(true){
                        int nnr = nr + dr[i];
                        int nnc = nc + dc[i];
                        if(board[nnr][nnc] == '#') break;
                        if(board[nnr][nnc] == 'O'){
                            nr = nnr; nc = nnc;
                            break;
                        }
                        if(rorb == 0 && nnr == n_bluer && nnc == n_bluec && board[n_bluer][n_bluec] != 'O') break;
                        if(rorb == 1 && nnr == n_redr && nnc == n_redc && board[n_redr][n_redc] != 'O') break;
                        nr = nnr; nc = nnc;
                    }
                    if(rorb == 0) { n_redr = nr; n_redc = nc; }
                    else { n_bluer = nr; n_bluec = nc; }
                }

                if(board[n_bluer][n_bluec] == 'O') continue;
                if(board[n_redr][n_redc] == 'O'){
                    cout << time + 1;
                    return 0;
                }
                if(!visited[n_redr][n_redc][n_bluer][n_bluec]){
                    visited[n_redr][n_redc][n_bluer][n_bluec] = true;
                    q.push({n_redr, n_redc, n_bluer, n_bluec});
                }
            }
        }
        time++;
        if(time>=10){
            cout<<-1;
            return 0;
        }
    }
    cout<<-1;
}