#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
vector<bool> prime;
vector<bool> visited;
map<int, bool> check;
int T, cnt;
string number;
void bt(int depth, int num) {
    if (!check[num] && prime[num]) {
        check[num] = true;
        cnt++;
    }
    if (depth == 7) return;
    for (int i = 0; i < number.length(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        bt(depth + 1, num * 10 + number[i] - '0');
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prime = vector<bool>(10000000, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(9999999); i++) {
        if (prime[i] == true) {
            for (int j = 2; i * j <= 9999999; j++) {
                prime[i * j] = false;
            }
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> number;
        cnt = 0;
        check.clear();
        visited = vector<bool>(number.length(), false);
        bt(0,0);
        cout << cnt << "\n";
    }
}