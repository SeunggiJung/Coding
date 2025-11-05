#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> inDegree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int count;
        cin >> count;
        
        if (count == 0) {
            continue;
        }

        int prevSinger;
        cin >> prevSinger;
        for (int j = 1; j < count; ++j) {
            int currSinger;
            cin >> currSinger;
            adj[prevSinger].push_back(currSinger);
            inDegree[currSinger]++;
            
            prevSinger = currSinger;
        }
    }
    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int next : adj[cur]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    if (result.size() == N) {
        for (int singer : result) {
            cout << singer << "\n";
        }
    } 
    else {
        cout << "0";
    }
}