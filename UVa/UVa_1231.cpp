#include <bits/stdc++.h>
using namespace std;
const int limN = 2e3 + 5;

int maxAcrRow[limN];
int acrs[limN][limN];

void testCase() {
    memset(acrs, 0, sizeof(acrs));
    int T, H, F;
    scanf("%d%d%d", &T, &H, &F);
    for(int i=0; i<T; i++) {
        int A, tmp;
        scanf("%d", &A);
        for(int j=0; j<A; j++) {
            scanf("%d", &tmp);
            acrs[tmp][i]++;
        }
    }

    maxAcrRow[H] = 0;
    for(int t=0; t<T; t++)
        maxAcrRow[H] = max(maxAcrRow[H], acrs[H][t]);

    
    // for(int h=H; h>=0; h--) {
    //     for(int t=0; t<T; t++) {
    //         printf("%d ", acrs[h][t]);
    //     }
    //     printf("\n");
    // }
        
    for(int h=H-1; h>=0; h--) {
        int ans = maxAcrRow[h] = 0;
        int ado = (h+F<=H? maxAcrRow[h+F] : 0);
        for(int t=0; t<T; t++) {
            acrs[h][t] += max(acrs[h+1][t], ado);
            ans = max(ans, acrs[h][t]);
        }
        maxAcrRow[h] = ans;
    }

    printf("%d\n", maxAcrRow[0]);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
}
