#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    double mino = 1e9;

    scanf("%d%d", &N, &T);
    for(int i=0, a,b; i<N; i++) {
        scanf("%d%d", &a, &b);
        mino = min(mino, 1.0*a/b);
    }
    printf("%.9lf\n", mino*T);
}
