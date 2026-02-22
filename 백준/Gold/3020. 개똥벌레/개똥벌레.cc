#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, H;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>H;
    vector<int> up;
    vector<int> down;
    for(int i=0;i<N;i++){
        int h;
        cin>>h;
        if(i%2) down.push_back(H-h);
        else up.push_back(h);
    }
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    int left = -1;
    int right = N+1;
    int mini = INT_MAX;
    int ecnt = 0;
    for(int i=0;i<H;i++){
        int idx1 = upper_bound(up.begin(), up.end(), i) - up.begin();
        int idx2 = upper_bound(down.begin(), down.end(), i) - down.begin();
        int cnt = (N/2 - idx1 + idx2);
        if(cnt < mini){
            ecnt = 1;
            mini = cnt;
        }
        else if(cnt == mini) ecnt++;
    }
    cout<<mini<<" "<<ecnt;
}