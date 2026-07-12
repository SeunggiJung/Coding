#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> visited;
vector<vector<int>> check;
vector<pair<int, pii>> connect;

int find(int a, vector<int>& parent) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a], parent);
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    queue<pii> q;
    int r = land.size();
    int c = land[0].size();
    int idx = 0;
    
    visited.assign(r, vector<int>(c, 0));
    check.assign(r, vector<int>(c, 0));
    connect.clear();
    
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (!visited[i][j]) {
                idx++;
                q.push({i,j});
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    check[x][y] = idx;
                    visited[x][y] = 1;
                    q.pop();
                    for (int k=0;k<4;k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0<=nx&&nx<r&&0<=ny&&ny<c&&!visited[nx][ny]) {
                            if (abs(land[x][y] - land[nx][ny]) <= height) {
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                                check[nx][ny] = idx;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            for (int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0<=nx&&nx<r&&0<=ny&&ny<c) {
                    if (check[i][j] != check[nx][ny]) {
                        connect.push_back({abs(land[i][j] - land[nx][ny]), {check[i][j], check[nx][ny]}});
                    }
                }
            }                
        }
    }
    
    sort(connect.begin(), connect.end());
    vector<int> parent(idx + 1);
    for (int i = 1; i <= idx; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < connect.size(); i++) {
        int x = connect[i].second.first;
        int y = connect[i].second.second;
        int cost = connect[i].first;
        
        int a = find(x, parent);
        int b = find(y, parent);
        
        if (a!=b) {
            parent[a] = b;
            answer += cost;
        }
    }
    return answer;
}