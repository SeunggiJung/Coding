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
//static vector<vector<int>> v;
static vector<bool> visited;
static int cnt;
map<int, vector<int>> m;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void AC(string func, vector<int> v) {
    int head = 0;
    int end = v.size();
    bool rev = false;
    for (int i = 0; i < func.length(); i++) {
        if (func[i] == 'R') {
            rev = !rev;
            int tmp = head;
            head = end;
            end = tmp;
        }
        else {
            if (!rev)
                head++;
            else
                head--;
            if (!rev&&head>end || rev&&head<end) {
                cout << "error\n";
                return;
            }
        }
    }
    
        if (!rev) {
            cout << "[";
            for (int i = head; i < end; i++) {
                cout << v[i];
                if (i != end-1)cout << ",";
            }
            cout << "]\n";
        }
        else {
            cout << "[";
            for (int i = head-1; i >= end; i--) {
                cout << v[i];
                if (i != end)cout << ",";
            }
            cout << "]\n";
        }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string func, arr;
        cin >> func >> M;
        vector<int> v;
        char a;
        cin >> a;
        for (int j = 0; j < M; j++) {
            int b;
            if (j != M - 1)
                cin >> b >> a;
            else
                cin >> b;
            v.push_back(b);
        }
        cin >> a;
        AC(func, v);
    }
}
