#include <bits/stdc++.h>
using namespace std;

int cycle_days ;
int days_to_dates[146400][3];
int dates_to_days[400][13][32];

bool leap_year_p(int year) {
    return year%4!=0? false : year%100!=0? true : year%400==0 ;
}

int tru_days(int y, int m, int d) {
    int ans = (y/400)*cycle_days;
    y %= 400;
    return ans + dates_to_days[y][m][d];
}

int main() {
    int n, d, m, y;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    d=1, m=1, y=0, n=0;
    while(y<400) {
        days_to_dates[n][2] = d;
        days_to_dates[n][1] = m;
        days_to_dates[n][0] = y;
        dates_to_days[y][m][d] = n;
        d++;
        n++;
        int m_days = (leap_year_p(y) && m==2)? 29 : months[m];
        if(d>m_days) {
            d = 1;
            m ++;
            if(m>12) {
                m = 1;
                y++;
            }
        }
    }
    cycle_days = n;

    while(scanf("%d%d%d%d", &n, &d, &m, &y), n or d or m or y) {
        long long td = tru_days(y, m, d) + n;
        y = (td/cycle_days) * 400;
        td %= cycle_days;
        y += days_to_dates[td][0];
        m = days_to_dates[td][1];
        d = days_to_dates[td][2];
        printf("%d %d %d\n", d, m, y);
    }
    
    return 0;
}
