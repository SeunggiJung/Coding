#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector<vector<int>> board;
vector<vector<vector<int>>> visited;
typedef pair<int, int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N, vector<int>(N));
    visited.assign(N, vector<vector<int>>(N, vector<int>(2, 1000001)));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0,0,0,0,0});
    
    vector<vector<vector<vector<int>>>> visited(N, vector<vector<vector<int>>>(N, vector<vector<int>>(2, vector<int>(2, 2000000000))));
    visited[0][0][0][0] = 0;

    while(!q.empty()){
        int time = q.top()[0];
        int r = q.top()[1];
        int c = q.top()[2];
        int b = q.top()[3];
        int prev = q.top()[4];
        q.pop();

        if(visited[r][c][b][prev] < time) continue;

        if(r==N-1 && c==N-1) {
            cout<<time;
            exit(0);
        }

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=N) continue;

            int next_time = time + 1;

            if(board[nr][nc] == 1) {
                if(visited[nr][nc][b][0] > next_time) {
                    visited[nr][nc][b][0] = next_time;
                    q.push({next_time, nr, nc, b, 0});
                }
            }
            else if(board[nr][nc] > 1) {
                if(prev) continue;
                int period = board[nr][nc];
                int can_time = next_time;
                if(can_time % period != 0) {
                    can_time = (time / period + 1) * period;
                }
                if(visited[nr][nc][b][1] > can_time) {
                    visited[nr][nc][b][1] = can_time;
                    q.push({can_time, nr, nc, b, 1});
                }
            }
            else if(board[nr][nc] == 0) {
                if(!b && !prev) {
                    bool v = false, h = false;
                    if((nr-1>=0 && board[nr-1][nc]==0) || (nr+1<N && board[nr+1][nc]==0)) v = true;
                    if((nc-1>=0 && board[nr][nc-1]==0) || (nc+1<N && board[nr][nc+1]==0)) h = true;
                    
                    if(!(v && h)) {
                        int period = M;
                        int can_time = next_time;
                        if(can_time % period != 0) {
                            can_time = (time / period + 1) * period;
                        }
                        if(visited[nr][nc][1][1] > can_time) {
                            visited[nr][nc][1][1] = can_time;
                            q.push({can_time, nr, nc, 1, 1});
                        }
                    }
                }
            }
        }
    }
}