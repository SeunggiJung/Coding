#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> board;
int H, W;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>H>>W;
    int cnt = 0;
    board.assign(H, vector<int>(W, 0));
    for(int i=0;i<W;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            board[H-1-j][i] = 1;
        }
    }
    for(int i=0;i<H;i++){
        if(!board[i][0]){
            for(int j=0;j<W;j++){
                if(board[i][j]) break;
                board[i][j] = 2;
            }
        }
        if(!board[i][W-1]){
            for(int j=W-1;j>=0;j--){
                if(board[i][j]) break;
                board[i][j] = 2;
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(!board[i][j]) cnt++;
        }
    }
    cout<<cnt<<"\n";
}