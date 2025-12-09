#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int N, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T-->0){
        priority_queue<int> dec;
        priority_queue<int, vector<int>, greater<int>> inc;
        cin>>N;
        cout<<N/2+1<<"\n";
        for(int i=1;i<=N;i++){
            int num;
            cin>>num;
            if(i==1){
                dec.push(num);
            }
            else{
                if(num>dec.top()) inc.push(num);
                else dec.push(num);
                if(inc.size()>dec.size()){
                    dec.push(inc.top());
                    inc.pop();
                }
                else if(dec.size()>inc.size()+1){
                    inc.push(dec.top());
                    dec.pop();
                }
            }
            if(i%2){
                cout<<dec.top()<<" ";
            }
            if(i%20==0) cout<<"\n";
        }
        cout<<"\n";
    }
}