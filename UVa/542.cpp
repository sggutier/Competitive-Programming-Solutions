#include <bits/stdc++.h>
using namespace std;
const int limN = 16;

inline bool canPlay(const int a, const int b, const int lev) {
    int A = (a>>(lev-1)), B = (b>>(lev-1));
    return (A>>1) == (B>>1) && (A&1) != (B&1);
}

double probs[limN][limN];
char names[limN][100];
bool usd[limN][5];
double probWinMemo[limN][5];

double probWin(int T, int G) {
    if(usd[T][G])
        return probWinMemo[T][G];
    double ans = 0.0, k = probWin(T, G-1);
    usd[T][G] = true;
    for(int i=0; i<limN; i++) {
        if(canPlay(T, i, G)) {
            ans += probWin(i, G-1) * k * probs[T][i];
        }
    }
    // for(int i=0; i<limN; i++) {
    //     if(canPlay(T, i, G)) {
    //         printf("%d and %d playin at %d, otr=%lf, k=%lf, probs=%lf\n", i, T, G, probWin(i, G-1), k, probs[T][i]);
    //     }
    // }
    // printf("%d %d => %lf\n", T, G, ans);
    return probWinMemo[T][G] = ans;
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    for(int i=0; i<16; i++) {
        probWinMemo[i][0] = 1.0;
        usd[i][0] = true;
    }
    for(int i=0; i<limN; i++)
        scanf("%s", names[i]);
    for(int i=0; i<limN; i++) {
        for(int j=0; j<limN; j++) {
            int tmp;
            scanf("%d", &tmp);
            probs[i][j] = tmp/100.0;
        }
    }
    for(int i=0; i<16; i++) {
        printf("%-10s p=%.2lf%%\n", names[i], 100.0*probWin(i, 4));
    }
    
}

int main() {
    testCase();
    
    return 0;
}
