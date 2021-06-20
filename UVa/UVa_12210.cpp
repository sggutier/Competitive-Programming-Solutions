#include <bits/stdc++.h>
using namespace std;

void testCase(int A, int B) {
    int minA = 2e9;
    int w ;
    for(int i=0; i<A; i++) {
        scanf("%d", &w);
        minA = min(minA, w);
    }
    for(int i=0; i<B; i++)
        scanf("%d", &w);
    printf("%d", max(0, A-B));
    if(A>B)
        printf(" %d", minA);
    printf("\n");
}

int main() {
    int a, b;
    int tc = 0;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Case %d: ", ++tc);
        testCase(a, b);
    }
}
