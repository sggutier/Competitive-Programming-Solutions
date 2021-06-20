#include <bits/stdc++.h>
using namespace std;
const int limMon = 30000 + 1;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int coinCnt =  sizeof(coins)/sizeof(int);
long long changeWays[limMon][coinCnt];

void depo() {
    changeWays[0][0] = 1 ;
    for(int i=0; i<limMon; i++) {
        for(int j=0; j<coinCnt; j++) {
            if(j)
                changeWays[i][j] += changeWays[i][j-1];
            if(i+coins[j]<limMon)
                changeWays[i+coins[j]][j] += changeWays[i][j];
        }
    }
}

int main() {
    depo();
    int a, b;

    while(scanf("%d.%d", &a, &b)!=EOF && (a || b)) {
        long long ans = changeWays[a*100 + b][coinCnt-1];
        printf("%3d.%02d%17lld\n", a, b, ans);
    }
    
    return 0;
}
