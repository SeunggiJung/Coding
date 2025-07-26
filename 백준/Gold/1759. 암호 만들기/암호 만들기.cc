#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, T;
vector<char> v;
void bt(int depth, int index, vector<char> pw, int cnt) {
    if (depth == N) {
        if (!cnt || (N - cnt) < 2) return;
        for (int i = 0; i < depth; i++) {
            cout << pw[i];
        }
        cout << "\n";
        return;
    }
    for (int i = index; i < M; i++) {
        pw.push_back(v[i]);
        bool aeiou = false;
        if ((v[i] == 'a') || (v[i] == 'e') || (v[i] == 'i') || (v[i] == 'o') || (v[i] == 'u')) {
            bt(depth + 1, i + 1, pw, cnt + 1);
        }
        else bt(depth + 1, i + 1, pw, cnt);
        pw.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bt(0, 0, vector<char>(), 0);
}