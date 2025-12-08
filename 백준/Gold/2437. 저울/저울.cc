#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> chu(N);
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>chu[i];
    }
    sort(chu.begin(), chu.end());
    int mini=1;
    for(int c : chu){
        if(c>mini) break;
        mini += c;
    }
    cout<<mini;

}