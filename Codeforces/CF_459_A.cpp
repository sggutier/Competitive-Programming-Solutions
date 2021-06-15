#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

int main() {
    int xs[2], ys[2];
    set <pii> usd;
    for(int i=0; i<2; i++) {
        scanf("%d%d", &xs[i], &ys[i]);
        usd.insert({xs[i], ys[i]});
    }
    sort(xs, xs+2);
    sort(ys, ys+2);
    if(xs[1]-xs[0] != 0 && ys[1]-ys[0] != 0 && xs[1]-xs[0] != ys[1]-ys[0]) {
        printf("-1\n");
        return 0;
    }
    if(xs[0] == xs[1])
        xs[1] = xs[0] + ys[1]-ys[0];
    if(ys[0] == ys[1])
        ys[1] = ys[0] + xs[1]-xs[0];
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            if(!usd.count({xs[i], ys[j]}))
                printf("%d %d ", xs[i], ys[j]);
    printf("\n");
}
