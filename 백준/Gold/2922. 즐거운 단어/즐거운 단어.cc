#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<char> v;
long long cnt = 0;
vector<int> alpha(26, 0);
vector<bool> ism(26, false);
void im(){
    for(int i=0;i<26;i++){
        char c = 'A' + i;
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') ism[i] = true;
    }
}
void bt(int depth, int seq, vector<long long> s){ //seq>0 : 모음 연속, seq<0 : 자음 연속
    if(abs(seq)>=3) return;
    if(depth==N){
        if(!alpha[11]) return;
        long long sum = 1;
        for(long long x : s) sum*=x;
        cnt+=sum;
        return;
    }
    if(v[depth]){
        if(ism[v[depth]-'A']){
            if(seq>=0) {
                bt(depth+1, seq+1, s);
            }
            else bt(depth+1, 1, s);
        }
        else{
            if(seq<0) {
                bt(depth+1, seq-1, s);
            }
            else bt(depth+1, -1, s);
        }
    }
    else{// 무슨 자음/모음 별로 안중요함
        // 모음
        s.push_back(5);
        if(seq>=0) bt(depth+1, seq+1, s);
        else bt(depth+1, 1, s);
        s.pop_back();
        // 자음

        //L
        s.push_back(1);
        alpha[11]++;
        if(seq<=0){
            bt(depth+1, seq-1, s);
        }
        else bt(depth+1, -1, s);
        alpha[11]--;
        s.pop_back();

        //다른거
        s.push_back(20);
        if(seq<=0){
            bt(depth+1, seq-1, s);
        }
        else bt(depth+1, -1, s);
        s.pop_back();

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    cin>>in;
    N = in.length();
    v.resize(N);
    for(int i=0;i<N;i++){
        if(in[i]!='_') {
            v[i] = in[i];
            alpha[in[i] - 'A']++;
        }
    }
    im();
    bt(0, 0, {});
    cout<<cnt;
}