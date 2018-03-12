/*
ID: me60
LANG: C++11
TASK: beads
*/
#include <bits/stdc++.h>
using namespace std ;

int countColor(char* collar, int size, char color, int pos, int dir) {
    int cnt;
    for(cnt=0; cnt<size && collar[(pos + size + cnt*dir)%size]!=color; cnt++) ;
    return cnt;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n;
    char* collar;
    int ans = 0;

    scanf("%d", &n);
    collar = new char[n+5];
    scanf("%s", collar);

    for(int i=0; i<n; i++) {
        ans = max(ans, countColor(collar, n, 'b', i, -1) +
                  countColor(collar, n, 'b', i+1, 1));
        ans = max(ans, countColor(collar, n, 'b', i, -1) +
                  countColor(collar, n, 'r', i+1, 1));
        ans = max(ans, countColor(collar, n, 'r', i, -1) +
                  countColor(collar, n, 'b', i+1, 1));
        ans = max(ans, countColor(collar, n, 'r', i, -1) +
                  countColor(collar, n, 'r', i+1, 1));
    }
    ans = min(ans, n);

    printf("%d\n", ans);

    delete[] collar;
    return 0;
}
