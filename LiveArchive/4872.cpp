#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int limN = 1005;

double dst(const pii p1, const pii p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

bool usd[limN];
double minDst[limN];
pii pts[limN];
priority_queue <pair<double, int> > Q;

void testCase(int N) {
    double ans = 0;
    memset(usd, 0, sizeof(usd));
    for(int i=0; i<N; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
    }
    Q.push({-0, 0});
    while(!Q.empty()) {
        int pos = Q.top().y;
        if(usd[pos]) {
            Q.pop();
            continue;
        }
        usd[pos] = true;
        ans -= Q.top().x;
        Q.pop();
        for(int i=0; i<N; i++) {
            if(i==pos || usd[i]) continue;
            Q.push({-dst(pts[i], pts[pos]), i});
        }
    }
    printf("%.2lf\n", ans);
}

int main() {
    int N ;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
}
