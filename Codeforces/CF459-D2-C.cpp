#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int ans[limN][limN];

int main() {
    int n, d, k;
    scanf("%d%d%d", &n, &k, &d);
    if(n==1) {
        for(int i=0; i<d; i++)
            printf("1\n");
        return 0;
    }
    if(k >= n) {
        for(int i=0; i<d; i++) {
            for(int j=1; j<=n; j++)
                printf("%d ", j);
            printf("\n");
        }
        return 0;
    }
    if(d==1 || k==1) {
        printf("-1\n");
        return 0;
    }
    int num[limN];
    for(int i=0; i<d; i++)
        num[i] = 0;
    for(int w=0; w<n; w++) {
        for(int i=0; i<d; i++) {
            ans[i][w] = num[i] + 1;
        }
        int xtra = 1;
        for(int i=0; i<d && xtra; i++) {
            num[i] += xtra;
            xtra = num[i] / k;
            num[i] %= k;
        }
        if(xtra && w+1<n) {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0; i<d; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}
