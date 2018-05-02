#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int p[limN];
bool usd[limN];

int main() {
    int up = 0;
    int impCnt = 0;
    int ua=0, ub=0;
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &p[i]);

    for(int i=1; i<=N; i++) {
        if(usd[i]) continue;
        int lc = 0;
        for(int pos=i; !usd[pos]; pos=p[pos]) {
            usd[pos] = true;
            lc ++;
        }
        if(lc==1)
            up = i;
        else if(lc % 2)
            impCnt ++;
        else if(lc==2) {
            ua = i;
            ub = p[i];
        }
    }

    if(up) {        
        printf("YES\n");
        for(int j=1; j<=N; j++)
            if(up != j)
                printf("%d %d\n", up, j);
        return 0;
    }

    if(impCnt || ua==0) {
        printf("NO\n");
        return 0;
    }

    memset(usd, 0, sizeof(usd));
    printf("YES\n");
    printf("%d %d\n", ua, ub);
    usd[ua] = usd[ub] = true;
    for(int i=1; i<=N; i++) {
        if(usd[i]) continue;
        for(int pos=i, pr=0; !usd[pos]; pos=p[pos], pr=1-pr) {
            printf("%d %d\n", pos, pr? ub : ua);
            usd[pos] = true;
        }
    }
}
