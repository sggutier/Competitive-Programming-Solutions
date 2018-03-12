#include <bits/stdc++.h>
using namespace std;

int N, H, ANS, MN = (1 << 30);
int V[15];

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        scanf("%d", &V[i]);
    }
    scanf("%d", &H);

    for(int i=0;i<N;i++) {
        int NR = H % V[i];
        if(NR < MN) {
            MN = NR, ANS = V[i];
        }
    }

    printf("%d\n", ANS);
    return 0;
}
