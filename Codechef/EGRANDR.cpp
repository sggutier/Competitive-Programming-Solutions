#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool testCase() {
    int N ;
    int mino = 5, maxo = 0, sumo = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        mino = min(mino, a);
        maxo = max(maxo, a);
        sumo += a;
    }

    return mino > 2 && maxo == 5 && sumo >= 4*N;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        printf("%s\n", testCase()? "Yes" : "No");
}
