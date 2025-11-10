#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef pair<int,int> pii;
vector<bool> visited;
vector<pii> done;
vector<int> ar;
set<string> ss;
string str;
int sz;
char vac;
void bt(int depth){
    if(depth==sz){
        vector<bool> rem(str.size(), true);
        for(int i=0;i<sz;i++){
            if(visited[i]){
                rem[done[i].first] = false;
                rem[done[i].second] = false;
            }
        }
        string s;
        for(int i=0;i<str.size();i++){
            if(rem[i]) s.push_back(str[i]);
        }
        if(s!=str) ss.insert(s);
        return;
    }
    visited[depth] = true;
    bt(depth+1);
    visited[depth] = false;
    bt(depth+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>str;
    vector<pii> op;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            op.push_back({i, -1});
        }
        else if(str[i]==')'){
            op.back().second = i;
            done.push_back(op.back());
            op.pop_back();
        }
    }
    sz = done.size();
    visited.resize(sz, false);
    bt(0);
    for(string s : ss){
        cout<<s<<'\n';
    }
}   