#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    char mat[N][N+5];
    int ans = 0;
    for(int i=0; i<N; i++)
        scanf("%s", mat[i]);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(mat[i][j]!='1')
                continue;
            int tmp = (1<<30);
            for(int r=0; r<N; r++) {
                for(int c=0; c<N; c++) {
                    if(mat[r][c]=='3')
                        tmp = min(tmp, abs(r-i) + abs(c-j));                    
                }
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
