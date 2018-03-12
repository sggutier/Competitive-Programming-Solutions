#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int N, b[MAXN], r[MAXN];
char s[MAXN];

int main() {
    fgets(s, MAXN, stdin);
    N = strlen(s) - 1;

    for(int i=1;i<N;i++) {
        int k = b[i - 1];

        while(k && s[k] != s[i])
            k = b[k-1];

        if(s[k] == s[i]) {
            b[i] = k + 1;
            r[i] = b[k] + 1;
        }
    }

    int mx = 0, imx = 0;
    for(int i=0;i<N;i++) {
        if(r[i] > mx)
            mx = r[i], imx = i;
        printf("%d", r[i]);
    }
    printf("\n");

    for(int i=0;i<=imx;i++)
        printf("%c", s[i]);
    printf("\n");

    return 0;
}
