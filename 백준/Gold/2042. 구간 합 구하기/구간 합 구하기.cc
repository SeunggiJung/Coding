#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, K;
vector<long long int> tree;
void init(int idx) {
    for (int i = tree.size() / 2 - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}
void update(int idx, long long int diff) {
    while (idx > 1) {
        tree[idx] += diff;
        idx /= 2;
    }
}
long long int sum(int start, int end) {
    long long int ans = 0;
    while (start <= end) {
        if (start % 2 == 1) ans += tree[start++];
        if (end % 2 == 0) ans += tree[end--];
        start /= 2;
        end /= 2;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> K;
    int Size = 1 << ((int)(ceil(log2(N))) + 1);
    tree = vector<long long int>(Size, 0);
    int start = Size / 2 - 1;
    for (int i = start+1; i <= start+N; i++) {
        long long int a;
        cin >> a;
        tree[i] = a;
    }
    init(start+N);
    for (int i = 0; i < (M + K); i++) {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long int diff = c - tree[start+b];
            update(start + b, diff);
        }
        else {
            cout << sum(start+b, start+c) << "\n";
        }
    }
}