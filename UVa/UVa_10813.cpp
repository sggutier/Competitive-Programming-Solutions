#include <bits/stdc++.h>
using namespace std;
const int CARD_CNT = 75;
const int N = 5;

void testCase() {
    vector <int> rows(CARD_CNT+1, -1);
    vector <int> cols(CARD_CNT+1, -1);
    vector <int> diag(CARD_CNT+1, -1);
    vector<int> cntR(5);
    vector<int> cntC(5);
    vector<int> cntD(5);

    cntR[2] = (cntC[2] = (cntD[1] = (cntD[2] = 1)));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==2 && j==2)
                continue;
            int a;
            scanf("%d", &a);
            rows[a] = i;
            cols[a] = j;
            if(i==j)
                diag[a] = 1;
            else if(N-1-i==j)
                diag[a] = 2;
        }
    }

    int winT = 0;
    for(int i=1; i<=CARD_CNT; i++) {
        int a;
        scanf("%d", &a);
        if( (rows[a]!=-1 && (++cntR[rows[a]])==5) ||
            (cols[a]!=-1 && (++cntC[cols[a]])==5) ||
            (diag[a]!=-1 && (++cntD[diag[a]])==5) ) {
            if(!winT)
                winT = i;
        }
    }

    printf("BINGO after %d numbers announced\n", winT);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc--; )
        testCase();
}
