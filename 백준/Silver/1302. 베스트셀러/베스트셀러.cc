#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<string> v;
    map<string, int> m;
    int maxi=0;
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        if(!m[in])m[in]=0;
        m[in]++;
        if(m[in]>maxi){
            v={in};
            maxi=m[in];
        }
        else if(m[in]==maxi){
            v.push_back(in);
        }
    }
    if(v.size()>1){
        sort(v.begin(), v.end());
    }
    cout<<v[0];
}