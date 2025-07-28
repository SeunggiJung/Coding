#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
#include <list>
#include <set>
using namespace std;
static long long int N, M, X, Y;
static vector<vector<int>> v;
static vector<int> visited;
static vector<pair<int, int>> direction;
static int cnt;
map<int,vector<pair<int,int>>> m;
static int wei;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        
        return a.second < b.second;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    cin >> in;
    string bomb;
    cin >> bomb;
    deque<char> dq;
    string str = in;
    for (int i = in.size()-1; i >= 0; i--) {
        dq.push_front(in[i]);
        if (!dq.empty()&&dq.size()>=bomb.size()&&dq[0] == bomb[0]) {
            bool flag = true;
            for (int j = 1; j <= bomb.size()-1; j++) {
                if (dq[j] != bomb[j])
                    flag = false;
            }
            if (flag) {
                for (int j = 0; j < bomb.size(); j++) {
                    dq.pop_front();
                }
            }
        }
    }
    if (dq.empty())cout << "FRULA";
    else {
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
    }
}
