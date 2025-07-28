#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt = 0;
    vector<int> x;
    for (int i = 666; i < 3000000; i++) {
        string s = to_string(i);
        bool flag = false;
        for (int j = 0; j < s.length() - 2; j++) {
            string y=s.substr(j, 3);
            if (y == "666") flag = true;
        }
        if (flag) x.push_back(i);
    }
    cin >> N;
    cout << x[N-1];
}