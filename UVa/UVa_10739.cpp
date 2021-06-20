#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;

bool usd[limN][limN];
int minDstMemo[limN][limN];
char S[limN];

int minDst(int ini, int fin) {
    if(usd[ini][fin])
        return minDstMemo[ini][fin];
    usd[ini][fin] = true;
    if(ini>=fin)
        return minDstMemo[ini][fin] = 0;
    return minDstMemo[ini][fin] = min(minDst(ini+1, fin-1) + (S[ini]!=S[fin]),
                                      1 + min(minDst(ini+1, fin), minDst(ini, fin-1)));
}

int testCase() {
    memset(usd, 0, sizeof(usd));
    scanf("%s", S);
    int n = strlen(S);
    return minDst(0, n-1);
}

int main() {
    int tc ;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        printf("Case %d: %d\n", i, testCase());
    
    return 0;
}
