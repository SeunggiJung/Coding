#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int x, N;
vector<int> l;
map<char, int> m;
int main() {
    while(cin>>x){
        x *=10000000;
        cin>>N;
        l.assign(N, 0);
        for(int i=0;i<N;i++){
            cin>>l[i];
        }
        sort(l.begin(), l.end());
        if(N==1){
            cout<<"danger\n";
            continue;
        }
        int maxi = -1;
        pii lr;
        for(int i=0;i<N-1;i++){
            int left = i;
            int right = N;
            while(left+1<right){
                int mid = (left + right) / 2;
                int sum = l[i] + l[mid];
                if(sum==x){
                    int diff = abs(l[i] - l[mid]);
                    if(diff>maxi){
                        maxi = diff;
                        lr = {l[i], l[mid]};
                    }
                    break;
                }
                if(sum>x) right = mid;
                else left = mid;
            }
        }
        if(maxi==-1) cout<<"danger\n";
        else{
            cout<<"yes "<<lr.first<<" "<<lr.second<<"\n";
        }
    }
}