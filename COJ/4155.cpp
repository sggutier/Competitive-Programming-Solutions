#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int limN = 1005;

int PR, PC;
char mapa[limN][limN];
int W ;
pii pts[limN*limN];

bool funca() {
    for(int i=0; i<PR; i++) {
        for(int j=0; j<PC; j++) {
            if(mapa[i][j] != 'x')
                continue;
            for(int k=0, r, c; k<W; k++) {
                r = i + pts[k].x;
                c = j + pts[k].y;
                if(r < 0 || PR <= r || c < 0 || PC <= c || mapa[r][c] == '.')
                    return false;
                mapa[r][c] = '.';
            }
        }
    }
    return true;
}

void lee() {
    int R, C;
    scanf("%d%d", &PR, &PC);
    scanf("%d%d", &R, &C);
    for(int i=0; i<PR; i++)
        scanf("%s", mapa[i]);
    W = 0;
    char tmp[limN];
    int fst = 0;
    int minX=0, minY=0;

    for(int i=0; i<R; i++) {
        scanf("%s", tmp);
        for(int j=0; j<C; j++) {
            if(tmp[j] == 'x') {
                if(!(fst++))
                    minX = i, minY = j;
                pts[W++] = {i-minX, j - minY};
            }
        }
    }    
}

void testCase() {
    lee();
    printf("%s\n", funca()? "TAK" : "NIE");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
