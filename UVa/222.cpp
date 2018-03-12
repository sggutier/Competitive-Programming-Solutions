#include <bits/stdc++.h>
using namespace std;
const int limN = 55;
const double inf = 1e9;
const double eps = 1e-6;

int stopCnt;
double tankCap, carEfc;
double gasPrice[limN], dst[limN];
double reqNext[limN];
double ans = inf;

void minCostSt(int pos=0, double tank=0.0, double crg=0.0) {
    if(crg>ans)
        return;
    if(pos==stopCnt) {
        ans = crg;
        return;
    }
    if(!(tank*2.0 - eps < tankCap || tank - eps <reqNext[pos]))
        return;
    crg = (pos>0? crg + 200.0 + round((tankCap-tank)*gasPrice[pos]) : round(gasPrice[0]));
    // printf("%d %.2lf %.2lf\n", pos, tank, crg/100.0);
    for(int i=pos+1; i<=stopCnt; i++) {
        double rem = tankCap - (dst[i]-dst[pos])/carEfc;
        if(rem<0.0)
            break;
        minCostSt(i, rem, crg);
    }
    // printf("%d (%.2lf %.2lf) => %.2lf\n", pos, dst[pos], gasPrice[pos]/100.0, (200.0 + (tankCap-tank)*gasPrice[pos] + ans)/100.0);
}

void testCase(double fin) {
    scanf("%lf%lf%lf%d", &tankCap, &carEfc, &gasPrice[0], &stopCnt);
    for(int i=1; i<=stopCnt; i++) {
        scanf("%lf%lf", &dst[i], &gasPrice[i]);
    }
    dst[++stopCnt] = fin;
    gasPrice[0] *= 100.0;
    // gasPrice[0] /= tankCap;

    for(int i=0; i<stopCnt; i++) {
        reqNext[i] = (dst[i+1]-dst[i])/carEfc;
    }
    // for(int i=0; i<=stopCnt; i++) {
    //     printf("%.2lf %.2lf %.2lf\n", dst[i], gasPrice[i]/100.0, reqNext[i]);
    // }
    ans = inf;
    reqNext[stopCnt] = inf;
    minCostSt();
    printf("minimum cost = $%.2lf\n", ans/100.0);
}

int main() {
    double tmp ;
    int tc = 0;

    while(scanf("%lf", &tmp)!=EOF && tmp!=-1.0) {
        printf("Data Set #%d\n", ++tc);
        testCase(tmp);
    }
    
    return 0;
}
