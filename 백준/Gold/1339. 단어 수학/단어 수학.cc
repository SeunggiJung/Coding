#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<long long> nums(26, 0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        int len = in.length();
        for(char c : in){
            int n = c - 'A';
            nums[n] += pow(10, len-1);
            len--;
        }
    }
    long long sum = 0;
    sort(nums.rbegin(), nums.rend());
    for(long long i=0;i<=9;i++){
        sum += nums[i] * (9-i);
    }
    cout<<sum;
}
