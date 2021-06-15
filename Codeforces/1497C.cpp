#include <bits/stdc++.h>
using namespace std;
// N | K
// 0 | 0 ok
// 1 | 1 ok
// 1 | 0 (9, 4) 4, 2, 2, 1   (17, 4) 8, 4, 4, 1
// 0 | 1  (8, 3)   4, 2, 2   (4, 3) 2, 1, 1   (6, 3) 2, 2, 2   (18, 3)  8, 8, 2    (10, 3)  4, 4, 2   (12, 3) 6, 3, 3

void testCase(int n, int k) {
    if((n - (k-1)) * 2 <= n) {
        for(int i=1; i < k; i++, n--)
            printf("1 ");
        printf("%d\n", n);
        return;
    }
    if(n % 2 == k % 2) {
        for(int i=k-2; i > 0; i--, n--)
            printf("1 ");
        printf("%d %d\n", n / 2, n / 2);
        return ;
    }
    if(n % 2 == 0 && k == 3) {
        if(n % 4 == 2)
            printf("%d %d %d\n", 2, (n - 2) / 2, (n - 2) / 2);
        else
            printf("%d %d %d\n", n / 2, n / 4, n / 4);
        return ;
    }
    printf("%d ", 1);
    testCase(n - 1, k - 1);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int n, k;
        scanf("%d%d", &n, &k);
        testCase(n, k);
    }
    // for(int n=3; n <= 28; n++) {
    //     for(int k=3; k <= n; k++) {
    //         printf("%d %d   ===> ", n, k);
    //         testCase(n, k);
    //     }
    // }
}
