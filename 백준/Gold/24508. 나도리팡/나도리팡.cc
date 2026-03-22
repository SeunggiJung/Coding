#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, K, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K>>T;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v.rbegin(), v.rend());
    int left = 0, right = N-1;
    int cnt = 0;
    while(left<right){
        if(v[left] + v[right] > K){
            int x = K-v[left];
            v[left] += x;
            v[right] -= x;
            cnt += x;
        }
        else{
            int x = v[right];
            v[left] += x;
            v[right] = 0;
            cnt += x;
            right--;
        }
        if(cnt>T){
            cout<<"NO";
            exit(0);
        }
        if(v[left] == K) left++;
    }
    for(int i=0;i<N;i++){
        if(v[i]!=K && v[i]!=0){
            cout<<"NO";
            exit(0);
        }
    }
    cout<<"YES";
}