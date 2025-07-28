#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
static int N, M;
vector<vector<int>> v;
vector<vector<bool>> visited;
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
map<pair<int, int>, int> m;
static int minsum;
void bt(vector<pair<int, int>> ck, int index) {
    if (ck.size() == M) {
        int sum = 0;
        for (auto& home : homes) {
            int mini = 99999;
            for (auto& chicken : ck) {
                int diff = abs(chicken.first - home.first) + abs(chicken.second - home.second);
                mini = min(mini, diff);
            }
            sum += mini;
        }
        minsum = min(sum, minsum);
    }
    for (int i = index; i < chickens.size(); i++) {
        if (visited[chickens[i].first][chickens[i].second]) continue;
        visited[chickens[i].first][chickens[i].second] = true;
        ck.push_back(chickens[i]);
        bt(ck, i + 1);
        ck.pop_back();
        visited[chickens[i].first][chickens[i].second] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2)chickens.push_back({ i,j });
            if (v[i][j] == 1)homes.push_back({ i,j });
        }
    }
    minsum = 99999;
    vector<pair<int, int>> ck;
    bt(ck, 0);
    cout << minsum;
}