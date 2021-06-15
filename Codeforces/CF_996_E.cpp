#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define x first
#define y second
const int LIM_N = 1e5 + 5;

inline ll tam(const pii v) {
    return v.x*v.x + v.y*v.y;
}

int N ;
pii pts[LIM_N];
int ords[LIM_N];
int ans[LIM_N];

int main() {
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
        ords[i] = i;
    }

    if(N == 1) {
        printf("1\n");
        return 0 ;
    }

    sort(ords, ords+N,
         [](const int a, const int b) {
             return tam(pts[a]) > tam(pts[b]);
         });

    pii ansV = {1e18, 0};

    for(int a=0; a < 2; a++) {
        for(int b=0; b < 2; b++) {
            pii pos = {
                (a? 1 : -1) * pts[ords[0]].x + (b? 1 : -1) * pts[ords[1]].x,
                (a? 1 : -1) * pts[ords[0]].y + (b? 1 : -1) * pts[ords[1]].y};
            // printf("> %lld %lld => %lld\n", pos.x, pos.y, tam(pos));
            for(int i=2; i < N; i++) {
                int x = ords[i];
                ans[x] = tam({pos.x + pts[x].x, pos.y + pts[x].y}) <= tam({pos.x - pts[x].x, pos.y - pts[x].y})? 1 : -1;
                pos = ans[x] == 1? pii(pos.x + pts[x].x, pos.y + pts[x].y) : pii(pos.x - pts[x].x, pos.y - pts[x].y);
            }
            ansV = min(ansV, {tam(pos), a*2 + b});
            // printf("%lld %lld => %lld\n", pos.x, pos.y, tam(pos));
        }
    }

    int a = ansV.second & 2? 1 : -1;
    int b = ansV.second & 1? 1 : -1;
    // printf(">> %d %d\n", a, b);
    pii pos = {
                a * pts[ords[0]].x + b * pts[ords[1]].x,
                a * pts[ords[0]].y + b * pts[ords[1]].y};
    ans[ords[0]] = a;
    ans[ords[1]] = b;
    // printf("> %lld %lld => %lld\n", pos.x, pos.y, tam(pos));
    for(int i=2; i < N; i++) {
        int x = ords[i];
        ans[x] = tam({pos.x + pts[x].x, pos.y + pts[x].y}) <= tam({pos.x - pts[x].x, pos.y - pts[x].y})? 1 : -1;
        pos = ans[x] == 1? pii(pos.x + pts[x].x, pos.y + pts[x].y) : pii(pos.x - pts[x].x, pos.y - pts[x].y);
    }
    // printf("> %lld %lld => %lld\n", pos.x, pos.y, tam(pos));

    for(int i=0; i < N; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
