#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6 ;

void testCase(int N, int x, int T, int D) {
    // printf("%d %d %d %d\n", N, x, T, D);
    x = floor(double(x * (N + 1)) / 1.1 + 1e-6) - (N + 1) * T;
    N++;
    // printf("%d\n", x);
    int maxHap[2*N+1][x+1];
    memset(maxHap, 0, sizeof(maxHap));
    // printf("=> %d %d\n", x, N);

    for(int i=0; i<D; i++) {
        int costo, hap=0;
        scanf("%d", &costo);
        int tmp;
        for(int j=0; j<N; j++) {
            scanf("%d", &tmp);
            hap += tmp;
        }
        // printf("%d %d\n", costo, hap);
        for(int w=2; w; w--) {
            for(int p=2*N-1; p>=0; p--) {
                for(int c=x-costo; c>=0; c--) {
                    maxHap[p+1][c+costo] = max(maxHap[p+1][c+costo], maxHap[p][c] + hap);
                }
            }
        }
    }

    int ans = 0, xo= (x/N + T)*N;
    // // printf("%d %d\n",x , xo);
    // for(int i=x; i>=0; i--) {
    //     if( ceil((i + T*N)*1.1) - eps <= xo) {
    //         // printf("%d\n", i);
    //         ans = maxHap[2*N][i];
    //         break;
    //     }
    // }
    ans = maxHap[2*N][x];

    printf("%.2lf\n", ans/(N*1.0));
}

int main() {
    int a, b, c, d;

    while(scanf("%d%d%d%d", &a, &b, &c, &d)!=EOF && (a || b || c || d))
        testCase(a, b, c, d);
    
    return 0;
}
