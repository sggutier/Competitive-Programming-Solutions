#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1, 0, 1, 0} ;
int dc[] = {0, 1, 0, -1};
int miDict[300] ;
#define par pair<int, int>
#define r first
#define c second
const int limR = (2e2) + 5;
const int limC = (5e1 + 5)*4;

void ff(int rows, int cols, char mapa[limR][limC], int r, int c) {
    queue <par> Q ;
    Q.push(par(r, c));
    mapa[r][c] = '2';
    while(!Q.empty()) {
        par pos = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            par sig = pos;
            sig.r += dr[d];
            sig.c += dc[d];
            if(sig.r<0 || sig.r>=rows || sig.c<0 || sig.c>=cols || mapa[sig.r][sig.c]!='0')
                continue ;
            mapa[sig.r][sig.c] = '2';
            Q.push(sig);
        }
    }
}

int holeCnt(int rows, int cols, char mapa[limR][limC], int r, int c) {
    int ans = 0 ;
    queue <par> Q ;
    Q.push(par(r, c));
    mapa[r][c] = '3';
    while(!Q.empty()) {
        par pos = Q.front(); Q.pop();
        // printf(">> %d %d\n", pos.r, pos.c);
        // getchar() ;
        for(int d=0; d<4; d++) {
            par sig = pos;
            sig.r += dr[d];
            sig.c += dc[d];
            if(sig.r<0 || sig.r>=rows || sig.c<0 || sig.c>=cols || mapa[sig.r][sig.c]>'1')
                continue ;
            if(mapa[sig.r][sig.c]=='0') {
                ff(rows, cols, mapa, sig.r, sig.c);
                ans ++ ;
            }
            else {
                // printf(">>> %d %d\n", sig.r, sig.c);
                mapa[sig.r][sig.c] = '3';
                Q.push(sig);
            }
        }
    }
    return ans ;
}

inline int toDec(char a) {
    return (a>='a' && a<='z')? a - 'a' + 10 : a-'0';
}

void testCase(int rowsCpy, int colsCpy) {
    char mapa[limR][limC];
    char encLine[limC];
    map <int, int> ans ;
    int rows = rowsCpy, cols = (colsCpy+2) * 4 - 2;

    for(int j=0; j<=cols+1; j++)
        mapa[0][j] = mapa[rows+1][j] = '0';
    for(int i=1; i<=rows; i++) {
        scanf("%s", (encLine + 1) );
        encLine[0] = encLine[colsCpy+1] = '0';
        for(int j=0; j<=colsCpy+1; j++) {
            int num = toDec(encLine[j]);
            for(int b=0; b<4; b++)                
                mapa[i][4*j+(3-b)] = ((1<<b) & num)? '1' : '0';
        }
    }

    // printf("\n");
    // for(int i=0; i<=rows+1; i++)
    //     printf("%s\n", mapa[i]);
    // return ;

    ff(rows+2, cols+2, mapa, 0, 0);
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            if(mapa[i][j]=='1') {
                ans[miDict[holeCnt(rows+2, cols+2, mapa, i, j)]] ++ ;
            }
        }
    }

    for(auto &a: ans) {
        for(int i=a.second; i; i--)
            printf("%c", a.first);        
    }
    printf("\n");
}

int main() {
    miDict[1] = 'A';
    miDict[3] = 'J';
    miDict[5] = 'D';
    miDict[4] = 'S';
    miDict[0] = 'W';
    miDict[2] = 'K';
    
    int a , b ;
    int tc = 1;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Case %d: ", tc++);
        testCase(a, b);
    }
    
    return 0;
}
