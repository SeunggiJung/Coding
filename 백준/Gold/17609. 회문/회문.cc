#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N;
string in;
int check(int start, int front, int back) {
    int len = in.length();
    for (int j = start; j < len / 2; j++) {
        if (in[j + front] == in[len - 1 - j - back]) continue;
        if (front + back > 0) return 2;

        if (in[j + 1] == in[len - 1 - j] || in[j] == in[len - 2 - j]) {
            return min(check(j, 1, 0), check(j, 0, 1));
        }
        return 2;
    }
    return front + back;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> in;
        int len = in.length();
        cout << check(0, 0, 0) << "\n";
    }
}