#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MAX_N = 1e5 + 5;

int cuadCnt = 0;
int cuads[MAX_N];

void precarga(int N = INF) {
    cuadCnt = 0;
    while(cuadCnt*(cuadCnt+1)<=N) {
        cuads[cuadCnt] = cuadCnt*(cuadCnt+1);
        cuadCnt++;
    }
    cuads[cuadCnt] = cuadCnt*(cuadCnt+1);
    cuadCnt++;
}

void testCase(int n) {
    n *= 2;
    for(int b=min(cuadCnt-1, n/2); b>0; b--) {
        int a = n-cuads[b];
        if(a<0 || a%(2*b))
            continue;
        a /= 2*b;
        printf("%d = %d + ... + %d\n", n/2, a+1, a + b);
        return;
    }
    printf("shrug\n");
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n!=-1)
        testCase(n);
}
