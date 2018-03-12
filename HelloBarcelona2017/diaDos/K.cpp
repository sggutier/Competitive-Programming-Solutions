#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;
const int limB = 1e2;

void make_table(const int &N, const char *s, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j<N) {
        while(i!=-1 && s[i]!=s[j])
            i = prev[i];
        i++, j++;
    }
}

int kmp(const int &N, const char *A, const int &M, const char *B, const int *prev) {
    int ans = 0;
    int i=0, j=0;
    while(j<N) {
        while(i!=-1 && B[i]!=A[j])
            i = prev[i];
        i++, j++;
        if(i==M) {
            ans++;
            i = prev[i];
        }
    }
    return ans;
}

int main() {
    char S[limN], A[limN];
    int N, M ;
    int tab[limN];

    scanf("%s%s", S, A);
    N = strlen(S);
    M = strlen(A);

    make_table(M, A, tab);
    int aprs = kmp(N, S, M, A, tab);

    printf("%d\n", N - M*aprs + aprs);
}
