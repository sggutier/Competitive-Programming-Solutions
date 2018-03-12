/*
ID: me60
LANG: C++11
TASK: numtri
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int trian[1001][1001];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    
    int ans = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++ ){
        for(int j=0; j<=i; j++) {
            scanf("%d", &trian[i][j]);
            if(i)
                trian[i][j] += max(trian[i-1][j], j? trian[i-1][j-1] : 0);
            ans = max(ans, trian[i][j]);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
