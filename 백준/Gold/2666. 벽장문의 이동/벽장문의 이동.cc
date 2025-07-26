#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, open1, open2, M;
int func(int a, int b, int cnt) {
    if (cnt == M) return 0;
    // 1. 열려있는 a를 닫고 v[cnt]를 여는 경우, 2. 열려있는 b를 닫고 v[cnt]를 여는 경우
    return min(abs(v[cnt] - a) + func(v[cnt], b, cnt + 1), abs(v[cnt] - b) + func(a, v[cnt], cnt + 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt = 0;
    cin >> N >> open1 >> open2 >> M;
    v = vector<int>(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }
    cout << func(open1, open2, 0); // 1,2 : 열려있는 문, 3 : 사용한 벽장의 수 -> 몇번째 TC 진행중인지
}