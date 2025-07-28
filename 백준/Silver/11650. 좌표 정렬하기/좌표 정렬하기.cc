#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> v(200001);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v[x+100000].push_back(y+100000);
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].empty())continue;
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); j++) {
            cout << i - 100000 << " " << v[i][j] - 100000 << "\n";
        }
    }
}