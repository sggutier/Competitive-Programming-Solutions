#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    char str[limN];
    int n ;
    int ans ;

    scanf("%s", str+1);
    ans = n = strlen(str+1);

    for(char c='a'; c<='z'; c++) {
        int u = 0;
        int cst = 0;
        for(int i=1; i<=n; i++) {
            if(str[i]!=c) continue;
            cst = max(cst, i-u);
            u = i;
        }
        cst = max(cst, n+1-u);
        ans = min(ans, cst);
    }

    printf("%d\n", ans);
}
