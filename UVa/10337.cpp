#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
const int limH = 10;
const int inf = 1e6;

void testCase() {
    int dp[limH][limN];
    int X ;
    int costs[limH][limN];

    scanf("%d", &X);
    X /= 100;
    for(int h=0; h<limH; h++) {
        for(int i=0; i<X; i++)
            scanf("%d", &costs[limH-1-h][i]);
    }
    for(int h=0; h<limH; h++)
        dp[h][0] = inf;
    dp[0][0] = 0;
    for(int i=1; i<=X; i++) {
        dp[0][i] = inf;
        for(int h=(i!=X? 1 : 0); h<limH; h++) {
            dp[h][i] = min(inf, dp[h][i-1] - costs[h][i-1] + 30);
            if(h>0)
                dp[h][i] = min(dp[h][i], 60 - costs[h-1][i-1] + dp[h-1][i-1]);
            if(h+1<limH)
                dp[h][i] = min(dp[h][i], 20 - costs[h+1][i-1] + dp[h+1][i-1]);
        }
    }
    // for(int h=0; h<limH; h++) {
    //     for(int i=0; i<=X; i++) {
    //         printf("%3d ", dp[limH-1-h][i]%inf);
    //     }
    //     printf("\n");
    // }
    printf("%d\n\n", dp[0][X]);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
