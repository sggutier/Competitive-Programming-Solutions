#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int divo = 1900;

int main() {
    int N;
    int minR = -inf, maxR = inf;
    int s = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int c, t;
        scanf("%d%d", &c, &t);
        if(t==1)
            minR = max(minR, divo-s);
        else
            maxR = min(maxR, divo-1-s);
        s += c;
    }

    if(minR > maxR)
        printf("Impossible\n");
    else if(maxR == inf)
        printf("Infinity\n");
    else
        printf("%d\n", maxR+s);
}
