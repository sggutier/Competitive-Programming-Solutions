#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    bool usd[n];
    bool fst = true;
    int cnt = 1, pos = 0;

    memset(usd, 0, sizeof(usd));

    printf("Discarded cards:");
    while(cnt<n) {
        if(!fst)
            printf(",");
        fst = false ;
        printf(" %d", pos+1);
        usd[pos] = true ;
        for(int w=0; w<2; w++)
            do {
                pos = (pos+1)%n;
            } while(usd[pos]) ;
        cnt ++ ;
    }
    printf("\n");
    printf("Remaining card: %d\n", pos+1);
}

int main() {
    int n ;

    while(scanf("%d", &n)!=EOF && n!=0)
        testCase(n);
    
    return 0;
}
