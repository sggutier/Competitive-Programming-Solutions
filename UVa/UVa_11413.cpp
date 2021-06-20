#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;

bool itWorks(int M, int vesCnt, const int ves[], int cap) {
    M--;
    for(int i=0, crg=0; i<vesCnt; i++) {
        if(crg+ves[i] > cap) {
            M --;
            crg = 0;
        }
        if(M<0)
            return false;
        crg += ves[i];
    }
    return true;
}

void testCase(int vesCnt, int M) {
    static int ves[limN];
    int maxC = 0, sum=0;

    for(int i=0; i<vesCnt; i++) {
        scanf("%d", &ves[i]);
        maxC = max(maxC, ves[i]);
        sum += ves[i];
    }

    int ini=maxC, fin=sum;
    while(ini<fin) {
        int piv = (ini+fin)/2 ;
        if(itWorks(M, vesCnt, ves, piv))
            fin = piv;
        else
            ini = piv+1;
    }
    
    printf("%d\n", ini);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
}
