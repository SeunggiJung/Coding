#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    map<pii, int> m;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int index = lower_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
        if (index == arr.size()) {
            if(!index){
                m[{v[i], 0}] = -1000000001;
            }
            else {
                if(!m[{v[i], index}])
                    m[{v[i], index}] = arr.back();
            }
            arr.push_back(v[i]);
        }
        else {
            if(!index){
                m[{v[i], 0}] = -1000000001;
            }
            else{
                if(!m[{v[i], index}])
                    m[{v[i], index}] = arr[index-1];
            }
            arr[index] = v[i];
        }
    }
    cout <<arr.size()<<"\n";
    vector<int> out;
    pii bef = {arr.back(), arr.size() - 1};
    while(true){
        //cout<<bef.first<<" "<<bef.second<<"\n";
        out.push_back(bef.first);
        if(bef.second==0) break;
        bef = {m[bef], bef.second-1};
        
    }
    while(!out.empty()){
        cout<<out.back()<<" ";
        out.pop_back();
    }
}