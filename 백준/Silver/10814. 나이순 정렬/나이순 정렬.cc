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
    vector<vector<string>> v(201);
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        v[age].push_back(name);
    }
    for (int i = 1; i <= 200; i++) {
        int len = v[i].size();
        if (!len)continue;
        for (int j = 0; j < len; j++) {
            cout << i << " " << v[i][j] << "\n";
        }
    }
}