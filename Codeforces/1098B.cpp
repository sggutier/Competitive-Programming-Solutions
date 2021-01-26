#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 3e5 + 5 ;

int R, C ;
vector <string> mapa;
vector <string> ans;
int rev[128];
int lets[4];

int calcRw(int a, int b, int x, int y, int dx, int dy) {
    int ansV = 0 ;
    for(; x < R && y < C; x += dx, y += dy) {
        ans[x][y] = lets[a];
        if(mapa[x][y] != a)
            ansV ++;
        swap(a, b);
    }
    return ansV;
}

int calcCst(int a, int b, int dx, int dy, bool print = false) {
    int ans = 0 ;
    int c = -1, d ;
    for(int i=0; i < 4; i++) {
        if(i == a || i == b) continue;
        if(c == -1)
            c = i ;
        else
            d = i;
    }
    for(int i=0, j=0; i < R && j < C; i += dy, j += dx) {
        int ca = calcRw(a, b, i, j, dx, dy);
        int cb = calcRw(b, a, i, j, dx, dy);
        if(ca < cb) {
            ans += ca ;
            if(print)
                calcRw(a, b, i, j, dx, dy);
        }
        else {
            ans += cb ;
            if(print)
                calcRw(b, a, i, j, dx, dy);
        }
        swap(a, c);
        swap(b, d);
    }
    return ans;
}

int main() {
    rev['C'] = 1;
    rev['G'] = 2;
    rev['T'] = 3;
    lets[0] = 'A';
    lets[1] = 'C';
    lets[2] = 'G';
    lets[3] = 'T';
    char tmp[LIM_N];
    scanf("%d%d", &R, &C);
    mapa.resize(R);
    ans.resize(R);
    for(int i=0; i < R; i++) {
        scanf("%s", tmp);
        mapa[i] = tmp;
        ans[i] = tmp;
        for(int j=0; j < C; j++) {
            mapa[i][j] = rev[(int) mapa[i][j]];
        }
    }

    int minCst = R*C + 1;
    int ansDx, ansDy, ansA, ansB;
    for(int dx=0, dy=1; dx < 2; dx++, dy--) {
        for(int a=0; a < 4; a++) {
            for(int b=a+1; b < 4; b++) {
                int c = calcCst(a, b, dx, dy);
                if( c >= minCst ) continue;
                minCst = c ;
                ansDx = dx;
                ansDy = dy;
                ansA = a;
                ansB = b;
            }
        }
    }

    calcCst(ansA, ansB, ansDx, ansDy, true);
    // printf("%d\n", minCst);
    for(int i=0; i < R; i++)
        printf("%s\n", ans[i].c_str());
}
