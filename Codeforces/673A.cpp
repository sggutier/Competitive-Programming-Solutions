#include <bits/stdc++.h>
using namespace std;
const int limN = 91;

bool usd[limN+1];

int main() {
    int N ;

    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        usd[a] = true;
    }

    for(int i=1, c=0; i<limN; i++) {
        if(usd[i]) {
            c = 0;
            continue;
        }
        c ++;
        if(c==15) {
            printf("%d\n", i);
            return 0;
        }       
    }

    printf("%d\n", 90);
}
