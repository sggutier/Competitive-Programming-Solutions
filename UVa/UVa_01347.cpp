#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;

int N, sa, sb ;
double dsts[limN][limN];
int prevo[limN][limN][2];
double memoMinD[limN][limN][2];

double minD(int p=0, int q=0, int o = 0) {
    if(memoMinD[p][q][o] != -1.0)
        return memoMinD[p][q][o];
    int v = max(p, q) + 1;
    if(v == N-1) {
        //printf("%d %d %d => %.3lf\n", p, q, o, dsts[p][v] + dsts[q][v]);
        return memoMinD[p][q][o] = dsts[p][v] + dsts[q][v];
    }
    else if(v == sa) {
        double x = minD(v, q, 0) + dsts[p][v], y = minD(p, v, 1) + dsts[q][v];
        prevo[p][q][o] = x < y? 0 : 1 ;
        // printf("Hirino? ");
        // printf("%d %d %d => %.3lf\n", p, q, o, min(x, y));
        return memoMinD[p][q][o] = min(x, y);
    }
    else if(v == sb) {
        prevo[p][q][o] = 1-o;
        
        //printf("%d %d %d => %.3lf\n", p, q, o, o==1? dsts[p][v] + minD(v, q) : dsts[q][v] + minD(p, v) );
        return memoMinD[p][q][o] = o==1? dsts[p][v] + minD(v, q, o) : dsts[q][v] + minD(p, v, o) ;
    }
    else {
        double x = minD(v, q, o) + dsts[p][v], y = minD(p, v, o) + dsts[q][v];
        prevo[p][q][o] = x < y? 0 : 1 ;
        //printf("%d %d %d => %.3lf\n", p, q, o, min(x, y));
        return memoMinD[p][q][o] = min(x, y);
    }
    return 1.0;
    //return memoMinD[p][q] = min(dsts[p][v] + minD(v, q),
    //dsts[q][v] + minD(p, v));
}

void testCase() {
    double x[limN], y[limN];

    //printf("%d %d\n", sa, sb);
    if(sa > sb)
        swap(sa, sb);
    for(int i=0; i<N; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
        for(int j=0; j<=i; j++) {
            dsts[i][j] = dsts[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
            memoMinD[i][j][0] = memoMinD[j][i][0] = -1.0;
            memoMinD[i][j][1] = memoMinD[j][i][1] = -1.0;
        }
    }

    // printf("\n");
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++)
    //         printf("%.2lf ", dsts[i][j]);
    //     printf("\n");
    // }
    printf("%.2lf\n", minD());

    int w = 0;
    vector <int> ret[2];
    printf("0");
    for(int p=0, q=0, o=0, v=1; v<N; v++) {
        int sg = prevo[p][q][o];        
        ret[sg].push_back(v);
        if(sg) {
            q = v;
        }
        else {
            //printf(" -%d", v);
            p = v;
        }
        if(v==1)
            w = sg;
        if(v==sa) {
            o = sg;
        }
    }
    for(const int &v:ret[w])
        printf(" %d", v);
    for(int i=ret[1-w].size()-1; i>=0; i--)
        printf(" %d", ret[1-w][i]);
    printf(" 0\n");
}

int main() {
    int tc = 0;
    
    while(scanf("%d%d%d", &N, &sa, &sb)!=EOF && (N || sa || sb)) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}
