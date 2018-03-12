#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    static char ans[1500];
    if(N == 1) {
        printf("%d\n", N);
        return ;
    }
    if(N == 0) {
        printf("%d\n", 10);
        return ;
    }
    int W = 0;
    for(int i=9; i>=2; i--) {
        while(N%i==0) {
            ans[W++] = '0' + i;
            N /= i;
        }
    }
    if(N > 1) {
        printf("-1\n");
        return ;
    }
    ans[W] = 0;
    reverse(ans, ans+W);
    if(W==0)
        ans[0] = '1';
    printf("%s\n", ans);
}

int main() {
    int N ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        testCase(a);
    }
}
