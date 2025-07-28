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
vector<bool> visited;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> v(N);
    vector<pii> link(1000001, {0,0});
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++) {
        link[v[i]] = { v[(i + N - 1) % N], v[(i + 1) % N] };
    }
    for (int k = 0; k < M; k++) {
        string order;
        int i, j;
        cin >> order;
        if (order == "BN") { 
            cin >> i >> j; 
            cout << link[i].second << "\n";
            link[j] = { i, link[i].second };
            link[link[i].second].first = j;
            link[i].second = j;
        }
        else if(order=="BP"){
            cin >> i >> j;
            cout << link[i].first << "\n";
            link[j] = { link[i].first,i };
            link[link[i].first].second = j;
            link[i].first = j;
        }
        else if(order=="CN"){
            cin >> i;
            cout << link[i].second << "\n";
            int remove = link[i].second;
            int next = link[remove].second;
            link[i].second = link[remove].second;
            link[next].first = i;
        }
        else {
            cin >> i;
            cout << link[i].first << "\n";
            int remove = link[i].first;
            int next = link[remove].first;
            link[next].second = i;
            link[i].first = next;
        }
    }
}