#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
const int LIM_N = 2e5 + 5 ;

int BIT[LIM_N];
int tot[LIM_N];

void mete(int pos, const int nov) {
    tot[pos] += nov ;
    for(; pos < LIM_N; pos += pos & -pos)
        BIT[pos] += nov ;
}

int saca(int pos) {
    int ans = 0 ;
    for(; pos; pos -= pos & -pos)
        ans += BIT[pos];
    return ans ;
}

void testCase(int N) {
    map <int, int> rev ;
    pii pts[N+1];
    pii scrs[N+1];
    int maxX = 0;
    set <int> maxYs ;

    // printf("N = %d\n", N) ;
    for(int i=0; i < N; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        rev[pts[i].y];
    }

    function<void(pii&, int, int, int)> fncs[] = {
        [](pii &scr, const int y, const int xig, const int dst) {
            int a = saca(y-1) - xig;
            int b = dst - xig - a - tot[y];
            scr.x += a;
            scr.y += b ;
        },
        [](pii &scr, const int y, const int xig, const int dst) {
            int a = saca(y-1) ;
            int b = dst - xig - a - tot[y];
            scr.x += b;
            scr.y += a ;
        }
    };
    int posInis[] = {0, N-1};
    int posFins[] = {N, -1};
    int dirs[] = {1, -1};

    int k = 1 ;
    for(auto &it : rev)
        it.second = k++ ;
    for(int i=0; i < N; i++) {
        pts[i].y = rev[pts[i].y] ;
        // printf("%c = (%d, %d)\n", i + 'A', pts[i].x, pts[i].y);
    }
    sort(pts, pts+N);

    for(int w=0; w < 2; w++) {
        memset(BIT, 0, sizeof(BIT));
        memset(tot, 0, sizeof(tot));
        int ini = posInis[w], fin = posFins[w], dir = dirs[w];
        auto f = fncs[w];
        int xig = 0, lastX = 1e9 ;
        for(int i=ini; i != fin; i += dir) {
            if(pts[i].x != lastX) {
                xig = 0 ;
                lastX = pts[i].x;
            }
            f(scrs[i], pts[i].y, xig, abs(i - ini));
            mete(pts[i].y, 1);
            xig ++ ;
        }
    }

    // printf("\n");
    pts[N].x = pts[N-1].x + 1 ;
    for(int i=0, lastX = pts[0].x; i <= N; i++) {
        if(pts[i].x != lastX) {
            int locMin = scrs[i-1].x;
            for(int j=i-1; j >= 0 && pts[j].x == lastX; j--) {
                locMin = min(locMin, scrs[j].x);
            }
            maxX = max(maxX, locMin);
        }
        lastX = pts[i].x;
    }
    for(int i=0, lastX = pts[0].x; i <= N; i++) {
        if(pts[i].x != lastX) {
            int locMin = scrs[i-1].x ;
            for(int j=i-1; j >= 0 && pts[j].x == lastX; j--) {
                locMin = min(locMin, scrs[j].x);
            }
            if(locMin == maxX) {
                int my = 0 ;
                for(int j=i-1; j >= 0 && pts[j].x == lastX; j--) {
                    my = max(my, scrs[j].y);
                }
                maxYs.insert(my);
            }
        }
        lastX = pts[i].x;
    }
    // for(int i=0; i < N; i++) {
    //     printf("%d %d  =>   %d %d\n", pts[i].x, pts[i].y, scrs[i].x, scrs[i].y);
    // }

    printf("Stan: %d; Ollie:", maxX);
    for(const int y : maxYs) {
        printf(" %d", y);
    }
    printf(";\n");
}

int main() {
    int N ;
    while(scanf("%d", &N) != EOF && N) {
        testCase(N);
    }
}
