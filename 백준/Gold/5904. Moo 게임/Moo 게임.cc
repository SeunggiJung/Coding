#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
long long N;
vector<int> v;
void func(int index, int w) {
    if (index == 0) {
        if (w == 0) cout << 'm';
        else cout << "o";
        return;
    }
    if (w < v[index-1] + (index + 3)&& w>=v[index-1]) {
        if (w == v[index - 1]) cout << 'm';
        else cout << 'o';
        return;
    }
    if (w < v[index - 1]) {
        func(index - 1, w);
    }
    else {
        func(index - 1, w - (v[index - 1] + (index + 3)));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    v.push_back(3);
    int x = 3;
    while (x <= 1000000000) {
        v.push_back(2 * x + v.size() + 3);
        x = v.back();
    }
    cin >> N;
    N--;
    int index = 0;
    while (true) {
        if (N - v[index] <= 0) break;
        index++;
    }
    func(index+1, N);
}