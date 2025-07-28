#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, T;
string in;
vector<bool> visited;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
void func(int start, int end){
    //if (start == end) return;
    pair<char, int> p = { 'Z' + 1, 101 };
    for (int i = start; i < end; i++) {
        if (visited[i]) continue;
        if (p.first > in[i]) {
            p = { in[i], i };
        }   
    }
    if (p.second == 101) return;
    visited[p.second] = true;
    for (int i = 0; i < in.length(); i++) {
        if (visited[i]) cout << in[i];
    }
    cout << "\n";
    
    func(p.second + 1, end);
    func(start, p.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> in;
    visited = vector<bool>(in.length(), false);
    func(0, in.length());
}