#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,int> p;
vector<int> cnt(20, 0);
int sum=0;
bool flag=false;
void dcq(int l, int w, int h){
    if(flag) return;
    int shortest = min(l, min(w, h));
    int x=0;
    while(pow(2,x)<=shortest){
        x++;
    }
    x--;
    long long int c=1;
    for(int i=x;i>=0;i--){
        if(cnt[i]>=c){
            cnt[i]-=c;
            sum+=c;
            break;
        }
        if(i==0) {flag=true; return;}
        c-=cnt[i];
        sum+=cnt[i];
        cnt[i]=0;
        c*=8;
    }
    int len = pow(2,x);
    if(l-len>0) dcq(l-len, len, len);
    if(w-len>0) dcq(l, w-len, len);
    if(h-len>0) dcq(l, w, h-len);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, w, h, N;
    cin>>l>>w>>h>>N;
    for(int i=0;i<N;i++){
        int x, num;
        cin>>x>>num;
        cnt[x] = num;
    }
    dcq(l, w, h);
    if(flag){
        cout<<-1;
        return 0;
    }
    cout<<sum;
}
