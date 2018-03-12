#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char str[limN];
int pref[limN];

void makePref(const int &N, char *str, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j<N) {
        while(i!=-1 && str[i]!=str[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

int main() {
    int N ;

    //gets(str);
    scanf("%s", str);
    N = strlen(str);
    makePref(N, str, pref);
    

    for(int i=1; i<=N; i++) {
        if(i!=1)
            printf(" ");
        printf("%d", pref[i]);
    }
    printf("\n");
}
