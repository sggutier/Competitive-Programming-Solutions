#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int maxLen[limN][limN];

void testCase(char *str) {
    memset(maxLen, 0, sizeof(maxLen));
    int n = strlen(str);
    for(int i=0; i<n; i++)
        maxLen[i][i] = 1;
    for(int len=1; len<n; len++) {
        for(int i=len; i<n; i++) {
            maxLen[i-len][i] = max(maxLen[i-len+1][i], maxLen[i-len][i-1]);
            if(str[i-len] == str[i])
                maxLen[i-len][i] = max(maxLen[i-len][i], maxLen[i-len+1][i-1] + 2);
        }
    }
    printf("%d\n", maxLen[0][n-1]);
}

int main() {
    int tc;
    char S[limN];

    gets(S);
    sscanf(S, "%d", &tc);    
    while(tc--) {
        // scanf("%s", S);
        gets(S);
        testCase(S);
    }
    
    return 0;
}
