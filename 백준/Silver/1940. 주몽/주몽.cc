#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int N, M;
vector<int> v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = N-1;
    int cnt = 0;
    while (left < right) {
        int sum = v[left] + v[right];
        if (sum == M) {
            cnt++;
            right--;
            continue;
        }
        if (sum > M)right--;
        if (sum < M) left++;
    }
    cout << cnt;
}
