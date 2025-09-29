#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, D;
vector<vector<int>> r_visited;
vector<vector<int>> c_visited;
vector<vector<int>> board;
bool Sflag = false;
void bt(int r, int c) {
    if (r < N - D || c < N - D) {

    }
    if (r==N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        Sflag = true;
        return;
    }
    int next_r = (c == N - 1) ? r + 1 : r;
    int next_c = (c == N - 1) ? 0 : c + 1;
    for (int i = 0; i < D; i++) {
        board[r][c] = i;
        r_visited[r][i]++;
        c_visited[c][i]++;
        bool able = true;
        int r_miss_cnt = 0;
        for (int j = 0; j < D; j++) {
            if (!r_visited[r][j]) r_miss_cnt++;
        }
        if (r_miss_cnt > N - 1 - c) able = false;
        if (able) {
            int c_miss_cnt = 0;
            for (int j = 0; j < D; j++) {
                if (!c_visited[c][j]) c_miss_cnt++;
            }
            if (c_miss_cnt > N - 1 - r) able = false;
        }
        if (able) bt(next_r, next_c);
        if (Sflag) return;
        r_visited[r][i]--;
        c_visited[c][i]--;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> D;
    r_visited = vector<vector<int>>(N, vector<int>(D, 0));
    c_visited = vector<vector<int>>(N, vector<int>(D, 0));
    board = vector<vector<int>>(N, vector<int>(N, -1));
    bt(0, 0);
}