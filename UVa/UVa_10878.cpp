#include <bits/stdc++.h>
using namespace std;

int main() {
    char S[500];

    while(gets(S)) {
        int n = strlen(S);
        char *p = &S[0];
        int ans = 0;
        for(char *p=S; *p; p++) {
            if(*p=='|' || *p=='.')
                continue;
            ans = ans<<1 | (*p=='o');
        }
        if(ans)
            printf("%c", ans);
    }
    
    return 0;
}
