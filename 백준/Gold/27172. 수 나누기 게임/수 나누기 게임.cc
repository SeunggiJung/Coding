#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    int maxi=0;
    vector<int> nums(N, 0);
    v.assign(1000001, -1);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        maxi = max(maxi,nums[i]);
        v[nums[i]] = i;
    }
    vector<int> score(N, 0);
    for(int i=0;i<N;i++){
        for(int j=nums[i]*2;j<=maxi;j+=nums[i]){
            if(v[j]>=0){
                score[i]++;
                score[v[j]]--;
            }
        }
    }
    for(int s : score) cout<<s<<" ";
}
