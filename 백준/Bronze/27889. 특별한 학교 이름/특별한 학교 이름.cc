#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
using namespace std;
static long long int N, A;
static vector<vector<int>> v;
static vector<bool> visited;
map<int, pair<int, int>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<string, string> m;
    m["NLCS"] = "North London Collegiate School";
    m["BHA"] = "Branksome Hall Asia";
    m["KIS"] = "Korea International School";
    m["SJA"] = "St. Johnsbury Academy";
    string in;
    cin >> in;
    cout << m[in];
}
