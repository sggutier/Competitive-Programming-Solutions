#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int tot = 0;
    int mxo = 0;

    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        tot += a;
        mxo = max(mxo, a);
    }

    for(int k = mxo; ; k++) {
        if(N*k - tot > tot) {
            printf("%d\n", k);
            return 0;
        }
    }
}
