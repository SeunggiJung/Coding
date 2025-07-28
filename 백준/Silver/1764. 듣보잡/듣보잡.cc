#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<int> out;
static vector<bool> kn;
static int max_value;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    map<string, int> m;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        m[name] = 1;
    }
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (m[name]) {
            v.push_back(name);
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}
