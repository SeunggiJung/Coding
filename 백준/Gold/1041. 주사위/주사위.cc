#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
long long int inf = 2500000001;
vector<long long int> num;
vector<bool> visited;
vector<long long int> mini(6, inf);
long long int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    long long int sum=0;
    long long int maxi=0;
    for(int i=0;i<6;i++){
        long long int n;
        cin>>n;
        sum+=n;
        num.push_back(n);
        mini[1] = min(mini[1], n);
        maxi = max(maxi, n);
    }
    mini[5] = sum - maxi;
    vector<pii> two = {{1,2}, {1,3}, {1,4}, {1,5}, {2,6}, {3,6}, {4,6}, {5,6}, {2,3}, {2,4}, {3,5}, {4,5}};
    vector<vector<int>> three = {{1,2,3}, {1,2,4}, {1,4,5}, {1,3,5}, {2,3,6}, {2,4,6}, {3,5,6}, {4,5,6}};
    for(auto& t : two){
        mini[2] = min(mini[2], num[t.first-1] + num[t.second-1]);
    }
    for(auto& t : three){
        mini[3] = min(mini[3], num[t[0]-1] + num[t[1]-1] + num[t[2]-1]);
    }
    if(N==1){
        cout<<mini[5];
        return 0;
    }

    long long int res = 0;
    res += mini[1] * ((N-1)*(N-2)*4 + (N-2)*(N-2));
    res += mini[2] * ((N-1)*4 + (N-2)*4);
    res += mini[3] * 4;
    cout<<res;
}