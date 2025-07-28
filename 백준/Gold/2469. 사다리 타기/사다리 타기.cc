#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<bool> visited;
vector<pair<int, int>> ans;
string b, a;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    string goal;
    cin >> goal;
    queue<string> bef;
    vector<string> aft;
    bool flag = false;
    for (int i = 0; i < M; i++) {
        string line;
        cin >> line;
        if (line[0] == '?') {
            flag = true;
            continue;
        }
        if (!flag) bef.push(line);
        else aft.push_back(line);
    }
    string before;
    for (int i = 0; i < N; i++) {
        before.push_back((char)('A' + i));
    }
    while (!bef.empty()) {
        string order = bef.front();
        bef.pop();
        for (int i = 0; i < N - 1; i++) {
            if (order[i] == '-') {
                char tmp = before[i];
                before[i] = before[i + 1];
                before[i + 1] = tmp;
            }
        }
    }
    while (!aft.empty()) {
        string order = aft.back();
        aft.pop_back();
        for (int i = 0; i < N - 1; i++) {
            if (order[i] == '-') {
                char tmp = goal[i];
                goal[i] = goal[i + 1];
                goal[i + 1] = tmp;
            }
        }
    }
    string ans;
    for (int i = 0; i < N - 1; i++) {
        if (before[i] == goal[i + 1] && before[i + 1] == goal[i]) {
            ans.push_back('-'); ans.push_back('*'); i++;
            continue;
        }
        else if (before[i] == goal[i]) {
            ans.push_back('*');
            continue;
        }
        else {
            for (int i = 0; i < N - 1; i++) cout << 'x';
            return 0;
        }
    }
    if(ans.size()==N)ans.pop_back();
    cout << ans;
}