#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M;
vector<vector<char>> v;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
long long int p(int A, int B, int C) {
    if (B == 1) {
        return A % C;
    }
    else {
        long long int x = (p(A, B / 2, C)) % C;
        if (B % 2 == 0) {
            return (x * x) % C;
        }
        else {
            return (x * x) % C * A % C;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int A, B, C;
    cin >> A >> B >> C;
    cout<<p(A, B, C);
}