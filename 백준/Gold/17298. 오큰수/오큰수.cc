#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int N, S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    vector<pii> des;
    vector<int> nge(N, -1);
    for(int i=0;i<N;i++){
        if(!des.empty() && v[i]>des.back().first){
            while(des.back().first<v[i]){
                nge[des.back().second] = v[i];
                des.pop_back();
                if(des.empty()) break;
            }
        }
        des.push_back({v[i], i});
    }
    for(int i : nge) cout<<i<<" ";
}
