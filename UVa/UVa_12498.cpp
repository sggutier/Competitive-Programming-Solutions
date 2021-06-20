#include <bits/stdc++.h>
using namespace std;
const int limN = 55;
const int inf = 1e6;

int testCase() {
    int rowCnt, colCnt;
    int ans = inf ;
    char mat[limN][limN];

    scanf("%d%d", &rowCnt, &colCnt);
    for(int i=0; i<rowCnt; i++)
        scanf("%s", mat[i]);

    for(int c=0; c<colCnt; c++) {
        int sum = 0;
        for(int i=0; i<rowCnt; i++) {
            if(mat[i][c]=='0')
                continue;
            int tmp = inf;
            for(int d=-1; d<=1; d+=2) {
                for(int j=c; 0<=j && j<colCnt; j+=d) {
                    if(mat[i][j]=='0') {
                        tmp = min(tmp, abs(j-c));
                        break;
                    }
                }
            }
            sum += tmp;
        }
        ans = min(ans, sum);
    }

    return (ans==inf? -1 : ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %d\n", i, testCase());
    }
    
    return 0;
}
