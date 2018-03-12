#include <bits/stdc++.h>
using namespace std;
const int limN = 10;

int N;
int grd[limN][limN];
int ans ;

void testCase() {
    scanf("%d", &N);
    int idx[limN];
    for(int i=0; i<N; i++) {
        idx[i] = i;
        for(int j=0; j<N; j++) {
            scanf("%d", &grd[i][j]);
        }        
    }
    ans = (1<<30);

    do {
        int sum = 0;
        for(int i=0; i<N; i++)
            sum += grd[i][idx[i]];
        ans = min(ans, sum);
    } while( next_permutation(idx, idx+N));

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
