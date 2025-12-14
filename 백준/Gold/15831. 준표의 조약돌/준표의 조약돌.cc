#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, B, W;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>B>>W;
    string in;
    cin>>in;
    int left=0, right=0;
    int bcnt=0, wcnt=0;
    int maxi = 0;
    while(left<=right){
        if(right==N) break;
        in[right]=='W'? wcnt+=1 : bcnt+=1;
        while(bcnt>B){
            if(left==right) break;
            in[left]=='W' ? wcnt-=1 : bcnt-=1;
            left++;
        }
        if(wcnt>=W && bcnt<=B)
            maxi = max(maxi, right - left + 1);
        right++;
    }
    cout<<maxi;
}
