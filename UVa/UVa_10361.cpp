#include <bits/stdc++.h>
using namespace std;

void testCase() {
    char ans[6][300];
    for(int i=0; i<5; i++) {
        int n = 0;
        while(true) {
            char c;
            scanf("%c", &c);
            if(c=='\n' || c=='<' || c=='>')
                break;
            // if(c != '\n')
            ans[i][n++] = c;
        }
        ans[i][n] = 0;        
    }
    int n ;
    for(n=0; ; n++) {
        scanf("%c", &ans[5][n]);
        if(ans[5][n]=='\n')
            break;
    }
    ans[5][n-3] = 0;
    printf("%s%s%s%s%s\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
    printf("%s%s%s%s%s\n", ans[5], ans[3], ans[2], ans[1], ans[4]);
}

int main() {
    int tc;
    scanf("%d\n", &tc);
    while(tc--)
        testCase();
}
