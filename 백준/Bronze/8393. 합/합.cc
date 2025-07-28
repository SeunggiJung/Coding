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
static long long int N, M, X, Y;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<pair<int, int>> direction;
static int cnt;
map<int,vector<pair<int,int>>> m;
static int wei;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << sum;
    
}
