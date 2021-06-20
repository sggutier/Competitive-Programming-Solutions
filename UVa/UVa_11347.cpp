#include <bits/stdc++.h>
using namespace std;
const __int128 inf = 1e18;
const int limP = 1005;
const int limN = 500;

int primCnt = 0;
int isComp[limP];
int primos[limP];
int desc[limP][limN];

void criba(int n = limP) {
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i<n; i++)
        if(!isComp[i])
            primos[primCnt++] = i;
}

void precarga() {
    criba();
    for(int i=1; i<limP; i++) {
        int n = i;
        for(int j=0; j<primCnt; j++) {
            int p = primos[j];
            while(n%p==0) {
                n /= p;
                desc[i][j]++;
            }
        }
    }
}

void testCase(int n, int k) {
    __int128 p = 1;
    vector <int> fcs(primCnt, 0);
    while(n > 0) {
        for(int i=0; i<primCnt; i++) {
            fcs[i] += desc[n][i];
        }
        n -= k;
    }
    for(int i=0; i<primCnt; i++) {
        p *= fcs[i]+1;
        if(p > inf)
            break;
    }
    if(p > inf)
        printf("Infinity\n");
    else
        printf("%lld\n", (long long) p);
}

int main() {
    precarga();
    char lin[500];
    int tc;
    fgets(lin, 500, stdin);
    tc = atoi(lin);
    for(int i=1; i<=tc; i++) {
        int n = 0, k = 0;
        char *c = lin;
        fgets(lin, 500, stdin);
        while(*c != '!' && *c!='\n') {
            n = n*10 + *c-'0';
            c++;
        }
        while(*(c++) == '!')
            k++;
        printf("Case %d: ", i);
        testCase(n, k);
    }
}
