#include <bits/stdc++.h>
using namespace std;

char S[500];

void testCase() {
    gets(S);
    int n = strlen(S) - 1;
    char ans[500];
    for(int i=0; i<n; i++)
        ans[i] = 0;
    for(int i=0; i<8; i++) {
        gets(S);
        for(int j=1; j<n; j++) {
            ans[j-1] += (S[j]=='\\')<<i;
        }
    }
    gets(S);
    printf("%s\n", ans);
}

int main() {
    int tc;
    gets(S);
    sscanf(S, "%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            gets(S);
        testCase();
    }
}
