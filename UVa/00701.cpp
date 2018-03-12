#include <bits/stdc++.h>
using namespace std;

long double l10 = log2(10) ;

int testCase(long double n) { 
    int cnt = log10l(n) + 1;
    long double n1 = log2l(n+1);
    n = log2l(n);
    //printf("=> %.2Lf %.2Lf\n", n, n1);
    n += cnt*l10;
    n1 += cnt*l10;
    //printf("=> %.2Lf %.2Lf\n", n, n1);
    //int ans = n1;
    do {
        //n -= floor(n);
        //n1 -= floor(n);
        //ans += n1;
        n += l10;
        n1 += l10;
        //printf("%.2Lf %.2Lf\n", n, n1);
        //getchar();
    } while((int) n == (int) n1);
    return n1;
    //return ans;
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
        printf("%d\n", testCase(n));
}
