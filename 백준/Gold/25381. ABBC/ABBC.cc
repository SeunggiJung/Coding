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
    queue<int> A;
    queue<int> B;
    queue<int> C;
    for(int i=0;i<in.length();i++){
        if(in[i]=='A') A.push(i);
        if(in[i]=='B') B.push(i);
        if(in[i]=='C') C.push(i);
    }
    if(B.empty()){
        cout<<0;
        return 0;
    }
    int cnt=0;
    int Blen = B.size();
    int popcnt=0;
    while(!C.empty()){
        int c = C.front();
        C.pop();
        if(popcnt>=Blen) break;
        int b = B.front();
        B.pop();
        popcnt++;
        if(b<c){
            cnt++;
            continue;
        }
        B.push(b);
    }
    while(!A.empty()){
        int a = A.front();
        A.pop();
        while(!B.empty()){
            int b = B.front();
            B.pop();
            if(a<b){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}
