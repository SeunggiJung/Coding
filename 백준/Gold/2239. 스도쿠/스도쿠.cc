#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii; 
vector<vector<int>> board(9, vector<int>(9));
vector<vector<bool>> box(9, vector<bool>(10, false)); // 왼쪽 위부터 1,2,3 ~ 9번 박스에 1~9까지의 숫자 체크
vector<vector<bool>> row(9, vector<bool>(10, false)); // 행에 해당 숫자가 있는지
vector<vector<bool>> col(9, vector<bool>(10, false)); // 열에 해당 숫자가 있는지
bool flag = false;
int N;
void bt(int r, int c) {
    if (flag) return;
    if (r == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        flag = true;
        return;
    }
    int next_r = c + 1 == 9 ? r + 1 : r;
    int next_c = c + 1 == 9 ? 0 : c + 1;
    int box_num = (r / 3 * 3) + c / 3;
    bool flag = false;
    if (board[r][c]) {
        bt(next_r, next_c);
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (box[box_num][i]) continue;
            if (row[r][i]) continue;
            if (col[c][i]) continue;
            flag = true;
            box[box_num][i] = true;
            row[r][i] = true;
            col[c][i] = true;
            board[r][c] = i;
            bt(next_r, next_c);
            board[r][c] = 0;
            box[box_num][i] = false;
            row[r][i] = false;
            col[c][i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    for (int i = 0; i < 9; i++) {
        cin >> input;
        for (int j = 0; j < 9; j++) {
            board[i][j] = (input[j] - '0');
            if (board[i][j]) {
                box[(i / 3 * 3) + j / 3][board[i][j]] = true;
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
            }
        }
    }
    bt(0, 0);
}
