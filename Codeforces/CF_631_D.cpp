#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define f first
#define s second
const int limN = 2e5 + 5;

void hazTab(const int n, ll *s, ll *pv) {
    pv[0] = -1;
    for(int i=-1, j=0; j<n; ) {
        while(i!=-1 && s[i] != s[j])
            i = pv[i];
        i++, j++;
        pv[j] = i;
    }
}

void anumo(const int n, pii* arr, ll *ans) {
    for(int i=0; i<n; i++)
        ans[i] = arr[i].f * 26 + arr[i].s;
}

void mtchs(const int N, ll *s, const int M, const ll *t, ll *pv, ll *ans) {
    for(int i=0, j=0; j<N; ) {
        while(i !=-1 && t[i] != s[j])
            i = pv[i];
        i++, j++;
        ans[j-1] = i;
        if(i==M)
            i = pv[i];
    }
}

int N = 0, M = 0, W = 0;
pii upo[limN], lowo[limN];
ll tb[limN], ms[limN], x[limN], y[limN], z[limN];


int main() {
    int norg, morg;

    scanf("%d%d", &norg, &morg);
    for(int i=0, u=-1; i<norg; i++) {
        int n;
        char a;
        scanf("%d-%c", &n, &a);
        a -= 'a';
        if(a == u)
            upo[N-1].f += n;
        else
            upo[N++] = {n, (int) a};
        u = a;
    }
    for(int i=0, u=-1; i<morg; i++) {
        int n;
        char a;
        scanf("%d-%c", &n, &a);
        a -= 'a';
        if(a == u)
            lowo[M-1].f += n;
        else
            lowo[M++] = {n, (int) a};
        u = a;
    }

    long long ans = 0;

    if(M == 1) {
        for(int i=0; i<N; i++) {
            if(upo[i].s == lowo[0].s && upo[i].f >= lowo[0].f)
                ans += upo[i].f - lowo[0].f + 1;            
        }
        printf("%lld\n", ans);
        return 0 ;
    }

    if(M == 2) {
        for(int i=0; i+1<N; i++) {
            if(upo[i].s == lowo[0].s && upo[i+1].s == lowo[1].s && lowo[0].f <= upo[i].f && lowo[1].f <= upo[i+1].f)
                ans ++;
        }
        printf("%lld\n", ans);
        return 0 ;
    }

    anumo(N, upo, x);
    anumo(M, lowo, z);
    for(int i=1; i+1<N; i++)
        y[i-1] = z[i];
    W = M-2;

    hazTab(W, y, tb);
    mtchs(N, x, W, y, tb, ms);

    for(int i=M-1; i<N; i++) {
        if(ms[i-1] == M-2 && upo[i-(M-1)].s == lowo[0].s && upo[i].s == lowo[M-1].s && lowo[0].f <= upo[i-(M-1)].f && lowo[M-1].f <= upo[i].f)
            ans++;
    }
    printf("%lld\n", ans);
}
