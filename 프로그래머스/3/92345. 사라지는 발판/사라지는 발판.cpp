#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int rs, cs;
pair<bool, int> dfs(vector<vector<int>>& board, int ax, int ay, int bx, int by) {
    if (!board[ax][ay]) return {false, 0};
    
    bool can_move = false;
    int maxi = 0;
    int mini = INT_MAX;
    
    board[ax][ay] = 0;
    
    for (int i = 0; i < 4; i++) {
        int nx = ax + dx[i];
        int ny = ay + dy[i];
        
        if (nx < 0 || nx >= rs || ny < 0 || ny >= cs) continue;
        if (board[nx][ny] == 0) continue;
        
        can_move = true;
        
        pair<bool, int> res = dfs(board, bx, by, nx, ny);
        bool op_win = res.first;
        int op_move = res.second;
        
        if (!op_win) mini = min(mini, op_move + 1);
        else maxi = max(maxi, op_move + 1);
    }
    
    board[ax][ay] = 1;
    
    if (!can_move) return {false, 0};
    
    if (mini != INT_MAX) return {true, mini};
    else return {false, maxi};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    rs = board.size();
    cs = board[0].size();
    
    pair<bool, int> answer = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]);
    return answer.second;
}