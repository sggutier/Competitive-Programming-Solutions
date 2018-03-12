#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
#define par pair<int,int>
#define r first
#define c second
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int rows, cols;
bool bomba[limN][limN];
int minP[limN][limN];

inline bool validPos(par pos) {
    return 0 <= pos.r && pos.r < rows && 0 <= pos.c && pos.c < cols && !bomba[pos.r][pos.c] && !minP[pos.r][pos.c];
}

void bfs(par pos) {
    queue <par> Q;
    minP[pos.r][pos.c] = 1;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            par sig = pos;
            sig.r += dr[d]; sig.c += dc[d];
            if(validPos(sig)) {
                Q.push(sig);
                minP[sig.r][sig.c] = minP[pos.r][pos.c] +1;
            }
        }
    }
}

void testCase() {
    int brows;
    par ini, fin;
    memset(bomba, 0, sizeof(bomba));
    memset(minP, 0, sizeof(minP));

    scanf("%d", &brows);
    while(brows--) {
        int row, woo, tmp ;
        scanf("%d%d", &row, &woo);
        while(woo--) {
            scanf("%d", &tmp);
            bomba[row][tmp] = true;
        }
    }
    scanf("%d%d", &ini.r, &ini.c);
    scanf("%d%d", &fin.r, &fin.c);

    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++)
    //         printf("%d", bomba[i][j]);
    //     printf("\n");
    // }

    bfs(ini);
    printf("%d\n", minP[fin.r][fin.c]-1);
    // printf("%d\n", abs(ini.r-fin.r) + abs(ini.c - fin.c));
}

int main() {
    while(scanf("%d%d", &rows, &cols)!=EOF && (rows || cols))
        testCase();
}
