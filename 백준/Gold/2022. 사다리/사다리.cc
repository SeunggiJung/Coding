#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
static double x,y,c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>y>>c;
    double able=0;
    double disable = min(x,y);
    while(able+0.000001<disable){
        double mid = (able+disable)/2;
        double h1 = sqrt(x*x - mid*mid);
        double h2 = sqrt(y*y - mid*mid);
        double h = (h1*h2) / (h1+h2);
        if(h>=c){
            able = mid;
        }
        else disable = mid;
    }
    cout<<able;
}