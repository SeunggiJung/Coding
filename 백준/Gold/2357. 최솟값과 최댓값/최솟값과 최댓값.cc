#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, K;
typedef pair<int, int> pii;
vector<pii> tree;
void init(int idx) {
    for (int i = tree.size() / 2 - 1; i > 0; i--) {
        tree[i] = { max(tree[i * 2].first,tree[i * 2 + 1].first), min(tree[i * 2].second, tree[i * 2 + 1].second) };
    }
}
pii range(int start, int end) {
    pii ans = {0, INT32_MAX};
    while (start <= end) {
        if (start % 2 == 1) {
            ans = { max(ans.first,tree[start].first), min(ans.second, tree[start].second)};
            start++;
        }
        if (end % 2 == 0) { 
            ans = {max(ans.first, tree[end].first), min(ans.second, tree[end].second)};
            end--;
        }

        start /= 2;
        end /= 2;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    int Size = 1 << ((int)(ceil(log2(N))) + 1);
    tree = vector<pii>(Size, {0,INT32_MAX});
    int start = Size / 2 - 1;
    for (int i = start + 1; i <= start + N; i++) {
        long long int a;
        cin >> a;
        tree[i].first = a;
        tree[i].second = a;
    }
    init(start + N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pii res = range(start + a, start + b);
        cout << res.second << " " << res.first << "\n";
    }
}