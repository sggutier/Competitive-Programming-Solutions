#include <bits/stdc++.h>
using namespace std;

void testCase(int groupCnt) {
    char S[1005];
    scanf("%s", S);
    int len = strlen(S), smallLen = len/groupCnt;

    for(int i=0; i<len; i+=smallLen) {
        reverse(S+i, S+i+smallLen);
    }

    printf("%s\n", S);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
