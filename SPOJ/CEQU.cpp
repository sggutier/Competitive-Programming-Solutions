#include <bits/stdc++.h>
using namespace std;

int TC = 0;

void testCase() {
    int a, b ,c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Case %d: %s\n", ++TC, c % __gcd(a, b) == 0? "Yes" : "No");
}

int main() {
    int T ;
    for(scanf("%d", &T); T; T--)
        testCase();
}
