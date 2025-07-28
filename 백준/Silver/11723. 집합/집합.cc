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
    cin >> M;
    vector<bool> visited(21, false);
    
    for (int j = 0; j < M; j++) {
        string order;
        int in;
        cin >> order;
        if (order == "add") {
            cin >> in;
            visited[in] = true;
        }
        else if (order == "remove") {
            cin >> in;
            visited[in] = false;
        }
        else if (order == "check") {
            cin >> in;
            if (visited[in]) cout << "1\n";
            else cout << "0\n";
        }
        else if (order == "toggle") { cin >> in; visited[in] = !visited[in]; }
        else if (order == "all") {
            for (int i = 1; i <= 20; i++)
                visited[i] = true;
        }
        else if (order == "empty") {
            for (int i = 1; i <= 20; i++) {
                visited[i] = false;
            }
        }
    }
}
