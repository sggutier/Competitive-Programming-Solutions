/*
ID: me60
LANG: C++11
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;
const int limT = 1e6 + 5;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n;
    int* milkSchedule = new int[limT + 5];
    int startTime = (1<<30), endTime=-(1<<30);
    int maxMilkTime=0, maxIdleTime=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int ini, fin;
        scanf("%d%d", &ini, &fin);
        startTime = min(startTime, ini);
        endTime = max(endTime, fin);
        milkSchedule[ini]++;
        milkSchedule[fin]--;
    }

    for(int t=startTime, mtime=0, itime=0, mcows=0; t<endTime; t++) {
        mcows += milkSchedule[t];
        if(mcows==0) {
            mtime = 0;
            itime ++;
        }
        else {
            itime = 0;
            mtime ++;
        }
        maxMilkTime = max(maxMilkTime, mtime);
        maxIdleTime = max(maxIdleTime, itime);
    }

    printf("%d %d\n", maxMilkTime, maxIdleTime);

    delete[] milkSchedule;
    return 0;
}
