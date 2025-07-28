#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
map<char, bool> visited;
int maxi = 0;
vector<string> words;
void bt(char start, int depth) {
    if (depth == M) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            bool flag = false;
            for (int j = 0; j < words[i].length(); j++) {
                if (!visited[words[i][j]]) flag = true;
            }
            if (!flag) cnt++;
        }
        maxi = max(cnt, maxi);
        return;
    }
    for (char c = start; c <= 'z'; c++) {
        if (visited[c]) continue;
        visited[c] = true;
        bt(c+1,depth + 1);
        visited[c] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited['a'] = true;
    visited['n'] = true;
    visited['t'] = true;
    visited['i'] = true;
    visited['c'] = true;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        string a = in.substr(4, in.length() - 8);
        words.push_back(a);
    }
    if (M < 5) {
        cout << 0;
        return 0;
    }
    bt('b', 5);
    cout << maxi;
}