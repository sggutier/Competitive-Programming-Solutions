#include <bits/stdc++.h>
using namespace std;

void testCase(int a, int b) {
    printf(" %9d %9d    %s Choice\n", a, b, __gcd(a,b)==1? "Good" : "Bad");
}

int main() {
    int a, b;

    while(scanf("%d%d",&a,&b)!=EOF && (a || b)) {
        testCase(a, b);
        printf("\n");
    }
    
    return 0;
}
