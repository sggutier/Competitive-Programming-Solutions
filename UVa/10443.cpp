#include <bits/stdc++.h>
using namespace std;
const int limN = 1e2 + 5;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;

int letVals[limN];

void cambia(const int &R, const int &C, string* cur, string* sig) {
    for(int i=0; i<R; i++)
        sig[i] = cur[i];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            for(int d=0; d<4; d++) {
                int r=i+dr[d], c=j+dc[d];
                if(r<0 || r>=R || c<0 || c>=C)
                    continue;
                if(letVals[(int) cur[i][j]] == (letVals[(int) cur[r][c]]+1)%3)
                    sig[r][c] = cur[i][j];
            }
        }
    }
}

void testCase() {
    string cur[limN], sig[limN];
    int N, M, C;
    char tmp[limN];
    scanf("%d%d%d", &N, &M, &C);
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        cur[i] = tmp;
    }

    string *a = cur, *b = sig;
    while(C--) {
        cambia(N, M, a, b);
        swap(a, b);
    }

    for(int i=0; i<N; i++)
        printf("%s\n", a[i].c_str());
}

int main() {
    letVals['R'] = 0;
    letVals['P'] = 1;
    letVals['S'] = 2;

    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
