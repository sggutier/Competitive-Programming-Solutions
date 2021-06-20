#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    int cnt = 0, a;
    while(N--) {
        scanf("%d", &a);
        if(a==0)
            continue;
        if(cnt++)
            printf(" ");
        printf("%d", a);
    }
    if(!cnt)
        printf("0");
    printf("\n");
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
