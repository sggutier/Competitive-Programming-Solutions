#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
const int limN = 1e5 + 5;

struct Eqn {
    ll a, b, c;
    Eqn() {}
    Eqn(pt p, pt q) {
        a = q.y - p.y;
        b = p.x - q.x;
        c = p.x*q.y - q.x*p.y;
    }
    bool works(pt p) {
        return a*p.x + b*p.y == c;
    }
    void printa() {
        // printf("F es %lld %lld %lld\n", a, b, c);
    }
};

pt pts[limN];
int col[limN];

bool funca(int N) {
    memset(col, 0, sizeof(col));
    Eqn f = Eqn(pts[0], pts[1]) ;
    f.printa();
    int cnt = 0;
    for(int i=0; i<N; i++)
        if(f.works(pts[i])) {
            // printf("%d en linea\n", i);
            col[i] = 1;
            cnt ++;
        }
    f = Eqn(pts[2], pts[3]);
    f.printa();
    for(int i=0; i<N; i++)
        if(col[i]!=1 && f.works(pts[i])) {
            // printf("%d en linea\n", i);
            col[i] = 2;
            cnt ++;
        }
    // printf("cnt termina siendo %d\n", cnt);

    return cnt>=N;
}

int main() {
    int N ;    

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%lld%lld", &pts[i].x, &pts[i].y);

    if(N <= 4) {
        printf("YES\n");
        return 0;
    }

    sort(pts, pts+4);
    do {
        if(funca(N)) {            
            printf("YES\n");
            return 0;
        }
    } while(next_permutation(pts, pts+4));

    printf("NO\n");
}
