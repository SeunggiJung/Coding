#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, K, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string origin, target;
    cin>>origin>>target;
    map<char, vector<int>> m;
    for(int i=0;i<origin.length();i++){
        m[origin[i]].push_back(i);
    }
    int cnt = 0;
    for(int i=0;i<target.length();i++){
        int maxi = i;
        for(int j : m[target[i]]){
            int tmp = i;
            while(true){
                if(j==origin.length()){
                    maxi = max(maxi, tmp-1);
                    break;
                }
                if(tmp==target.length()){
                    maxi = target.length();
                    break;
                }
                if(origin[j] == target[tmp]){
                    maxi = max(maxi, tmp);
                    j++; tmp++;
                    continue;
                }
                else break;
            }
        }
        cnt++;
        i=maxi;
    }
    cout<<cnt;
}