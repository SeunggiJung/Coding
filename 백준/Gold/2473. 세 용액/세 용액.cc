#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int N;
vector<long long> v;
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
    vector<long long> ans = {LLONG_MAX, 0, 0 ,0};
    for(int i=0;i<N-2;i++){
        int start = i+1;
        int end = N-1;
        while(start<end){
            long long sum = v[i] + v[start] + v[end];
            if(abs(sum) < ans[0]){
                ans = {abs(sum), v[i], v[start], v[end]};
            }
            if(sum<0) start++;
            else end--;
        }
    }
    cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3];
}
