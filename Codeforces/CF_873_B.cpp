#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 ;

int sums[2*limN + 10];

int main() {
    int ans = 0;
    int N ;
    char str[limN + 10];

    memset(sums, -1, sizeof(sums));

    scanf("%d", &N);
    scanf("%s", str+1);

    sums[limN] = 0;
    for(int i=1, s=limN; i<=N; i++) {
        s += str[i]=='1'? 1 : -1;
        if(sums[s]==-1)
            sums[s] = i;
        ans = max(ans, i-sums[s]);
    }

    printf("%d\n", ans);
}
