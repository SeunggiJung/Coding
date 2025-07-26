#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    cin >> in;
    sort(in.rbegin(), in.rend());
    cout<<in;
}