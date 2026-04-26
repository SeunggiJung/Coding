#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
string in;
map<char, int> pri;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pri['*'] = pri['/'] = 0;
    pri['+'] = pri['-'] = 1;
    pri['('] = 2;
    cin>>in;
    vector<char> oper;
    for(int i=0;i<in.length();i++){
        if(in[i]<='Z' && in[i]>='A') {
            cout<<in[i];
            continue;
        }
        if(in[i]=='('){
            oper.push_back('(');
            continue;
        }
        if(in[i]==')'){
            while(!oper.empty()){
                char out = oper.back();
                oper.pop_back();
                if(out=='(') break;
                cout<<out;
            }
            continue;
        }
        while(!oper.empty() && pri[oper.back()] <= pri[in[i]]){
            char out = oper.back();
            oper.pop_back();
            cout<<out;
        }
        oper.push_back(in[i]);
    }
    while(!oper.empty()){
        cout<<oper.back();
        oper.pop_back();
    }
}