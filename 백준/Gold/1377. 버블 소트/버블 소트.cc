#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<pii> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    int maxi=0;
    for(int i=0;i<N;i++){
        maxi = max(maxi, A[i].second-i);
    }
    cout<<maxi + 1;
}
