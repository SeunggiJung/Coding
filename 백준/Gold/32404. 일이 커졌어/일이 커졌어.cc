#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<int> v(N+1);
    vector<int> visited(N+1, false);
    for(int i=N;i>0;i--){
        if(i%2==0){
            for(int j=1;j<=N;j++){
                if(!visited[j]){
                    visited[j] = true;
                    v[i] = j;
                    break;
                }
            }
        }
        else{
            for(int j=N;j>0;j--){
                if(!visited[j]){
                    visited[j] = true;
                    v[i] = j;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<v[i]<<" ";
    }
}