#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> fs;
    queue<int> q;
    q.push(4);
    q.push(7);
    while (!q.empty()) {
        int x = q.front();
        fs.push_back(x);
        q.pop();
        long long int next1 = (long long int)x * 10 + 4;
        long long int next2 = (long long int)x * 10 + 7;

        if (next1 <= N) {
            q.push(next1);
        }
        if (next2 <= N) {
            q.push(next2);
        }
    }
    sort(fs.begin(), fs.end());
    vector<int> prev(N+1,0);
    vector<bool> visited(N+1, false);
    q.push(0);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if(n==N) break;
        for(int i : fs){
            if(i+n>N||visited[i+n]) continue;
            visited[i+n] = true;
            prev[i+n] = i;
            q.push(i+n);
        }
    }
    if(!prev[N]){
        cout<<"-1";
    }
    else{
        vector<int> num;
        while(N>0){
            num.push_back(prev[N]);
            N-=prev[N];
        }
        sort(num.begin(), num.end());
        for(int i : num) cout<<i<<" ";
    }
}