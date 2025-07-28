#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
static int N, M;
static int A, B;
void bfs() {
    vector<int> visited(10000);
    queue<pair<int, string>> q;
    q.push({ A,"" });
    visited[A] = true;
    while (!q.empty()) {
        int num = q.front().first;
        string op = q.front().second;
        q.pop();
        if (num == B) {
            cout << op << "\n";
            break;
        }
        
        if (num == 0) {
            if (!visited[9999]) {
                visited[9999] = true;
                q.push({ 9999, op + "S" });
            }
                continue;
        }
        int n = num * 2;
        if (!visited[n % 10000]) {
            visited[n % 10000] = true;
            q.push({ n % 10000, op + "D" });
        }
        n = num - 1;
        if (!visited[n]) {
            visited[n] = true;
            q.push({ n, op + "S" });
        }
        int cnt = -1;
        n = num;
        while (n > 0) {
            n /= 10;
            cnt++;
        }
        int a = pow(10, cnt);
        n = num % 1000*10 + num / 1000;
        if (!visited[n]) {
            visited[n] = true;
            q.push({ n,op + "L" });
        }
        
        n = num / 10 + (num % 10) * 1000;
        if (!visited[n]) {
            visited[n] = true;
            q.push({ n,op + "R" });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        bfs();
    }
}
