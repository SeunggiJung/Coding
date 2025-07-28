#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
using namespace std;
static long long int N, A;
static vector<vector<int>> v;
static vector<bool> visited;
map<int, pair<int, int>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    time_t rt;
    struct tm* pt;
    rt = time(NULL);
    pt = localtime(&rt);
    int year = pt->tm_year + 1900;
    int month = pt->tm_mon + 1;
    int day = pt->tm_mday;
    int hour = pt->tm_hour;
    if (hour < 9) {
        day--;
        hour += 24;
    }
    if (day < 0) {
        month--;
        if (month == 1 && month == 3 && month == 5 && month == 7 && month == 8 && month == 10 && month == 12 && month == -1)
            day += 31;
        else if (month == 2) {
            if (year % 4 == 0) day += 29;
            else day += 28;
        }
        else
            day += 30;
    }
    if (month < 0) {
        year--;
        month += 12;
    }
    cout << year << "\n" << month << "\n" << day;
}
