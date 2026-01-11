#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, M;
bool flag=false;
int cnt = 0;
vector<bool> visited(10, false);
vector<long long> nums;
void bt(int depth, int bef, int limit){
    if(depth==limit){
        int x = 0;
        long long num = 0;
        for(int i=0;i<10;i++){
            if(visited[i]) {
                num += i * pow(10, x);
                x++;
            }
        }
        nums.push_back(num);
        cnt++;
        if(cnt>=N) flag = true;
        return;
    }
    for(int i=bef+1;i<10;i++){
        if(visited[i]) continue;
        visited[i] = true;
        bt(depth+1, i, limit);
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=1;i<=11;i++){
        bt(0, -1, i);
        if(flag){
            sort(nums.begin(), nums.end());
            cout<<nums[N-1];
            return 0;
        }
    }
    cout<<-1;
}