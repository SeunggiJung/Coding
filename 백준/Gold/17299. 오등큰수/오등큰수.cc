#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int N;
vector<int> m(1000001, 0);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        m[A[i]]++;
    }
    vector<pii> des;
    vector<int> ngf(N, -1);
    for(int i=0;i<N;i++){
        if(!des.empty() && m[A[i]] > m[des.back().first]){
            while(m[des.back().first] < m[A[i]]){
                ngf[des.back().second] = A[i];
                des.pop_back();
                if(des.empty()) break;
            }
        }
        des.push_back({A[i], i});
    }
    for(int i : ngf) cout<<i<<" ";
}