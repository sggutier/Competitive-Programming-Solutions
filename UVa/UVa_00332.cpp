#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    char str[25];
    int t ;
    int potA=1, potB=1, x, y;

    scanf("%s", str);
    t = strlen(str+2);

    // printf("==== %d %d %s\n", n, t, str);

    sscanf(str+2, "%d", &x);
    str[2+t-n] = 0;
    if(n!=t)
        sscanf(str+2, "%d", &y);
    else
        y = 0;
    for(int i=n; i<t; potB*=10, i++);
    for(int i=0; i<t; potA*=10, i++);

    // printf("%d %d => %d %d\n", potA, potB, x, y);
    potA -= potB;
    x -= y;
    t = __gcd(potA, x);
    printf("%d/%d\n", x/t, potA/t);
}

int main() {
    int n ;
    int tc = 1;
    while(scanf("%d", &n)!=EOF && n!=-1) {
        printf("Case %d: ", tc++);
        testCase(n);
    }
}
