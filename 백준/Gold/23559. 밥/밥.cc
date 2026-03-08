#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
long long N, X;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>X;
    vector<pii> v(N);
    for(int i=0;i<N;i++){
        int A, B;
        cin>>A>>B;
        v[i] = {A, B};
    }
    sort(v.begin(), v.end(), [](pii& a, pii& b) {
        return (a.first - a.second) > (b.first - b.second);
    });
    int sum = 0;
    for(int i=0;i<N;i++){
        int diff = v[i].first - v[i].second;
        if(diff>0 && (X-5000 >= (N-i-1)*1000)){
            X-=5000;
            sum += v[i].first;
        }
        else{
            X-=1000;
            sum += v[i].second;
        }
    }
    cout<<sum;
}