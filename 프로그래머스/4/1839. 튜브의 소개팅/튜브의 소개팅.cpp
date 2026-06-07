#include <climits>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, S;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<vector<vector<int>>> dp;

vector<int> solution(int n, int m, int s, vector<vector<int>> time_map) {
    N = n; M = m; S = s;
    dp.assign(50, vector<vector<int>>(50, vector<int>(2501, INT_MAX)));
    int max_move = N * M;
    queue<vector<int>> q;
    q.push({0, 0, 0, 0});
    dp[0][0][0] = 0;

    int ans = INT_MAX;
    int mini = INT_MAX;

    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int r = cur[0];
        int c = cur[1];
        int move = cur[2];
        int sum = cur[3];

        if (dp[r][c][move] < sum) continue;

        if (r == N - 1 && c == M - 1) {
            if(move < ans){
                ans = move;
                mini = sum;
            }
            else if(move==ans) mini = min(mini, sum);
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nmove = move + 1;

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (time_map[nr][nc] == -1) continue;
            if(INT_MAX - sum < time_map[nr][nc]) continue;
            int nsum = sum + time_map[nr][nc];
            if (nsum > S) continue;

            if (nsum < dp[nr][nc][nmove]) {
                dp[nr][nc][nmove] = nsum;
                q.push({nr, nc, nmove, nsum});
            }
        }
    }

    vector<int> answer(2);
    answer[0] = ans;
    answer[1] = mini;
    return answer;
}