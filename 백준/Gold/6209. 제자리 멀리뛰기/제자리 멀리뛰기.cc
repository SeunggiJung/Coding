#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int d, n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    cin>>d>>n>>m;
    vector<int> dist;
    vector<int> island(n, 0);
    vector<bool> removed(n+1, false);
    for(int i=0;i<n;i++){
        cin>>island[i];
    }
    sort(island.begin(), island.end());
    island.push_back(d);
    int left = 0;
    int right = island.back()+1;
    while(left+1<right){
        int mid = (left + right) / 2;
        int cnt = 0;
        int bef = 0;
        for(int i : island){
            if(i - bef <= mid){
                cnt++;
            }
            else{
                bef = i;
            }
        }
        if(cnt > m) right = mid;
        else left = mid;
    }
    cout<<right;
}