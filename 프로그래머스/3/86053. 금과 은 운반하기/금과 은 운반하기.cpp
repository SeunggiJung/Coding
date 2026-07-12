#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long start = -1;
    long long end = 4e15; 

    while(start + 1<end) {
        long long mid = (start + end) / 2;

        long long gold_carry = 0;
        long long sil_carry = 0;
        long long add_carry = 0;

        for (int i = 0; i < s.size(); i++) {
            long long now_gold = (long long)g[i];
            long long now_sil = (long long)s[i];
            long long now_w = (long long)w[i];
            long long now_t = (long long)t[i];

            long long move_cnt = mid / (now_t * 2);
            if (mid % (now_t * 2) >= now_t) move_cnt++; 

            gold_carry += (now_gold < move_cnt * now_w) ? now_gold : move_cnt * now_w;
            sil_carry += (now_sil < move_cnt * now_w) ? now_sil : move_cnt * now_w;
            add_carry += (now_gold + now_sil < move_cnt * now_w) ? now_gold + now_sil : move_cnt * now_w;
        }
        if(gold_carry >= a && sil_carry >= b && add_carry >= a + b) end = mid;
        else start = mid;
    }
    return end;
}