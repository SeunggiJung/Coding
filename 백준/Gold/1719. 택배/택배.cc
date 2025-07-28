#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
static int N, M, K;
vector<vector<int>> dist;
vector<vector<int>> root;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<vector<int>>(201, vector<int>(201, 0));
    root = vector<vector<int>>(201, vector<int>(201, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = 99999999;
            if (i == j) dist[i][j] = 0;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
        root[a][b] = b;
        root[b][a] = a;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i != k) root[i][j] = root[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (root[i][j]) cout << root[i][j] << " ";
            else cout << "- ";
        }
        cout << "\n";
    }
}