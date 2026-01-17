#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, int> pdi;
int N, M;
vector<int> stick;
vector<int> num;
vector<long long> method(100001, 0);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    stick.resize(N);
    for(int i=0;i<N;i++){
        cin>>stick[i];
        method[stick[i]]++;
    }
    for(int i=1;i<=100000;i++){
        if(method[i] == 0) continue;
        for(int j=2*i;j<=100000;j+=i){
            method[j] += method[i];
        }
    }
    cin>>M;
    num.resize(M);
    for(int i=0;i<M;i++){
        cin>>num[i];
        cout<<method[num[i]]<<" ";
    }
}
