#include <bits/stdc++.h>
using namespace std;
const int limN = 400;

int anso[limN][13][32];
int dm[] = {
    31, // Enero
    28, // Febrero
    31, // Marzo
    30, // Abril
    31, // Mayo
    30, // Junio
    31, // Julio
    31, // Agosto
    30, // Septiembre
    31, // Octubre
    30, // Noviembre
    31}; // Diciembre

void precalca() {
    int w = 5;
    for(int y=0; y<limN; y++) {
        for(int m = 1; m<=12; m++) {
            int k = dm[m-1];
            if(m==2) {
                if(y%400==0 || (y%4==0 && y%100))
                    k++;
            }
            for(int d=1; d<=k; d++, w=(w+1)%7)
                anso[y][m][d] = w;
        }
    }
    printf("%d", w);
}

bool testCase(int d, int m, long long y) {
    return anso[y%400][m][d] == 0;
}

int main() {
    precalca();
    // printf("%d\n", anso[1][1][1]);
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int a, b;
        long long c;
        scanf("%d%d%lld", &a, &b, &c);
        printf("%s\n", testCase(a, b, c)? "Y" : "N");
    }
}
