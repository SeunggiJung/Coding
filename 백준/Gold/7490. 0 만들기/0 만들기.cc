#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
static int N, M;
static int A, B;
void bt(vector<int> nums, vector<char> ops) {
    nums.push_back(nums.size() + 1);
    if (nums.size() == M) {
        int n1=1, n2;
        vector<int> ns = { 1 };
        vector<char> os;
        for (int i = 0; i < M - 1; i++) {
            if (ops[i] == ' ') {
                ns.back() = ns.back() * 10 + nums[i + 1];
            }
            else {
                ns.push_back(nums[i + 1]);
                os.push_back(ops[i]);
            }
        }
        int sum = ns[0];
        for (int i = 0; i < os.size(); i++) {
            if (os[i] == '+') sum += ns[i + 1];
            else sum -= ns[i + 1];
        }
        if (sum == 0) {
            cout << 1;
            for (int i = 0; i < M - 1;i++) {
                cout << ops[i] << nums[i + 1];
            }
            cout << "\n";
        }
        return;
    }
    char op[] = { ' ', '+', '-'};
    for (auto& a : op) {
        ops.push_back(a);
        bt(nums, ops);
        ops.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        vector<int> num;
        vector<char> op;
        bt(num, op);
        cout << "\n";
    }
}
