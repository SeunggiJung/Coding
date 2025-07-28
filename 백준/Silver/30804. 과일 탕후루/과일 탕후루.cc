#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
#include <list>
using namespace std;
static long long int N, M;
static vector<int> v;
static vector<int> visited;
static int maxi;
void g(int start, int end) {
    if (start < 0 || end >= N) return;
    visited = vector<int> (N + 1, 0);
    int cnt = 0;
    for (int i = start; i <= end; i++) {
        if (!visited[v[i]]) {
            cnt++;
        }
        visited[v[i]]++;
    }
    if (cnt <= 2) { maxi = max(end - start + 1, maxi);}
    g(start-1, end);
    g(start, end + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int right = 0;
    int left = 0;
    maxi = 0;
    map<int, int> m;
    
    while (right < N) {
        m[v[right]]++;
        while (m.size()>2) {
            m[v[left]]--;
            if (!m[v[left]]) m.erase(v[left]);
            left++;
        }
        maxi = max(maxi, right - left + 1);
        right++;
    }
    cout << maxi;
}
