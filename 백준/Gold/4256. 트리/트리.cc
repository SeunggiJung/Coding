#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, T;
vector<int> pre;
map<int, int> in;
void func(int p, int i, int len){
    if(p>=N||i>=N) return;
    int subroot = pre[p];
    int inrootidx = in[subroot];
    int leftsize = inrootidx - i;
    int rightsize = len - leftsize - 1;
    if(leftsize>0) func(p+1, i, leftsize);
    if(rightsize>0) func(p+1+leftsize, inrootidx+1, rightsize);
    cout<<subroot<<" ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T-->0){
        cin>>N;
        pre.assign(N, 0);
        in.clear();
        for(int i=0;i<N;i++){
            cin>>pre[i];
        }
        for(int i=0;i<N;i++){
            int n;
            cin>>n;
            in[n] = i;
        }
        func(0, 0, N);
        cout<<"\n";
    }
}
