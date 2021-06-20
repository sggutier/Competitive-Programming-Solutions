#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define x first
#define y second
const double inf = 1e9;
const double eps = 1e-9;

inline double dst(par A, par B) {
    return hypot(A.x - B.x, A.y - B.y);
}

void testCase() {
    int nodeCnt;
    vector<par> nodePos;
    vector<vector<double>> minP;

    scanf("%d", &nodeCnt);
    nodePos = vector<par>(nodeCnt);
    minP = vector<vector<double>>(nodeCnt, vector<double>(nodeCnt,inf));
    for(int i=0; i<nodeCnt; i++) {
        scanf("%d%d", &nodePos[i].x, &nodePos[i].y);
    }
    for(int i=0; i<nodeCnt; i++) {
        for(int j=i; j<nodeCnt; j++) {
            double d = dst(nodePos[i], nodePos[j]);
            if(d <= 10.0)
                minP[i][j] = minP[j][i] = d ;
        }
    }

    for(int k=0; k<nodeCnt; k++) 
        for(int i=0; i<nodeCnt; i++)
            for(int j=0; j<nodeCnt; j++)
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j]);

    double ans = 0.0;
    for(int i=0; i<nodeCnt; i++) {
        for(int j=0; j<nodeCnt; j++) {
            if(minP[i][j]==inf) {
                printf("Send Kurdy\n");
                return ;
            }
            ans = max(ans, minP[i][j]);
        }
    }

    printf("%.4lf\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        // if(i!=1)
        //     printf("\n");
        printf("Case #%d:\n", i);
        testCase();
        printf("\n");
    }
}
