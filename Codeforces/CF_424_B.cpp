#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 1003;
const int megaC = 1e6;

int main() {
    int N, r ;
    par cords[limN];

    scanf("%d%d", &N, &r);
    cords[N] = {0, r};
    for(int i=0; i<N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cords[i] = {a*a + b*b, c};
    }
    N++;

    sort(cords, cords+N);
    r = 0;
    for(int i=0; i<N; i++) {
        r += cords[i].s;
        if(r >= megaC) {
            printf("%.9lf\n", sqrt(cords[i].f));
            return 0;
        }
    }

    printf("-1\n");
}
