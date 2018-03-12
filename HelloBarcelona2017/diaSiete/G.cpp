#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int str[limN];
int rev[limN];
int pref[limN];

void makePref(const int &N, int *str, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j<N) {
        while(i!=-1 && str[i]!=str[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

int main(){
    int N, K;

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &str[i]);
        rev[N-1-i] = str[i];
    }

    makePref(N, rev, pref);

    for(int i=0; i<=N; i++)
        printf("%d ", str[i]);
    printf("\n");
    for(int i=0; i<=N; i++)
        printf("%d ", pref[i]);
    printf("\n");

    int i=0, j=0;
    while(j<N) {
        while(i!=-1 && rev[i]!=str[j])
            i = pref[i];
        i++, j++;

        printf("%d ", i);
    }
    printf("\n");

    int cnt = 0;
    while(i) {
        if(cnt++)
            printf(" ");
        printf("%d", i);
        i = pref[i];
    }
    printf("\n");
    
    return 0;
}
