#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
// M<=50 -> 2^50
/*
1. 모든 기타 OR 해서 최대 찾기
2. 1, 2, 3,,, 개수 올려가며 조합으로 찾으면 바로 끝?
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    vector<long long> guitar(N);
    long long maxi = 0;
    for(int i=0;i<N;i++){
        string name, can;
        cin>>name>>can;
        for(int j=0;j<M;j++){
            if(can[j]=='Y'){
                guitar[i] |= (1LL<<j);
            }
        }
        maxi |= guitar[i];
    }
    if(maxi==0){
        cout<<-1;
        return 0;
    }
    int mini = N;
    for(int i=0;i<(1<<N);i++){
        vector<int> visited(N, false);
        for(int j=0;j<N;j++){
            if((1<<j) & i) visited[j] = true;
        }
        long long sum = 0;
        int cnt = 0;
        for(int j=0;j<N;j++){
            if(visited[j]) {
                sum |= guitar[j]; 
                cnt++;
            }
        }
        if(sum==maxi){
            mini = min(mini, cnt);
        }
    }cout<<mini;
}