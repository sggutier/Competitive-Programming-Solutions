#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 64005;

bool isComp[LIM_N];
int P = 0;
int primes[LIM_N];
vector <tuple<int,int,int>> tris;

void sieve() {
    for(int i=2; i*i < LIM_N; i++)
        if(!isComp[i])
            for(int j=i*i; j < LIM_N; j += i)
                isComp[j] = true;
    for(int i=2; i < LIM_N; i++)
        if(!isComp[i])
            primes[P++] = i;
}

void printDiffs(int l, int r, int d) {
    for(int i=l; i < r; i+=d) {
        printf("%d ", i);
    }
    printf("%d\n", r);
}

void calcIntervs() {
    int dif_cnt = 0, prev_dif = 0, ini_int = 0;
    for(int i = 1; i < P; i++) {
        if(primes[i] - primes[i-1] != prev_dif) {
            if(dif_cnt >= 2) {
                tris.emplace_back(ini_int, primes[i-1], prev_dif);
            }
            prev_dif = primes[i] - primes[i-1];
            dif_cnt = 0;
            ini_int = primes[i-1];
        }
        dif_cnt ++;
    }
}

void testCase(int L, int R) {
    if( R < L ) swap(L, R);
    auto ptr = lower_bound(tris.begin(), tris.end(), tuple<int,int,int>(L, L, L)) ;
    while(true) {
        int l, r, d;
        tie(l, r, d) = *ptr;
        if(R < l) {
            break;
        }
        if(r <= R) {
            printDiffs(l, r, d);
        }
        ptr++;
    }
}

int main() {
    sieve();
    calcIntervs();
    int L, R ;
    while(scanf("%d%d", &L, &R) != EOF && (L || R)) {
        testCase(L, R);
    }
}
