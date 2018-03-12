#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

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

    for(int i=0; i<N; i++)
        str[N+1+i] = str[N-1-i];
    //N = 2*N+1;
    
    makePref(2*N+1, str, pref);
    
    int ans = 0;
    for(int i=0; i<=N+1; i++) {
        ans = max(ans, pref[i+N]);
        // if(i!=1)
        //     printf(" ");
        //printf("%d", pref[i+N]);
    }
    printf("%d\n", ans);
}
