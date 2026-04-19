#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int I, N, K;
vector<char> ink;
vector<vector<char>> board;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>I>>N>>K;
    board.resize(N, vector<char>(N));
    string in;
    cin>>in;
    pii start;
    for(int i=0;i<I;i++){
        ink.push_back(in[i]);
    }
    for(int i=0;i<N;i++){
        cin>>in;
        for(int j=0;j<N;j++){
            board[i][j] = in[j];
            if(board[i][j]=='@'){
                start = {i,j};
                board[i][j] = '.';
            }
        }
    }
    int curink = 0;
    char curcol = ink[0];
    string com;
    pii cur = start;
    cin>>com;
    int cnt = 0;
    for(char c : com){
        int R = cur.first;
        int C = cur.second;
        int d = 5;
        if(c =='U') d = 0;
        else if(c=='D') d=1;
        else if(c=='L') d=2;
        else if(c=='R') d=3;
        if(d<4){
            int nr = R + dr[d];
            int nc = C + dc[d];
            if(nr<0||nc<0||nr>=N||nc>=N) continue;
            if(board[nr][nc]!='.') continue;
            cur = {nr, nc};
            continue;
        }
        if(c=='j'){
            curink++;
            continue;
        }
        if(c=='J'){
            for(int i = R-curink;i<=R+curink;i++){
                for(int j=C-curink;j<=C+curink;j++){
                    if(i<0||j<0||i>=N||j>=N) continue;
                    if(board[i][j]=='.') continue;
                    if(abs(R-i) + abs(C-j) > curink) continue;
                    board[i][j] = curcol;
                }            
            }
            cnt++;
            curink = 0;
            curcol = ink[cnt%I];
        }
    }
    board[cur.first][cur.second] = '@';
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}