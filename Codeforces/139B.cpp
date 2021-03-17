#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();

struct Room {
    int x, z;
};

struct Paper {
    int h, w, c;
};

int calcCost(const Room &r, const Paper &p) {
    if(p.h < r.z)
        return INF;
    int bks = p.h / r.z;
    int tx = bks * p.w;
    return p.c * ((r.x % tx? 1 : 0) + r.x / tx);
}

int main() {
    int R, P ;
    vector <Room> rs;
    vector <Paper> ps;

    scanf("%d", &R);
    for(int i=0, a, b, c; i < R; i++) {
        scanf("%d%d%d", &a, &b, &c);
        rs.push_back({(a + b) * 2, c});
    }
    scanf("%d", &P);
    for(int i=0, a, b, c; i < P; i++) {
        scanf("%d%d%d", &a, &b, &c);
        ps.push_back({a, b, c});
    }

    int ans = 0 ;

    for(const auto &r : rs) {
        int minC = INF;
        for(const auto &p : ps) {
            int x = calcCost(r, p);
            // printf("%d\n", x);
            minC = min(minC, x);
        }
        ans += minC;
    }

    printf("%d\n", ans);
}
