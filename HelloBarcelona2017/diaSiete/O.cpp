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
    scanf("%s", str);
    int N = strlen(str);
    scanf("%s", str+N+1);

    str[N] = '#';
    makePref(2*N+1, str, pref);

    // int ans = 0;
    // for(int i=1; i<=N; i++)
    //     ans = max(ans, pref[i+N+1]);
    int ans = pref[2*N+1];

    // printf("%s\n", str);
    // for(int i=0; i<=2*N+1; i++)
    //     printf("%d ", pref[i]);
    // printf("\n");

    printf("%d\n", N-ans);
}
