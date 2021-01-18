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

int questCnt = 0 ;

int getVal() {
    char tmp[20];
    scanf("%s", tmp);
    return tmp[0] == 'Y';
}

int askTrian(set<pii> pts) {
    questCnt ++;
    assert(questCnt <= 60);
    printf("? %d", (int) pts.size());
    for(auto &p : pts)
        printf(" %d %d", p.x + 1, p.y + 1);
    printf("\n");
    fflush(stdout);
    return getVal();
}

int bs(const int N, pii corn) {
    int ini = 0, fin = N-1;
    while(ini < fin) {
        int piv = (ini + fin) / 2 ;
        pii dx = {corn.x + (corn.x? -1 : 1) * piv, corn.y};
        pii dy = {corn.x, corn.y + (corn.y? -1 : 1) * piv};
        if(askTrian({corn, dx, dy})) {
            fin = piv ;
        }
        else {
            ini = piv+1;
        }
    }
    return ini;
}

int getDiag(int N, pii corn) {
    pii dx = {corn.x + (corn.x? -1 : 1) * (N-1), corn.y};
    pii dy = {corn.x, corn.y + (corn.y? -1 : 1) * (N-1)};
    if(askTrian({corn, dx, dy})) {
        return bs(N, corn);
    }
    corn.x = (N-1) - corn.x;
    corn.y = (N-1) - corn.y;
    int pos = bs(N, corn);
    return (N-1) + ((N-1) - pos);
}

int main() {
    int N ;
    scanf("%d", &N);
    int diagX = getDiag(N, {0, 0});
    int diagY = getDiag(N, {N-1, 0}) - (N-1);
    // x+y = diagX
    // y-x = diagY
    // 2y = diagX + diagY
    int y = (diagX + diagY) / 2;
    int x = diagX - y;
    printf("! %d %d\n", x + 1, y + 1);
    fflush(stdout);
}
