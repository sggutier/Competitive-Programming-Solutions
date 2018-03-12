#include <bits/stdc++.h>
using namespace std;
const int trmDays = 1825;

int main() {
    int N;
    int maxP = 0;
    int p[30], a[30], b[30];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d%d", &p[i], &b[i], &a[i]);
        maxP = max(maxP, p[i]);
    }

    maxP *= trmDays;
    for(int t=0; t<maxP; t++) {
        bool funca = true;
        for(int i=0; i<N; i++) {
            int w = t%p[i];
            if(a[i] <= b[i])
                funca &= (a[i] <= w && w <= b[i]);
            else
                funca &= (a[i] <= w || w <= b[i]);
        }
        if(funca) {
            printf("%d\n", t);
            return 0;
        }
    }

    printf("impossible\n");
}
