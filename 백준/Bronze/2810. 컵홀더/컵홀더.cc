#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    queue<char> q;
    for (int i = 0; i < N; i++) {
        char in;
        cin >> in;
        q.push(in);
    }
    int cnt = 1;
    while (!q.empty()) {
        char a = q.front();
        q.pop();
        if (a == 'L')q.pop();
        cnt++;
    }
    if (cnt > N)cout << N;
    else cout << cnt;
}