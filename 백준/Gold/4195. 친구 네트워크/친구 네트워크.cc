#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, T;
map<string, pair<string, int>> parent;
string find(string child){
    if(parent[child].first==child) return parent[child].first;
    return parent[child].first = find(parent[child].first);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T-->0){
        cin>>N;
        parent.clear();
        for(int i=0;i<N;i++){
            string A, B;
            cin>>A>>B;
            if(!parent[A].second){
                parent[A] = {A, 1};
            }
            if(!parent[B].second){
                parent[B] = {B, 1};
            }
            string tmp;
            string pA = find(parent[A].first);
            string pB = find(parent[B].first);
            if(pA==pB){
                cout<<parent[pA].second<<"\n";
                continue;
            }
            cout<<parent[pA].second + parent[pB].second<<"\n";
            if(parent[pA].first < parent[pB].first){
                parent[pA].second += parent[pB].second;
                parent[pB] = parent[pA];
            }
            else{
                parent[pB].second += parent[pA].second;
                parent[pA] = parent[pB];
            }
        }
    }
}
