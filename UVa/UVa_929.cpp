#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
#define par pair<int,int>
#define r first
#define c second
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int grid[limN][limN];
int minP[limN][limN];

void testCase() {
    int rows, cols;
    priority_queue < pair<int, par> > Q ;
    
    scanf("%d%d", &rows, &cols);
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            scanf("%d", &grid[i][j]);
            minP[i][j] = (1<<30);
        }
    }

    Q.push( make_pair(-grid[1][1], par(1, 1) ) );
    while(!Q.empty()) {
        par pos = Q.top().second;
        int dst = -Q.top().first;
        Q.pop();
        if(minP[pos.r][pos.c]!=(1<<30))
            continue;
        minP[pos.r][pos.c] = dst;
        for(int d=0; d<4; d++) {
            par sig = par(pos.r + dr[d], pos.c + dc[d]);
            if(sig.r%(rows+1)==0 || sig.c%(cols+1)==0)
                continue;
            Q.push(make_pair(-(dst + grid[sig.r][sig.c]), sig));
        }
    }
    
    printf("%d\n", minP[rows][cols]);
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
