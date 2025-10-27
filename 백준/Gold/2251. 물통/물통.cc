#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int A,B,C;
map<vector<int>, bool> visited;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>A>>B>>C;
    vector<int> ABC(3,0);
    set<int> Cs;
    queue<vector<int>> q;
    ABC[2] = C;
    q.push(ABC);
    while(!q.empty()){
        int a = q.front()[0];
        int b = q.front()[1];
        int c = q.front()[2];
        q.pop();
        if(visited[{a,b,c}]) continue;
        visited[{a,b,c}] = true;
        if(a==0){
            Cs.insert(c);
        }
        if(a>0){
            int tob = min(a,B-b);
            q.push({a-tob, b+tob, c});
            int toc = min(a,C-c);
            q.push({a-toc, b, c+toc});
        }
        if(b>0){
            int toa = min(b,A-a);
            q.push({a+toa, b-toa, c});
            int toc = min(b, C-c);
            q.push({a,b-toc,c+toc});
        }
        if(c>0){
            int toa = min(c, A-a);
            q.push({a+toa, b, c-toa});
            int tob = min(c, B-b);
            q.push({a, b+tob, c-tob});
        }
    }
    for(int c : Cs) cout<<c<<" ";
}