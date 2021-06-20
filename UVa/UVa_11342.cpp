#include <bits/stdc++.h>
using namespace std;
const int limN = 50000;

int ant[4][limN+1];

void precarga() {
    memset(ant, -1, sizeof(ant));
    ant[0][0] = 0;
    for(int w=1; w<=3; w++) {
        for(int i=0; i<=limN; i++) {
            for(int c=0; c*c<=i; c++) {
                if(ant[w-1][i-c*c]!=-1) {
                    ant[w][i] = c;
                    break;
                }
            }
        }
    }
}

int main() {
    precarga();

    int n, tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d", &n);
        if( ant[3][n] == -1) {
            printf("-1\n");
        }
        else {
            // int ans[4];
            for(int w=3; w>0; w--) {
                // ans[w] = ant[w][n];
                printf("%d%c", ant[w][n], w==1? '\n' : ' ');
                n -= ant[w][n] * ant[w][n];
            }
            // printf("%d %d %d\n", ans[1], ans[2], ans[3]);
        }
    }
    
    return 0;
}
