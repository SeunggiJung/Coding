#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int N, M, T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    map<string, int> weeks;
    map<string, pair<int, int>> time;
    vector<vector<pair<string, pair<string, string>>>> days(M+1);
    int week = 0;
    for (int i = 0; i < N; i++) {
        string name, start, end;
        int day;
        cin >> name >> day >> start >> end;
        days[day].push_back({ name, {start,end} });
    }
    for (int i = 1; i <= M; i++) {
        for (auto& x : days[i]) {
            string name = x.first;
            string start = x.second.first;
            string end = x.second.second;
            if (!time[name].first) {
                time[name].first = 0;
                time[name].second = 0;
            }
            time[name].first++;

            time[name].second += (end[0] - '0') * 600;
            time[name].second += (end[1] - '0') * 60;
            time[name].second += (end[3] - '0') * 10;
            time[name].second += (end[4] - '0');

            time[name].second -= (start[0] - '0') * 600;
            time[name].second -= (start[1] - '0') * 60;
            time[name].second -= (start[3] - '0') * 10;
            time[name].second -= (start[4] - '0');
        }
        if (i % 7 == 0) {
            for (auto& a : time) {
                if (a.second.first >= 5 && a.second.second >= 3600)
                {
                    weeks[a.first] += 1;
                }
            }
            time.clear();
        }
    }
    bool flag = false;
    for (auto& w : weeks) {
        if (w.second==(M/7)) {
            cout << w.first << '\n';
            flag = true;
        }
    }
    if (!flag) cout << -1;
}