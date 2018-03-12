#include <bits/stdc++.h>
using namespace std;
const int limN = 205;
const int limS = limN*limN*5;

int tamS = 0;
char S[limS];
int mat[limN][limN];
int oCnt ;

inline int getSum(int ri, int ci, int rf, int cf) {
    return mat[rf][cf] - mat[rf][ci] - mat[ri][cf] + mat[ri][ci];
}

void construye(int r, int c, int tamR, int tamC) {
    if(tamR==0 || tamC==0)
        return;
    int sum = getSum(r-1, c-1, r-1+tamR, c-1+tamC);
    if(sum % (tamR * tamC) == 0) {
        if(oCnt==50) {
            oCnt = 0;
            printf("\n");
        }
        oCnt ++;
        printf("%c", sum>0? '1' : '0');
        return;
    }
    if(oCnt==50) {
        oCnt = 0;
        printf("\n");
    }
    oCnt ++;
    printf("D");
    int mitR = tamR/2 + tamR%2;
    int mitC = tamC/2 + tamC%2;
    construye(r, c, mitR, mitC);
    construye(r, c+mitC, mitR, tamC - mitC);
    construye(r+mitR, c, tamR - mitR, mitC);
    construye(r+mitR, c + mitC, tamR - mitR, tamC - mitC);
}

void destruye(int r, int c, int tamR, int tamC) {
    if(tamR==0 || tamC==0)
        return;
    char ch = S[tamS++] ;
    if(S[tamS]==0) {
        scanf("%s", S);
        tamS = 0;
    }
    if(ch=='D') {    
        int mitR = tamR/2 + tamR%2;
        int mitC = tamC/2 + tamC%2;
        destruye(r, c, mitR, mitC);
        destruye(r, c+mitC, mitR, tamC - mitC);
        destruye(r+mitR, c, tamR - mitR, mitC);
        destruye(r+mitR, c + mitC, tamR - mitR, tamC - mitC);
        return;
    }
    
    for(int i=0; i<tamR; i++) {
        for(int j=0; j<tamC; j++) {
            mat[r + i][c + j] = ch;
        }
    }
}

void construCase() {
    memset(S, 0, sizeof(S));
    oCnt = 0;
    int rows, cols;
    int K = 0;
    char W = 0;
    tamS = 0;
    scanf("%d%d", &rows, &cols);
    while(scanf("%s", S+K) != EOF && (S[K]=='0' || S[K]=='1')) {
        K += strlen(S+K);
    }
    W = S[K];
    S[K] = 0;
    // printf("=> %d %c\n", K, W);
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] +
                (S[(i-1)*cols + (j-1)]=='1');
        }
    }
    printf("D%4d%4d\n", rows, cols);
    construye(1, 1, rows, cols);
    printf("\n");
    S[0] = W;
}

void destruCase() {
    oCnt = 0;
    memset(S, 0, sizeof(S));
    int rows, cols;
    tamS = 0;
    scanf("%d%d", &rows, &cols);
    scanf("%s", S);
    printf("B%4d%4d\n", rows, cols);
    destruye(1, 1, rows, cols);
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            if(oCnt==50) {
                oCnt = 0;
                printf("\n");
            }
            oCnt ++;
            printf("%c", mat[i][j] );
        }
    }
    printf("\n");
}

int main() {
    scanf("%s", S);
    while(S[0]!='#') {
        if(S[0]=='D')
            destruCase();
        else
            construCase();
    }
    
    return 0;
}
