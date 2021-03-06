#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int pref[limN];
char str[limN];
bool posb[limN];

void makeKMP(int N, char *str, int *pref) {
    int i=-1, j=0;
    pref[0] = i;
    while(j<N) {
        while(i!=-1 && str[i]!=str[j])
            i = pref[i];
        i++, j++;
        pref[j] = i;
    }
}

int main() {
    int N ;
    int i, j;
    fgets(str, limN, stdin);
    N = strlen(str)-1;
    str[N] = 0;

    makeKMP(N, str, pref);

    for(i=0, j=1; j<N; j++) {
        while(i!=-1 && str[i]!=str[j])
            i = pref[i];
        i++;
        if(j!=N-1)
            posb[i] = true;
    }

    while(i > 0) {
        if(posb[i]) {
            for(int a=0; a<i; a++)
                printf("%c", str[a]);
            printf("\n");
            return 0;
        }
        i = pref[i];
    }

    printf("Just a legend\n");
}
