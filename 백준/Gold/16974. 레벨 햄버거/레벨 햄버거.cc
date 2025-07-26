#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
static long long int N, X;
vector<long long int> pts(51);
vector<long long int> len(51);
long long int func(long long int level, long long int index) {
    if (level == 0) {
        return 1;
    }
    if (index == 1) return 0;
    if(index == len[level]) return pts[level];

    if (index == (len[level] / 2)+1) // 해당 레벨의 정중앙
    {
        return pts[level - 1] + 1;
    }
    else if (index > len[level] / 2 + 1) 
    {
        return pts[level - 1] + 1 + func(level - 1, index - len[level - 1] - 2);
    }
    else {
        return func(level - 1, index-1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pts[0] = 1;
    len[0] = 1;
    for (int i = 1; i <= 50; i++) {
        len[i] = len[i-1] * 2 + 3;
        pts[i] = pts[i - 1] * 2 + 1;
    }
    cin >> N >> X;
    cout << func(N, X);
}