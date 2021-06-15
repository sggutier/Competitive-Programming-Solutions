#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N, D ;
    int minP[limN];
    char str[limN];

    scanf("%d%d", &N, &D);
    scanf("%s", str);
    minP[0] = 1;
    for(int i=1; i<N; i++) {
        if(str[i]!='1')
            continue;
        minP[i] = N+1;
        for(int a=1; a<=D && i-a>=0; a++) {
            if(str[i-a]!='1')
                continue;
            minP[i] = min(minP[i], minP[i-a]+1);
        }
    }
    printf("%d\n", minP[N-1]%(N+1) -1);
}
