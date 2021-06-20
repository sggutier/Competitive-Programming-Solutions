#include <bits/stdc++.h>
using namespace std;

void testCase(char *A) {
    char B[50];
    int n = strlen(A);
    long long ans = 0 ;
    sort(A, A+n);
    strcpy(B, A);
    reverse(B, B+n);
    if(A[0]=='0')
        for(int i=1; i<n; i++) {
            if(A[i]!='0') {
                swap(A[i], A[0]);
                break;
            }
        }
    if(true){
        long long x, y;
        sscanf(A, "%lld", &x);
        sscanf(B, "%lld", &y);
        ans = y-x;
    }
    printf("%s - %s = %lld = 9 * %lld\n", B, A, ans, ans/9);
}

int main() {
    char S[50];
    while(scanf("%s", S)!=EOF)
        testCase(S);
}
