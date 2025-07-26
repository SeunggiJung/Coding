#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<string>> v(51);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        int len = in.length();
        v[len].push_back(in);
    }
    for (int i = 0; i <= 50; i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        int len = v[i].size();
        for (int j = 0; j < len; j++) {
            cout << v[i][j] << "\n";
        }
    }
}