#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    string input;
    cin >> input;
    vector<int> in(N);
    for (int i = 0; i < N; i++) {
        in[i] = (input[i] - '0');
    }
    vector<int> out = { 10 };
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt == K || in[i] <= out.back()) {
            out.push_back(in[i]);
            continue;
        }
        while (out.back() < in[i]) {
            out.pop_back();
            cnt++;
            if (cnt == K) {
                break;
            }
        }
        out.push_back(in[i]);
    }
    for (int i = 1; i < out.size() - (K - cnt); i++) cout << out[i];
}