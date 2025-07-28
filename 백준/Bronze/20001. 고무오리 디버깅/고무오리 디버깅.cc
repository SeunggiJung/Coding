#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> q;
    while (true) {
        string in;
        getline(cin, in);
        if (in == "고무오리 디버깅 시작") continue;
        if (in == "고무오리 디버깅 끝") {
            break;
        }
        if (in == "문제") {
            q.push_back("문제");
        }
        if (in == "고무오리") {
            if (q.empty()) {
                q.push_back("문제");
                q.push_back("문제");
            }
            else q.pop_back();
        }
    }
    if (q.empty())cout << "고무오리야 사랑해";
    else cout << "힝구";
}