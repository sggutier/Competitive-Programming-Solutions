#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e4 + 5;

void testCase() {
    char multi[LIM_N];
    char org[LIM_N];
    int multiL, orgL;

    fgets(multi, LIM_N, stdin);
    fgets(org, LIM_N, stdin);
    multiL = strlen(multi);
    orgL = strlen(org);
    multi[--multiL] = 0;
    org[--orgL] = 0;

    int delCnt = 0, otrC = 0;
    for(int i=0; i < multiL; i++) {
        if(multi[i] == org[otrC]) {
            otrC = (otrC+1) % orgL;
        }
        else {
            delCnt++;
        }
    }
    if(otrC) {
        delCnt += otrC;
    }

    printf("%d\n", delCnt);
}

int main() {
    int T ;
    char S[LIM_N];

    fgets(S, LIM_N, stdin);
    for(sscanf(S, "%d", &T); T; T--) {
        testCase();
    }
}
