#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
static int mi, zero, pl;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void func(vector<vector<int>> v) {
    int ok = v[0][0];
    if (v.size() == 1) {
        switch (ok) {
        case -1:
            mi++;
            break;
        case 0:
            zero++;
            break;
        case 1:
            pl++;
            break;
        }
        return;
    }
    bool flag = true;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] != ok) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        switch (ok) {
        case -1:
            mi++;
            break;
        case 0:
            zero++;
            break;
        case 1:
            pl++;
            break;
        }
        return;
    }
    else {
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                vector<vector<int>>new_v(v.size() / 3, vector<int>(v.size() / 3));
                for (int i = 0; i < v.size() / 3; i++) {
                    for (int j = 0; j < v.size() / 3; j++) {
                        new_v[i][j] = v[i+k*v.size()/3][j+l*v.size()/3];
                    }
                }
                func(new_v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mi = 0, zero = 0, pl = 0;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    func(v);
    cout << mi << "\n" << zero << "\n" << pl;
}