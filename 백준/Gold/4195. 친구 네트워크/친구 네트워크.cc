#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, T;
map<string, pair<string, int>> parent;
pair<string ,int> find(string child){
    if(parent[child].first==child) return parent[child];
    return parent[child] = find(parent[child].first);
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
            parent[A] = find(parent[A].first);
            parent[B] = find(parent[B].first);
            if(parent[A].first==parent[B].first){
                cout<<parent[A].second<<"\n";
                continue;
            }
            cout<<parent[A].second + parent[B].second<<"\n";
            if(parent[A].first < parent[B].first){
                parent[parent[A].first].second += parent[B].second;
                parent[parent[B].first] = parent[parent[A].first];
            }
            else{
                parent[parent[B].first].second += parent[A].second;
                parent[parent[A].first] = parent[parent[B].first];
            }
        }
    }
}
