/*
ID: me60
LANG: C++11
TASK: friday
*/
#include <bits/stdc++.h>
using namespace std;

inline bool is_leap(int year) {
    return year%400==0 || (year%100!=0 && year%4==0);
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n, wd = 0;
    int* ans = new int[7]();
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        bool leap;
        if((leap  = is_leap(1900 + i)))
            month_days[1] ++;
        for(int j=0; j<12; j++) {
            ans[wd] ++;
            wd = (wd + month_days[j])%7;
        }
        if(leap)
            month_days[1] --;
    }
    for(int i=0; i<7; i++)
        printf("%s%d", i==0? "" : " ", ans[i]);
    printf("\n");
    delete[] ans;
    
    return 0;
}
