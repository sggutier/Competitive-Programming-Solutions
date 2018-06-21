// - More or less like the tutorial in http://codeforces.com/blog/entry/9571
#include <bits/stdc++.h>
using namespace std;
const int limN = 205;
const int xtra = 100;
const int mod = 1e9 + 7;

int toRow(const int r, const int c) {
    return c - r + xtra + 1;
}

int toCol(const int r, const int c) {
    return r + c + 1;
}

void preproca(vector < vector<int> > *mat, vector < vector<int> > *otr) {
    for(int i=0; i<limN; i++) {
        for(int j=0; j<limN; j++) {
            (*otr)[i][j] = 0;
            if(i)
                (*mat)[i][j] = ((*mat)[i][j] + (*mat)[i-1][j]) % mod;
            if(j)
                (*mat)[i][j] = ((*mat)[i][j] + (*mat)[i][j-1]) % mod;
            if(i && j)
                (*mat)[i][j] = ((*mat)[i][j] + (mod - (*mat)[i-1][j-1])) % mod;
        }
    }    
}

int getSum(vector < vector<int> > *mat, int rIni, int cIni, int rFin, int cFin) {
    // printf("tryna get %d %d ||| %d %d\n", rIni, cIni, rFin, cFin);
    rIni = max(0, rIni-1);
    cIni = max(0, cIni-1);
    rFin = min(rFin, limN-1);
    cFin = min(cFin, limN-1);
    // printf("\t that means %d %d ||| %d %d\n", rIni, cIni, rFin, cFin);
    int ans = (*mat)[rFin][cFin];
    ans = (ans + (*mat)[rIni][cIni]) % mod;
    ans = (ans + (mod - (*mat)[rIni][cFin])) % mod;
    ans = (ans + (mod - (*mat)[rFin][cIni])) % mod;
    return ans;
}

int testCase() {    
    int N, M, S, rfin, cfin;
    vector < vector<int> > matA(limN, vector<int>(limN, 0)), matB(limN, vector<int>(limN, 0));
    vector < vector<int> > *A = &matA, *B = &matB;

    scanf("%d%d%d%d%d", &N, &M, &S, &rfin, &cfin);
    rfin--, cfin--;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &(*A)[toRow(i, j)][toCol(i, j)]);
        }
    }
    for(int t=1; t<S; t++) {
        preproca(A, B);
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                (*B)[toRow(i, j)][toCol(i, j)] = getSum(A,
                                                        toRow(i, j-t), toCol(i, j-t),
                                                        toRow(i, j+t), toCol(i, j+t));
            }
        }
        // printf("--------------------\n");
        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<M; j++) {
        //         printf("%d ", (*B)[toRow(i, j)][toCol(i, j)]);
        //     }
        //     printf("\n");
        // }
        swap(A, B);
    }
    return (*A)[toRow(rfin, cfin)][toCol(rfin, cfin)];
}

int main() {
    freopen("treasures.in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        printf("Case %d: %d\n", i, testCase());
}
