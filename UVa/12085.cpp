#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000005;

void printNums(int ini, int fin) {
    if(ini == fin) {
        printf("0%d\n", ini);
        return;
    }
    int pot = 1;
    while(ini/pot != fin/pot)
        pot *= 10;
    printf("0%d-%d\n", ini, fin%pot);
}

void testCase(int N) {
    int ini, ult, k;
    scanf("%d", &ini);
    ult = ini;
    for(int i=1; i<N; i++) {
        scanf("%d", &k);
        if(ult+1 != k) {
            printNums(ini, ult);
            ini = k;
        }
        ult = k;
    }
    printNums(ini, ult);
}

int main() {
    int n;
    int tc = 0;
    while(scanf("%d", &n)!=EOF && n) {
        printf("Case %d:\n", ++tc);
        testCase(n);        
        printf("\n");
    }
}
