#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> p;
int N;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    vector<long long> ans = {LLONG_MAX, 0, 0};
    int start = 0;
    int end = N-1;
    while(start<end){
        long long sum = v[start] + v[end];
        if(abs(sum) < ans[0]){
            ans = {abs(sum), v[start], v[end]};
        }
        if(sum<0) start++;
        else end--;
    }
    cout<<ans[1]<<" "<<ans[2];
}
