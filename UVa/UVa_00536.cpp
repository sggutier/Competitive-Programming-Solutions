#include <bits/stdc++.h>
using namespace std;

void printa(char *s, int *org, int l, int r) {
    int p = org[(int) *s];
    if(l != p)
        printa(s+1, org, l, p-1);
    if(r != p)
        printa(s+(p-l)+1, org, p+1, r);
    printf("%c", *s);
}

void testCase(char *A, char *B) {
    int org[300];
    int n;
    for(n=0; B[n]; n++)
        org[(int) B[n]] = n;
    printa(A, org, 0, n-1);
    printf("\n");
}

int main() {
    char A[30], B[30];
    while(scanf("%s%s", A, B) != EOF)
        testCase(A, B);
}
