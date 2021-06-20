#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int *x=NULL, int *y=NULL) {
    if(b==0) {
        if(x)
            *x = 1, *y=0;
        return a;
    }
    int d = gcd(b,a%b,x,y);
    if(x) {
        int x2 = *y, y2 = *x - *y*(a/b);
        *x = x2, *y = y2;
    }
    return d;
}

void testCase(int a, int b) {
    int x, y;
    int d = gcd(a,b,&x,&y);
    printf("%d %d %d\n", x, y, d);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
}
