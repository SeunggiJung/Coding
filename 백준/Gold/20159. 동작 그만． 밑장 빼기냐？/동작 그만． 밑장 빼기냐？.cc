#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N;
vector<int> sum1;
vector<int> sum2;
vector<int> cards;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    cards.resize(N);
    for(int i=0;i<N;i++){
        cin>>cards[i];
        if(i%2==0) sum1.push_back((sum1.size() ? sum1.back() : 0) + cards[i]);
        else sum2.push_back((sum2.size() ? sum2.back() : 0) + cards[i]);
    }
    int maxi = sum1.back();
    for(int i=0;i<N;i++){
        if(i==0){
            maxi = max(maxi, sum2.back());
            continue;
        }
        if(i==1){
            maxi = max(maxi, cards[0] + sum2.back() - cards.back());
            continue;
        }
        if(i%2==1){
            maxi = max(maxi, sum1[i/2] + sum2[sum2.size()-2] - sum2[i/2-1]);
        }
        else{
            maxi = max(maxi, sum1[i/2-1] + sum2.back()-sum2[i/2-1]);
        }
    }
    cout<<maxi;
}