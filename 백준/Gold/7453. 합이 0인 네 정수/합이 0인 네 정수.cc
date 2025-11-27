#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<vector<int>> v(N, vector<int>(4));
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            cin>>v[i][j];
        }
    }
    vector<int> v2;
    map<int, int> cnt2;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int s2 = v[i][2] + v[j][3];
            v2.push_back(s2);
        }
    }
    sort(v2.begin(), v2.end());
    long long cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int n = v[i][0] + v[j][1];
            int li = lower_bound(v2.begin(), v2.end(), -n)-v2.begin();
            int ui = upper_bound(v2.begin(), v2.end(), -n)-v2.begin();
            cnt+=(ui-li);
        }
    }
    cout<<cnt;
}
