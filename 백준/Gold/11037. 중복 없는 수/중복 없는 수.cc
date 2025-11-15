#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, mini;
void bt(int num, vector<bool> visited){
    if(num>N){
        mini = min(mini, num);
        return;
    }
    for(int i=1;i<10;i++){
        if(visited[i]) continue;
        visited[i] = true;
        bt(num*10 + i, visited);
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>N){
        if(N>987654321){
            cout<<"0\n";
            continue;
        }
        //if(N==0) break;
        mini = INT_MAX;
        bt(0, vector<bool> (10, false));
        cout<<mini<<"\n";
    }
}   