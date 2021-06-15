#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1005;
const int LIM_T = 8;
const int LIM_K = 205;

int N ;
int nums[LIM_N];

int nxts[LIM_N][LIM_T][LIM_K];
int ord[LIM_T], slen[LIM_T];

bool works(int K) {
    int xtra = K % 8 ;
    K /= 8;
    // printf("---------------\n");
    // printf("%d with %d rem\n", K, xtra);
    for(int b=(1 << LIM_T) - 1; b >= 0; b--) {
        int cnt = 0 ;
        for(int i=0; i < LIM_T; i++) {
            if((1 << i) & b)
                cnt ++;
        }
        if(cnt != xtra) continue;
        // printf("Trying with lens:\n\t");
        for(int i=0; i < LIM_T; i++) {
            ord[i] = i;
            slen[i] = K + ((1 << i) & b? 1 : 0);
            // printf("%d ", slen[i]);
        }
        // printf("\n");
        do {
            bool wks = true;
            for(int i=0, n, pos=0; i < LIM_T; i++) {
                n = ord[i];
                if(nxts[pos][n][slen[n]] == -2) {
                    wks = false;
                    break;
                }
                pos = nxts[pos][n][slen[n]] + 1;
            }
            if(wks)
                return true;
        }while(next_permutation(ord, ord+LIM_T));
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d", &nums[i]);
        nums[i] --;
    }

    for(int a=0; a < 8; a++)
        for(int k=0; k < LIM_K; k++)
            nxts[N][a][k] = -2;
    for(int i=N-1; i >= 0; i--) {
        int n = nums[i];
        for(int a=0; a < LIM_T; a++) {
            if(a == n) continue;
            for(int k=0; k < LIM_K; k++)
                nxts[i][a][k] = nxts[i+1][a][k];
        }
        for(int k=2; k < LIM_K; k++)
            nxts[i][n][k] = nxts[i+1][n][k-1];
        nxts[i][n][1] = i;
        for(int a=0; a < LIM_T; a++)
            nxts[i][a][0] = i-1;
    }

    // for(int i=0; i <= N; i++) {
    //     for(int j=0; j < LIM_T; j++) {
    //         for(int k=0; k <= N; k++)
    //             printf("%d ", nxts[i][j][k]);
    //         printf("\n");
    //     }
    //     printf("-------------------\n");
    // }

    int ini=0, fin=N;
    while(ini < fin) {
        int piv = (ini + fin) / 2 + 1;
        if(works(piv))
            ini = piv ;
        else
            fin = piv - 1;
    }
    printf("%d\n", ini);
}
