#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int limN = 1e6 + 5;

void hazTab(int n, char *s, int *z) {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

char bgy[limN*2];
void calcMaxM(int X, char *org, int *ans, int Y, char *cpy, int *pv) {
    for(int i=0; i<Y; i++)
        bgy[i] = cpy[i];
    bgy[Y] = '#';
    for(int i=0; i<X; i++)
        bgy[Y+1+i] = org[i];
    bgy[X+Y+1] = 0;
    // for(int i=0; i<X+Y+1; i++)
    //     printf("%c ", bgy[i]);
    // printf("\n");
    hazTab(X+Y+1, bgy, pv);
    int S = Y+1;
    // for(int i=0; i<X+Y+1; i++)
    //     printf("%d ", pv[i]);
    // printf("\n");
    for(int i=0; i<X; i++) {
        ans[i] = pv[i+S];
    }
}

ll cntWays[limN], cntAcum[limN];
char A[limN], L[limN], R[limN];
int lenA, lenL, lenR;
int mml[limN], mmr[limN];
int kmp[limN*2];

int main() {
    fgets(A, sizeof(A), stdin);
    fgets(L, sizeof(L), stdin);
    fgets(R, sizeof(R), stdin);
    lenA = strlen(A)-1;  A[lenA] = 0;
    lenL = strlen(L)-1;  L[lenL] = 0;
    lenR = strlen(R)-1;  R[lenR] = 0;

    calcMaxM(lenA, A, mml, lenL, L, kmp);
    calcMaxM(lenA, A, mmr, lenR, R, kmp);

    if(lenL==lenR) {
        ll ans = 0;
        bool fca = lenA % lenL == 0;
        for(int i=0; i < lenA && fca; i+=lenA) {
            int x = mml[i], y = mmr[i];
            ans = 0;
            if(x==lenL || y==lenL)
                ans ++;
            else if(x==y) {
                if(L[x] <= A[i+x]  && A[i+x] <= R[x])
                    ans ++;
            }
            else if(x > y) {
                if(L[x] <= A[i+x])
                    ans ++;
            }
            else {
                if(A[i+y] <= R[y])
                    ans ++;
            }
            if(!ans)
                fca = 0;
        }
        printf("%lld\n", fca? 1LL : 0LL);
        return 0;
    }

    // printf(">> ");
    // for(int i=0; i<lenA; i++)
    //     printf("%d ", mml[i]);
    // printf("\n");
    // printf(">> ");
    // for(int i=0; i<lenA; i++)
    //     printf("%d ", mmr[i]);
    // printf("\n");

    cntAcum[lenA] = cntWays[lenA] = 1;
    for(int i=lenA-1; i>=0; i--) {
        if(A[i] == '0') {
            if(lenL == 1 && L[0]=='0')
                cntWays[i] = cntWays[i+1];
            cntAcum[i] = (cntAcum[i+1] + cntWays[i]) % mod;
            continue ;
        }
        if(true) {
            int x = i+lenL+1, y = min(i + lenR, lenA + 1);
            if(x < y)
                cntWays[i] = (cntAcum[x] - cntAcum[y] + mod) % mod;
        }
        // for(int x=lenL+1; x<lenR && i+x <= lenA; x++)
        //     cntWays[i] = (cntWays[i] + cntWays[i+x] + mod) % mod;
        if(i + lenL <= lenA) {
            int m = mml[i];

            // printf("%d\n", m);
            // printf("\t");
            // for(int j=0; j<lenL; j++)
            //     printf("%c", A[i + j]);
            // printf("\n");
            // printf("\t");
            // for(int j=0; j<lenL; j++)
            //     printf("%c", L[j]);
            // printf("\n");
            // bool fca = true;
            // for(int x=0; x<lenL; x++) {
            //     if(A[i+x] != L[x]) {
            //         fca = A[i + x] > L[x];
            //         break;
            //     }
            // }
            // printf("mml %d %d\n", i, m);
            // if(m < lenL)
            //     printf("\t%c %c\n", A[i + m ], L[m]);
            // if(fca) {
                if(m == lenL || (m < lenL && A[i + m ] >= L[m ] )) {
                // printf("YES\n");
                cntWays[i] = (cntWays[i] + cntWays[i+lenL]) % mod;
            }
        }
        if(i + lenR <= lenA) {
            int m = mmr[i];

            // printf("%d\n", m);
            // printf("\t");
            // for(int j=0; j<lenR; j++)
            //     printf("%c", A[i + j]);
            // printf("\n");
            // printf("\t");
            // for(int j=0; j<lenR; j++)
            //     printf("%c", R[j]);
            // printf("\n");
            // bool fca = true;
            // for(int x=0; x<lenR; x++) {
            //     if(A[i+x] != R[x]) {
            //         fca = A[i + x] < R[x];
            //         break;
            //     }
            // }
            
            // printf("mmr %d %d\n", i, m);
            // if(m < lenR)
            //     printf("\t%c %c\n", A[i + m ], R[m]);
            if(m == lenR || (m < lenR && A[i + m ] <= R[m] )) {
            // if(fca) {
                // printf("YES\n");
                cntWays[i] = (cntWays[i] + cntWays[i+lenR]) % mod;
            }
        }
        cntAcum[i] = (cntAcum[i+1] + cntWays[i]) % mod;
    }

    // for(int i=0; i<lenA; i++)
    //     printf("%c ", A[i]);
    // printf("\n");
    // for(int i=0; i<lenA; i++)
    //     printf("%lld ", cntWays[i]);
    // printf("\n");

    printf("%lld\n", cntWays[0]);
}
