#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<int> out;
static vector<bool> kn;
static int max_value;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

int parent(int child) {
    if (v[child][0] == child) return child;
    else {
        v[child][0] = parent(v[child][0]);
        return v[child][0];
    }
}
void uni(int a, int b) {
    if (a < b) {
        v[parent(b)][0] = v[parent(a)][0];
    }
    else {
        v[parent(a)][0] = v[parent(b)][0];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<int>>(N+1, vector<int>(1));
    for (int i = 1; i <= N; i++) {
        v[i][0] = i;
    }
    int know;
    cin >> know;
    kn = vector<bool> (N + 1,false);
    for (int i = 0; i < know; i++) {
        int k;
        cin >> k;
        kn[k] = true;
    }
    vector<vector<int>> party(M);
    for (int i = 0; i < M; i++) {
        int people;
        cin >> people;
        for (int j = 0; j < people; j++) {
            int in;
            cin >> in;
            party[i].push_back(in);
        }
        for (int j = 0; j < people - 1; j++) {
            if(kn[v[parent(party[i][j + 1])][0]])
                v[parent(party[i][j])][0] = v[parent(party[i][j+1])][0];
            else
                v[parent(party[i][j+1])][0] = v[parent(party[i][j])][0];
        }
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        bool flag = false;
        for (int j = 0; j < party[i].size(); j++) {
            if (kn[parent(party[i][j])]) {
                flag = true;
            }
        }
        if (!flag)cnt++;
    }
    cout << cnt;
}
