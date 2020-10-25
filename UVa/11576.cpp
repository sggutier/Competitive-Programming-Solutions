#include <bits/stdc++.h>
using namespace std;
const int limN = 1e2 + 5;

void makeTable(char *S, const int &N, int *tab) {
    int i=-1, j=0;
    tab[0] = -1;
    while(j<N) {
        while(i>=0 && S[i]!=S[j])
            i = tab[i];
        i++, j++;
        tab[j] = i;
    }
}

int KMP(char *S, char *Q, const int &N, int *tab) {
    int i=0, j=0;
    while(j<N) {
        while(i>=0 && Q[i]!=S[j])
            i = tab[i];
        i++, j++;
    }
    return i;
}

void testCase() {
    int W, N;
    char strA[limN], strB[limN];
    int tab[limN];
    int ans = 0;
    char *S = strA, *Q = strB;
    
    scanf("%d%d", &N, &W);
    scanf("%s", Q);
    reverse(Q, Q+N);
    makeTable(Q, N, tab);
    ans += N;
    for(int i=1; i<W; i++) {
        scanf("%s", S);
        reverse(S, S+N);
        ans += N-KMP(S, Q, N, tab);
        makeTable(S, N, tab);
        swap(Q, S);
    }

    printf("%d\n", ans);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
