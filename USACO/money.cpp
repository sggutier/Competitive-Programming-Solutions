/*
ID: me60
LANG: C++11
TASK: money
*/
#include <bits/stdc++.h>
using namespace std;

long long waysOfChange[10005][30];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    
    int coinV[30] ;
    int coinCnt, ch ;

    scanf("%d%d", &coinCnt, &ch);
    for(int i=0; i<coinCnt; i++)
        scanf("%d", &coinV[i]);

    for(int i=0; i<coinCnt; i++)
        waysOfChange[0][i] = 1LL ;
    for(int i=1; i<=ch; i++) {
        for(int j=0; j<coinCnt; j++) {
            if(j)
                waysOfChange[i][j] = waysOfChange[i][j-1] ;
            if(i >= coinV[j])
                waysOfChange[i][j] += waysOfChange[i-coinV[j]][j] ;
        }
    }

    printf("%lld\n", waysOfChange[ch][coinCnt-1]);
    
    return 0;
}
