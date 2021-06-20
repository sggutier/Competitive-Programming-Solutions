#include <bits/stdc++.h>
using namespace std;
const int limP = 1120;
const int limK = 14;

int primCnt = 0;
int primos[limP+1];
bool comp[limP+1];

int ways[limK+1][limP+1];

void criba() {
    for(int i=2; i*i<limP; i++)
        if(!comp[i])
            for(int j=i*i; j<limP; j+=i)
                comp[j] = true;
    for(int i=2; i<limP; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void precarga() {
    criba();
    ways[0][0] = 1;
    for(int i=0; i<primCnt; i++) {
        for(int k=limK-1; k>=0; k--) {
            for(int j=limP-primos[i]; j>=0; j--) {
                ways[k+1][j + primos[i]] += ways[k][j];
            }
        }
    }
}

int main() {
    precarga();

    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        printf("%d\n", ways[b][a]);
    
    return 0;
}
