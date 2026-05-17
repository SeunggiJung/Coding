#include <string>
#include <vector>
using namespace std;
vector<vector<char>> board;
int dr[] = {1,0,0,-1};
int dc[] = {0,-1,1,0};
char d[] = {'d', 'l', 'r', 'u'};
bool flag = false;
string answer = "impossible";
int N, M, R, C;
int K;
void dfs(int depth, int r, int c, string route){
    if(flag) return;
    if(depth==K){
        if(board[r][c]=='E') {
            answer=route;
            flag = true;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr==0||nc==0||nr>N||nc>M) continue;
        if(depth + 1 + abs(nr - R) + abs(nc-C) > K) continue;
        string nroute = route;
        nroute.push_back(d[i]);
        dfs(depth+1, nr, nc, nroute);
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    int min_dist = abs(x - r) + abs(y - c);
    if (min_dist > k || (k - min_dist) % 2 != 0) return "impossible";
    N=n;M=m;K = k;R=r;C=c;
    board.assign(n+1, vector<char>(m+1, '.'));
    board[x][y] = 'S';
    board[r][c] = 'E';
    dfs(0, x, y, "");
    return answer;
}