#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
static vector<vector<int>> v;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void printv() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
bool zerocheck() {
    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
            if (v[j][k] == 0) return true;
        }
    }
    return false;
}
void bt(queue<pair<int,int>> q) {
    if (q.empty()) return;
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (v[x][y]) return;
    for (int i = 1; i < 10; i++) {
        bool flag = true;
        
        for (int r = 0; r < 9; r++) {
            if (v[r][y] == i) flag = false;
            //if (v[r][y] == 0 && r!=x) q.push({ r,y });
        }
        for (int c = 0; c < 9; c++) {
            if (v[x][c] == i) flag = false;
            //if (v[x][c] == 0 && c!=y)q.push({ x,c });
        }
        
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (v[x / 3 * 3 + r][y / 3 * 3 + c] == i) flag = false;
                //if (v[x / 3 * 3 + r][y / 3 * 3 + c] == 0 && x / 3 * 3 + r != x && y / 3 * 3 + c != y)q.push({ x / 3 * 3 + r, y / 3 * 3 + c });
            }
        }

        if (flag) {
            v[x][y] = i;
            //printv();
            //cout << "\n";
            bt(q);
            if (!zerocheck()) {
                return;
            }
            v[x][y] = 0;
        }
        else continue;
        //v[x][y] = 0;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    v= vector<vector<int>>(9, vector<int>(9));
    queue<pair<int, int>> q;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> v[i][j];
            if (!v[i][j])
                q.push({ i,j });
        }
    }
    
    bt(q);
    
    printv();
}
