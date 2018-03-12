#include <bits/stdc++.h>
using namespace std;
const int limS = 3005;
const int limC = 55;
const int limT = 1e4 + 5;
typedef pair<int,int> par;
#define f first
#define s second

int S, C, E, T;
int vals[limS];
double accumProb[limC];
double mP[limT][limC];
vector <par> appls[limS];
int nsuDay[limS];
//double ans[limS];
double ans;

void procST(int s, int gd) {
    if(nsuDay[s] > gd)
        return;
    int val = vals[s];
    double pt = 1.0;
    for(int i=0; i<C; i++) {
        accumProb[i] = 0.0;
    }
    //printf("%d (%d) => ", s+1, val);
    for(const par &app:appls[s]) {
        int t = app.f, c = app.s;
        if(t>=gd)
            break;
        // double sum = 0.0;
        // for(int j=t; j<gd; j++) {
        //     sum += mP[j][c];
        // }
        // pt *= 1.0 - sum;
        pt *= 1.0 - (mP[gd-1][c] - mP[t-1][c]);
        //printf("(%d %d %.3lf %.3lf) ", t, c+1, pt, 1 - (mP[gd-1][c] - mP[t-1][c]));
    }
    //printf("\n");
    ans += pt*val;
}

void simula(int wo) {
    ans = 0.0;
    //printf("Simulando %d\n", wo);
    for(int i=0; i<S; i++)
        procST(i, wo);
}

int main() {
    scanf("%d%d%d%d", &S, &C, &E, &T);
    for(int i=0; i<S; i++) {
        scanf("%d", &vals[i]);
        nsuDay[i] = T+1;
    }
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        if(b==C-1)
            nsuDay[a] = c;
        else
            appls[a].push_back(par(c, b));
    }
    for(int i=1; i<=T; i++) {
        for(int j=0; j<C-1; j++) {
            scanf("%lf", &mP[i][j]);
            mP[i][j] += mP[i-1][j];
        }
    }
    for(int i=0; i<S; i++)
        sort(appls[i].begin(), appls[i].end());

    pair <double, int> pans = make_pair(-1.0, 0);

    for(int i=1; i<=T; i++) {
        // if(i!=4)
        //     continue;
        simula(i);
        pans = max(pans, make_pair(ans, -i));
    }

    printf("%.8lf %d\n", pans.f, -pans.s );
}
