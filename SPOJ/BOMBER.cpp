#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limB = 150;

int ganaMem[limN][limN];
bool usd[limN][limN];
int mex[limB];

int gana(int r, int c) {
    if(r==0 || c==0) return 0;
    if(usd[r][c]) return ganaMem[r][c];
    usd[r][c] = true;
    if(r > c) {
        return ganaMem[r][c] = gana(c, r);
    }
    for(int i=(r+1)/2; i>=1; i--) {
        for(int j=(c+1)/2; j>=1; j--) {
            gana(i-1,j-1);
            gana(i-1,c-j);
            gana(r-i,j-1);
            gana(r-i,c-j);
        }
    }
    int w = r*limN + c;
    for(int i=(r+1)/2; i>=1; i--) {
        for(int j=(c+1)/2; j>=1; j--) {
            mex[gana(i-1,j-1) ^
                gana(i-1,c-j) ^
                gana(r-i,j-1) ^
                gana(r-i,c-j)] = w;
        }
    }
    // printf("El mex de %d %d es\n", r, c);
    // printf("\t");
    // printf("\n");
    for(int i=0; ; i++) {
        if(mex[i] != w)
            return ganaMem[r][c] = i;
    }
    return 0;
}

int main() {
    int T ;
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", gana(a, b)? 1 : 2);
    }
}
