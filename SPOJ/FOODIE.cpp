#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N, K ;
    vector <bool> posb;
    scanf("%d%d", &N, &K);
    posb.resize(K+1);
    posb[0] = true;
    for(int i=0; i < N; i++) {
        int k, sm =0;
        scanf("%d", &k);
        for(int j=0, a; j < k; j++) {
            scanf("%d", &a);
            sm += a;
        }
        for(int j=K; j >= sm; j--)
            if(posb[j - sm])
                posb[j] = true;
    }
    for(int i=K; i >= -1; i--) {
        if(!posb[i]) continue;
        printf("%d\n", i);
        break;
    }
}

int main() {
    int tc ;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
