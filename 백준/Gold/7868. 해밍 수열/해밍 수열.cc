#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
long long int N;
vector<ll> primes;
map<ll, bool> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<ll , vector<ll>, greater<ll>> pq;
    ll p1, p2, p3, i;
    cin>>p1>>p2>>p3>>i;
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    ll x=0;
    while(i-->0){
        x = pq.top();
        pq.pop();
        if(p1<=LLONG_MAX/x && !m[p1*x]) {
            pq.push(p1*x);
            m[p1*x]=true;
        }
        if(p2<=LLONG_MAX/x && !m[p2*x]) {
            pq.push(p2*x);
            m[p2*x]=true;
        }
        if(p3<=LLONG_MAX/x && !m[p3*x]) {
            pq.push(p3*x);
            m[p3*x]=true;
        }
    }
    cout<<x;
}