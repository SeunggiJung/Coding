#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <random>
using namespace std;
static int N;
static vector<vector<int>> v;
static vector<vector<bool>> visited;
static vector<vector<bool>> pref;
int cnt;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    N = 0;
    cin >> N;
    v = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    pref = vector<vector<bool>>(N * N + 1, vector<bool>(10));
    vector<bool> like;
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    for (int i = 1; i <= N * N; i++) {
        int num;
        like = vector<bool> (N*N+1,false);
        cin >> num;
        for (int j = 0; j < 4; j++) {
            int l;
            cin >> l;
            like[l] = true;
        }
        pref[num] = like;
        if (i == 1) {
            v[2][2] = num; continue;
        }
        int empty;
        int maxe = -1;
        int maxi=-1;
        int r=0, c=0;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (v[j][k]) {
                    continue;
                }
                empty = 0;
                cnt = 0;
                for (int l = 0; l < 4; l++) {
                    int nr = j + dr[l];
                    int nc = k + dc[l];
                    if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
                    if (!v[nr][nc]) empty++;
                    if (like[v[nr][nc]]) cnt++;
                }
                if (cnt > maxi || (cnt == maxi && empty > maxe)) {
                    r = j;
                    c = k;
                    maxi = cnt;
                    maxe = empty;
                }
            }
        }
        v[r][c] = num;
    }
    int r, c;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
                if (pref[v[i][j]][v[nr][nc]]) cnt++;
            }
            if (cnt == 0) continue;
            else sum += pow(10, cnt - 1);
        }
    }
    cout << sum;
}
