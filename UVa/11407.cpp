#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 ;

int minReq[limN + 5];

void precarga() {
    for(int i=1; i<=limN; i++) {
        minReq[i] = (1<<30);
        for(int j=1; j*j<=i; j++) {
            minReq[i] = min(minReq[i], minReq[i - j*j] + 1);
        }
    }
}

int main() {
    precarga();

    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a;
        scanf("%d", &a);
        printf("%d\n", minReq[a]);
    }
    
    return 0;
}
