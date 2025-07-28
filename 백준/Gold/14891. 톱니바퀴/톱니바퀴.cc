#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N;
vector<vector<int>> wheel;
map<pair<int, int>, int> link;
void rotate(int num, int direction) {
    vector<int> nw(8);
    int di = 1;
    if (direction == -1) di = 7;
    for (int i = 0; i < 8; i++) {
        nw[(i + di) % 8] = wheel[num][i];
    }
    wheel[num] = nw;
    if (num != 0) {
        if (link[{num - 1, num}]) {
            link[{num - 1, num}] = 0;
            rotate(num - 1, -direction);
        }
    }
    if (num != 3) {
        if (link[{num, num + 1}]) {
            link[{num, num + 1}] = 0;
            rotate(num + 1, -direction);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    wheel = vector<vector<int>>(4, vector<int>(8));
    for (int i = 0; i < 4; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < 8; j++) {
            wheel[i][j] = in[j] - '0';
        }
    }
    vector<int> move;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < 3; i++) {
            if (wheel[i][2] != wheel[i + 1][6]) link[{i,i+1}] = 1;
        }
        int n, di;
        cin >> n >> di;
        rotate(n - 1, di);
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0])
            sum += pow(2, i);
    }
    cout << sum;
}