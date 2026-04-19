#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N;
vector<int> honor;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    honor.assign(N,0);
    for(int i=0;i<N;i++){
        cin>>honor[i];
    }
    int ent = 1;
    long long res = 0;
    sort(honor.begin(), honor.end());
    for(int i=0;i<N;i++){
        int cur = honor[i];
        if(cur - ent<=0){
            for(int j=i+1;j<N;j++){
                if(honor[j] - ent > 0) break;
                i = j;
            }
        }
        else{
            res += cur-ent;
        }
        ent++;
    }
    cout<<res;
}