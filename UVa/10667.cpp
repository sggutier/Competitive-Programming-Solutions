#include <bits/stdc++.h>
using namespace std;
const int limN = 1e2 + 5;

int N;
int mat[limN][limN];

void marca(int r1, int c1, int r2, int c2) {
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            mat[i][j] = 1;
        }
    }
}

void suma() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            mat[i][j] += mat[i-1][j];
        }
    }
}

inline bool vacio(const int& c, const  int& r1, const int& r2) {
    return mat[r2][c] == mat[r1-1][c];
}

void testCase() {
    memset(mat, 0, sizeof(mat));
    
    int Q;
    scanf("%d", &N);
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        marca(a, b, c, d);
    }

    suma();

    int ans = 0;
    for(int r1=1; r1<=N; r1++) {
        for(int r2=r1; r2<=N; r2++) {
            int maxK = 0, d = r2-r1+1;
            for(int c=1, k=0; c<=N; c++) {
                if(!vacio(c, r1, r2))
                    k = 0;
                else {
                    k++;
                    maxK = max(maxK, k);
                }
            }
            // printf("%d %d => %d %d\n", r1, r2, d, maxK);
            ans = max(ans, maxK*d);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
