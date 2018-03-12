#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 1;

bool usd[limN];

void testCase(int N, int M) {
    memset(usd, 0, sizeof(usd));
    bool fail = false;
    while(N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        for(; a<b; a++) {
            fail |= usd[a];
            usd[a] = true;
        }
    }
    while(M--) {
        int a, b, r;
        scanf("%d%d%d", &a, &b, &r);
        while(a<limN) {
            for(int i=a; i<b && i<limN; i++) {
                fail |= usd[i];
                usd[i] = true;
            }
            a += r;
            b += r;
        }
    }
    if(!fail)
        printf("NO ");
    printf("CONFLICT\n");
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
