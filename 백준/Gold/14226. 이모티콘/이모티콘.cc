#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<vector<bool>> visited(2000, vector<bool>(1000, false));
    queue<vector<int>> q;
    q.push({1, 0, 0});
    visited[1][0] = true;
    int mini = 9999;
    while(!q.empty()){
        int screen = q.front()[0];
        int clip = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if(cnt>=mini) continue;
        if(screen>=N){
            mini = min(cnt + (screen - N), mini);
            continue;
        }
        if(!visited[screen+clip][clip]){
            q.push({screen+clip, clip, cnt+1});
            visited[screen+clip][clip] = true;
        }
        if(!visited[screen][screen]){
            q.push({screen, screen, cnt + 1});
            visited[screen][screen] = cnt + 1;
        }
        if(screen > 1 && !visited[screen-1][clip]){
            q.push({screen-1, clip, cnt+1});
            visited[screen-1][clip] = cnt+1;
        }
    }
    cout<<mini;
}