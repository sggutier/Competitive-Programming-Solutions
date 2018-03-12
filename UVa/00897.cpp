#include <bits/stdc++.h>
using namespace std;
const int limN = 1e7;

bitset <limN> comp;
bitset <limN> cdo;
bitset <limN> isCicl;
vector <int> prims;
vector <int> ciclPrims[10];

void criba(int n = limN) {
    comp[0] = comp[1] = true;
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            prims.push_back(i);
}

void precarga() {
    char str[15];
    int n, w ;
    criba();
    for(const int &p:prims) {
        if(cdo[p]) {
            if(isCicl[p])
                ciclPrims[n].push_back(p);
            continue;
        }
        sprintf(str, "%d", p);
        n = strlen(str);
        sort(str, str+n);
        if(str[0]=='0')
            continue;
        bool fca = true;
        // printf("%d => ", p);
        do {
            w = atoi(str);
            if(!comp[w]) continue;
            fca = false;
            break;
        } while(next_permutation(str, str+n)) ;
        sort(str, str+n);
        // printf("%s ", fca? "Si" : "No");
        do {
            // printf("%s ", str);
            w = atoi(str);
            cdo[w] = true;
            isCicl[w] = fca;
        } while(next_permutation(str, str+n)) ;
        // printf("\n");
        // getchar();
        if(fca)
            ciclPrims[n].push_back(p);
    }
}

void testCase(int n) {
    char str[15];
    int len ;
    sprintf(str, "%d", n);
    len = strlen(str);
    auto it = upper_bound(ciclPrims[len].begin(), ciclPrims[len].end(), n);
    if(it==ciclPrims[len].end())
        printf("0\n");
    else
        printf("%d\n", *it);
}

int main() {
    precarga();
    int n ;
    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
}
