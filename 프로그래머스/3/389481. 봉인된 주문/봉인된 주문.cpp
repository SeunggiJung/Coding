#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long num(string s){
    long long res = 0;
    long long mult = 1;
    for(int i = s.length()-1;i>=0;i--){
        res += ((s[i] - 'a' + 1) * mult);
        mult*=26;
    }
    return res;
}
string who(long long n){
    string res = "";
    long long div = 1;
    while(true){
        if(n/div == 0){
            div /=26;
            break;
        }
        div *= 26;
    }
    while(div>=1){
        long long q = n/div;
        res.push_back('a'+ q - 1);
        n -= div*q;
        div/=26;
        if(div && n/div==0){
            res.back()-=1;
            n+=div*26;
        }
    }

    return res;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    long long obj = n;
    int bef = 0;
    vector<long long> bs;
    for(string ban : bans){
        bs.push_back(num(ban));
    }
    sort(bs.begin(), bs.end());
    for(long long b : bs){
        if(obj >= b) obj++;
    }
    answer = who(obj);
    for(int i=answer.size()-1;i>=0;i--){
        if(answer[i]=='`'){
            answer[i] = ' ';
            if(i==0) continue;
            else{
                answer[i] = 'z';
                answer[i-1] -=1;
            }
        }
    }
    answer.erase(remove(answer.begin(), answer.end(), ' '), answer.end());
    return answer;
}