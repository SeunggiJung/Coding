#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,int> p;
int N;
vector<int> v;
map<int, int> m;
vector<vector<bool>> es;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    int maxi=0;
    vector<int> nums(N);
    v.assign(1000001, false);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        maxi = max(maxi,nums[i]);
        m[nums[i]] = i;
        v[nums[i]] = true;
    }
    vector<int> score(N, 0);
    for(int i=0;i<N;i++){
        for(int j=nums[i]*2;j<=maxi;j+=nums[i]){
            if(v[j]){
                score[i]++;
                score[m[j]]--;
            }
        }
    }
    for(int s : score) cout<<s<<" ";
}
