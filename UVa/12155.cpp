#include <bits/stdc++.h>
using namespace std;

int N, N2;

void testCase(int rowIni, int colIni, int rowFin, int colFin) {
    N2 = 2*N-1;
    N--;
    int d ;
    for(int i=rowIni; i<=rowFin; i++) {
        for(int j=colIni; j<=colFin; j++) {
            d = abs(i%N2-N) + abs(j%N2-N);
            if(d>N)
                putchar('.');
            else
                putchar(d%26+'a');
        }
        putchar('\n');
    }
}

int main() {
    int a, b, c, d;
    int tc = 0;
    while(scanf("%d", &N)!=EOF && N) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("Case %d:\n", ++tc);
        testCase(a, b, c, d);
    }
}
