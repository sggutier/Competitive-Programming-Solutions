#include <bits/stdc++.h>
using namespace std;
const int limN = 505;

double testCase(int N, double p) {
    double dp[2][limN][limN];
    double (*cur)[limN] = dp[0], (*prev)[limN] = dp[1];
    double ans = 0.0;
    double p2 = 1-p;

    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++)
            prev[i][j] = cur[i][j] = 0.0;
    prev[0][0] = 1.0;

    for(int pos=1; pos<=N; pos++, swap(cur, prev)) {
        //double sumo = 0.0;
        cur[0][0] = prev[0][0]*p2;
        //printf("%d => %.2lf\n", 0, cur[0][0]);
        //sumo += cur[0][0];
        for(int maxSeg=1; maxSeg<=pos; maxSeg++) {
            double *CUR = cur[maxSeg], *PREV = prev[maxSeg];
            double sumo = PREV[0]*p2;
            //CUR[0] = PREV[0]*p2;
            for(int seg=1; seg<=maxSeg; seg++) {
                CUR[seg] = PREV[seg-1]*p;
                //CUR[0] += PREV[seg]*p2;
                sumo += PREV[seg]*p2;
            }
            CUR[maxSeg] += prev[maxSeg-1][maxSeg-1]*p;
            CUR[0] = sumo;
            // printf("%d => ", maxSeg);
            // for(int i=0; i<=maxSeg; i++) {
            //     printf("%.2lf ", CUR[i]);
            //     sumo += CUR[i];
            // }
            // printf("\n");
        }
        // printf("sumo = %.2lf\n", sumo);
        // printf("------\n");
    }

    for(int maxS=1; maxS<=N; maxS++) {
        double suma = 0.0;
        for(int seg=0; seg<=maxS; seg++)
            suma += prev[maxS][seg];
        ans += suma*maxS;
    }
    
    return ans;    
}

int main() {
    int N;
    double p;

    while(scanf("%d%lf", &N, &p)!=EOF && N)
        printf("%.10lf\n", testCase(N, p));
    
    return 0;
}
