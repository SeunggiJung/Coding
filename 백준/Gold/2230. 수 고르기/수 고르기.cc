#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M;
vector<vector<int>> board;
int cnt=0;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int mini = INT32_MAX;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int left = 0, right = 1;
    while (left <= right) {
        if (right == N) {

            break; 
        }
        if (v[right] - v[left] >= M) {
            mini = min(v[right] - v[left], mini);
            while (true) {
                left++;
                if (v[right] - v[left] < M) {
                    mini = min(v[right] - v[left - 1], mini);
                    break;
                }
            }
        }
        right++;
    }
    cout << mini;
}
