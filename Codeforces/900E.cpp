#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5 ;

int N, K ;
char S[LIM_N];
int cnts[2][LIM_N][2];
int cstRpl[LIM_N];
int qMrkCnt[LIM_N];
pair <int, int> ans[LIM_N] ;

int main() {
    scanf("%d%s%d", &N, S+1, &K);
    for(int i=1; i <= N; i++) {
        cstRpl[i] = -1;
        cnts[0][i][0] = cnts[0][i-1][0];
        cnts[0][i][1] = cnts[0][i-1][1];
        cnts[1][i][0] = cnts[1][i-1][0];
        cnts[1][i][1] = cnts[1][i-1][1];
        qMrkCnt[i] = qMrkCnt[i-1];
        if(S[i] != '?')
            cnts[S[i] - 'a'][i][i%2] ++ ;
        else
            qMrkCnt[i] ++ ;
    }
    K -- ;
    for(int i=1; i + K <= N; i++) {
        int cntA = cnts[0][i+K][(i+1)%2] - cnts[0][i-1][(i+1)%2];
        int cntB = cnts[1][i+K][i%2] - cnts[1][i-1][i%2];
        // printf("%d => %d %d\n", i, cntA, cntB);
        if(cntA || cntB)
            continue ;
        cstRpl[i] = qMrkCnt[i+K] - qMrkCnt[i-1];
    }
    // printf("\n");
    for(int i=N-K; i > 0; i--) {
        ans[i] = ans[i+1];
        if(cstRpl[i] != -1) {
            auto pr = ans[i+K+1];
            pr.first ++;
            pr.second -= qMrkCnt[i+K] - qMrkCnt[i-1];
            ans[i] = max(ans[i], pr);
        }
    }
    // for(int i=1; i <= N; i++) {
    //     printf("%d %d | %d | %d %d | %d %d\n", ans[i].first, ans[i].second, qMrkCnt[i], cnts[0][i][0], cnts[0][i][1], cnts[1][i][0], cnts[1][i][1]);
    // }
    printf("%d\n", -ans[1].second);
}
