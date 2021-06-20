#include <bits/stdc++.h>
using namespace std;
const int limS = 7;
const int limD = 3;
const int dr[] = {-1, 0, 0};
const int dc[] = {0, -1, 1};
const char srx[] = "@IEHOVA#";
const char wds[][10] = {"forth", "left", "right"};

int rowCnt, colCnt;
char mat[10][10];
int path[10];
bool fnd ;

void busca(int pos, int r, int c) {
    if(!(0 <= r && r<rowCnt && 0 <= c && c < colCnt) || mat[r][c]!=srx[pos])
        return;
    if(pos==limS) {
        fnd = true;
        for(int i=0; i<limS; i++)
            printf("%s%c", wds[path[i]], i==limS-1? '\n' : ' ');
        return;
    }
    for(int d=0; d<limD && !fnd; d++) {
        path[pos] = d;
        busca(pos+1, r+dr[d], c+dc[d]);
    }
}

void testCase() {
    fnd = false;
    scanf("%d%d", &rowCnt, &colCnt);
    for(int i=0; i<rowCnt; i++)
        scanf("%s", mat[i]);

    for(int i=0; i<rowCnt; i++) {
        for(int j=0; j<colCnt; j++) {
            if(mat[i][j]!='@')
                continue;
            busca(0, i, j);
            i = rowCnt;
            break;
        }
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
