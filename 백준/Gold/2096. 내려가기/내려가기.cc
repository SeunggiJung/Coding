#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> board(3);
    vector<int> maxis(3, 0);
    vector<int> minis(3, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[j];
        }
        vector<int> nmax(3, 0);
        vector<int> nmin(3, 30);
        nmax[0] = board[0] + max(maxis[0], maxis[1]);
        nmax[1] = board[1] + max(maxis[0], max(maxis[1], maxis[2]));
        nmax[2] = board[2] + max(maxis[1], maxis[2]);

        nmin[0] = board[0] + min(minis[0], minis[1]);
        nmin[1] = board[1] + min(minis[0], min(minis[1], minis[2]));
        nmin[2] = board[2] + min(minis[1], minis[2]);
        maxis = nmax;
        minis = nmin;
    }
    cout << max(maxis[0], max(maxis[1], maxis[2])) << " " << min(minis[0], min(minis[1], minis[2]));
}