#include <bits/stdc++.h>
using namespace std;
const int limC = 2e7;
const int limN = 1e6;

bitset<limC> comp;
//bool comp[limC];
int parCnt = 0;
int pars[limN];

void criba(int N = limC) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;    
    for(int i=2; i+2<N; i++)
        if(!comp[i] && !comp[i+2])
            pars[parCnt++] = i;
}

int main() {
    criba();
    int n;
    while(scanf("%d", &n)!=EOF)
        printf("(%d, %d)\n", pars[n-1], pars[n-1]+2);
}
