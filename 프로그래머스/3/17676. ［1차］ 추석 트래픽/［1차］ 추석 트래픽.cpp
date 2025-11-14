#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
pair<int, int> input_to_sec(string s){
    double sec=0, term=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'||s[i]==':'){
            s[i]=' ';
            continue;
        }
        if(s[i]=='.' && cnt==0){
            s[i]=' ';
            cnt++;
            continue;
        }
    }
    stringstream ss;
    ss.str(s);
    vector<double> time;
    double num=0;
    while(ss>>num){
        time.push_back(num);
    }
    
    sec+=time[3]*60*60*1000;
    sec+=time[4]*60*1000;
    sec+=time[5]*1000;
    sec+=time[6];
    term = time[7]*1000;
    
    return {sec, term};
}
int solution(vector<string> lines) {
    int answer=1;
    vector<pair<int,int>> works;
    for(string line : lines){
        pair<int,int> p = input_to_sec(line);
        works.push_back({p.first - p.second + 1 , p.first});
    }
    for(auto& work : works){
        int start = work.first;
        int end = work.second;
        int cur1=0, cur2=0;
        for(auto& another : works){
            if(another.first < start + 1000 && another.second >= start) cur1++;
            if(another.first < end + 1000 && another.second >= end) cur2++;
        }
        int cur = max(cur1, cur2);
        answer = max(cur, answer);
    }
    return answer;
}