#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    vector<int> v(M+1);
    for(int i=1;i<=M;i++){
        cin>>v[i];
    }
    if(N<=M){
        cout<<N;
        return 0;
    }
    long long int mini=6000000000;
    vector<int> res;
    long long int over=0;
    long long int start = 0;
    long long int end = (long long int)N*30;
    while(start+1<end){
        long long int mid = (start+end)/2;
        long long int div=M;
        int last;
        vector<int> divs;
        for(int i=1;i<=M;i++){
            div += (mid/v[i]);
            if(mid%v[i]==0) {
                divs.push_back(i);
                last = i;
            }
        }
        if(div>=N){
            if(mid<mini){
                mini = mid;
                res = divs;
                over = div-N;
            }
            end = mid;
        }
        else{
            start = mid;
        }
    }
    for(int i=0;i<over;i++){
        res.pop_back();
    }
    if(res.empty()) cout<<M; 
    else cout<<res.back();
}