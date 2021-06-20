#include <bits/stdc++.h>
using namespace std;
const int limN = 20;

int N;
char S[limN];

void bruta(int pos, int ceros, int unos) {
    if(pos==N) {
        printf("%s\n", S);
        return;
    }
    if(ceros) {
        S[pos] = '0';
        bruta(pos+1, ceros-1, unos);
    }
    if(unos) {
        S[pos] = '1';
        bruta(pos+1, ceros, unos-1);
    }
}

void testCase() {
    int a;
    scanf("%d%d", &N, &a);
    S[N] = 0;
    bruta(0, N-a, a);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
