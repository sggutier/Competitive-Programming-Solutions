#include <bits/stdc++.h>
using namespace std;
const int limN = 22;

int ans[2*limN + 1];

void precarga(int N = limN) {
    double log2 = log(2);
    double logBits = log2, logFact = 0.0;
    int f=1, b=0;
    while(b<=N) {
        //printf("%d %d %lf %lf\n", b, f, logBits, logFact);
        //getchar();
        while(logFact > logBits) {
            //printf("%d %d\n", b, f-1);
            ans[b++] = f-1;
            logBits *= 2;
        }
        logFact += log(++f);
    }
}

int testCase(int n) {
    return ans[(n-1940)/10];
}

int main() {
    precarga();
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("%d\n", testCase(n));
    }
    
    return 0;
}
