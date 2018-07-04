#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
typedef pair<int,int> pii;
#define x first
#define y second

int area(pii a, pii b, pii c) {
    return a.x*b.y + b.x*c.y + c.x*a.y -
        (a.y*b.x + b.y*c.x + c.y*a.x);
}

int sgno(int x) {
    if(x==0)
        return x;
    return x<0? -1 : 1;
}

int N ;
pii ptos[limN];

bool funca(int proh) {
    for(int i=0; i<N; i++) {
        if(sgno(area(ptos[(i+N-1)%N], ptos[i], ptos[(i+1)%N])) == proh)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &ptos[i].x, &ptos[i].y);
    printf("%d\n", (funca(1) || funca(-1))? 1 : 0);
}
