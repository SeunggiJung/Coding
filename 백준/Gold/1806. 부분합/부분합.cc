#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N, S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>S;
    vector<int> v(N+1,0);
    vector<int> sums(N+1, 0);
    int s=0;
    for(int i=1;i<=N;i++){
        int n;
        cin>>n;
        v[i] = n;
        s+=n;
        sums[i] = s;
    }
    int left=1, right=1;
    int mini = INT_MAX;
    while(left<=right){
        int sum = sums[right] - sums[left-1];
        if(sum>=S){
            while(left<right){
                left++;
                int nsum = sums[right] - sums[left-1];
                if(nsum<S){left--;break;}
            }
            mini = min(mini, right-left+1);
        }
        if(right==N) break;
        right++;
    }
    if(mini==INT_MAX) cout<<0;
    else cout<<mini;
}
