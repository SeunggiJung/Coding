#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    cin>>in;
    queue<int> q;
    int cnt=0;
    for(int i=0;i<in.length();i++){
        if(in[i] == 'B'){
            q.push(i);
            continue;
        }
        if(in[i]=='C'){
            if(q.empty()) continue;
            q.pop();
            cnt++;
        }
    }
    for(int i=0;i<in.length();i++){
        if(in[i]=='A'){
            while(!q.empty()){
                int b = q.front();
                q.pop();
                if(i<b){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt;
}
