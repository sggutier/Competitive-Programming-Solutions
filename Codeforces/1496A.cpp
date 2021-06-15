#include <bits/stdc++.h>
using namespace std;

void testCase() {
    static char s[2000];
    int N, k ;
    scanf("%d%d", &N, &k);
    scanf("%s", s);
    if(k*2 == N) {
        printf("NO\n");
        return ;
    }
    for(int i=0; i < k; i++)
        if(s[i] != s[N-1-i]) {
            printf("NO\n");
            return ;
        }
    printf("YES\n");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
