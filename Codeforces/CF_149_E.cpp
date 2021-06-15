#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5 ;

void makeTab(char *s, int n, int *prev) {
    prev[0] = -1;
    int i=-1, j=0;
    while(j < n) {
        while( i != -1 && s[i] != s[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

int N ;
char org[limN];
int maxM[limN], rv[limN];

int calca(char *s) {
    int L = strlen(s);
    reverse(s, s+L);
    makeTab(s, L, rv);   
    for(int i=N-1, j=0; i>=0; i--) {
        while(j != -1 && org[i] != s[j])
            j = rv[j];
        j++;
        if(j == L)
            j = rv[j];
        maxM[i] = j;
        maxM[i] = max(maxM[i], maxM[i+1]);
    }
    
    reverse(s, s+L);
    makeTab(s, L, rv);
    for(int i=0, j=0; i<N; i++) {
        while(j != -1 && org[i] != s[j])
            j = rv[j];
        j++;
        if(j == L)
            j = rv[j];
        if(j + maxM[i+1] >= L)
            return 1 ;
    }

    return 0 ;
}

int main() {
    char lin[limN];
    int Q;
    int ans = 0;
    scanf("%s", org);
    N = strlen(org);
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        scanf("%s", lin);
        ans += calca(lin);
    }

    printf("%d\n", ans);
}
