#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

void hazTabla(char *A, int N, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j < N) {
        while(i != -1 && A[i] != A[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

int acums[limN];
bool funca[limN];

int main() {
    int N ;
    char str[limN];
    int prev[limN];
    int ansCnt = 1;

    scanf("%s", str);
    N = strlen(str);
    hazTabla(str, N, prev);
        
    // for(int i=0; i<=N; i++)
    //     printf("%2d ", prev[i]);
    // printf("\n");
    // for(int i=0; i<=N; i++)
    //     printf("%2d ", i);
    // printf("\n");

    for(int i=N; i; i--) {
        acums[i]++;
        acums[prev[i]] += acums[i];
    }

    for(int i=prev[N]; i; i=prev[i]) {
        funca[i] = true;
        ansCnt ++;        
    }

    printf("%d\n", ansCnt);
    for(int i=1; i<=N; i++) {
        if(!funca[i]) continue;
        printf("%d %d\n", i, acums[i]);
    }
    printf("%d %d\n", N, 1);
}
