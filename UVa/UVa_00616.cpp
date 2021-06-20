#include <bits/stdc++.h>
using namespace std;

bool itWorks(int N, int C) {
    for(int i=0; i<N; i++) {
        if((C-1)%N)
            return false;
        C -= 1 + (C-1)/N;
    }
    return C%N==0;
}

void testCase(int N) {
    for(int i=max((int) sqrt(N), 2); i>1; i--) {
        if(itWorks(i, N)) {
            printf("%d coconuts, %d people and 1 monkey\n", N, i);
            return;
        }
    }
    printf("%d coconuts, no solution\n", N);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n>=0)
        testCase(n);
}
