#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<vector<int>>> origin_board(5, vector<vector<int>>(5, vector<int>(5)));
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int ans = 126;
vector<int> layer_dir(5);
vector<int> order = { 0,1,2,3,4 };
vector<vector<int>> rotate(vector<vector<int>> &piece) {
    vector<vector<int>> rotated(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            rotated[j][4 - i] = piece[i][j];
        }
    }
    return rotated;
}
void bfs(const vector<vector<vector<int>>> &board) {
    vector<vector<vector<int>>> visited(5, vector<vector<int>>(5, vector<int>(5, 0)));
    queue<vector<int>> q; // x,y,z
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int z = q.front()[2];
        q.pop();
        if (x == 4 && y == 4 && z == 4) {
            ans = min(ans, visited[x][y][z]);
            break;
        }
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if (visited[nx][ny][nz]) continue;
            if (board[nx][ny][nz] == 0) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({ nx,ny,nz });
        }
    }
}
void permu(int layer) {
    if (layer==5) {
        vector<vector<vector<int>>> board(5, vector<vector<int>>(5, vector<int>(5)));
        for (int i = 0; i < 5; i++) {
            vector<vector<int>> temp = origin_board[order[i]];
            for (int j = 0; j < layer_dir[i]; j++) {
                temp = rotate(temp);
            }
            board[i] = temp;
        }
        if (!board[0][0][0] || !board[4][4][4]) return;
        bfs(board);
        return;
    }
    for (int i = 0; i < 4; i++) {
        layer_dir[layer] = i;
        permu(layer + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> origin_board[i][j][k];
            }
        }
    }
    do {
        permu(0);
    } while (next_permutation(order.begin(), order.end()));

    if (ans == 126) cout << -1;
    else cout << ans;
}