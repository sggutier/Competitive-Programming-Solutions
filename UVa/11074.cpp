#include <bits/stdc++.h>
using namespace std;

void drawLine(int N, int T, int S) {
    for(int j=T; j; j--) {
        for(int i=N*(S+T)+T; i; i--)
            printf("*");
        printf("\n");
    }
}

void drawW(int T, char c) {
    for(; T; T--)
        printf("%c",c);
}

void drawSquares(int N, int T, int S) {
    for(int w=S; w; w--) {
        for(int k=N; k; k--) {
            drawW(T, '*');
            drawW(S, '.');
        }
        drawW(T, '*');
        printf("\n");
    }
}

void testCase(int S, int T, int N) {
    drawLine(N, T, S);
    for(int w=N; w; w--) {
        drawSquares(N, T, S);
        drawLine(N, T, S);
    }
}

int main() {
    int a, b, c;

    for(int tc=1; scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c); tc++) {
        printf("Case %d:\n", tc);
        testCase(a, b, c);
        printf("\n");
    }
    
    return 0;
}
