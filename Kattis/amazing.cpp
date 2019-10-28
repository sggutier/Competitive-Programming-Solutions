#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define r first
#define c second
const int gridSiz = 100;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
char dirs[][10] = {"up", "right", "down", "left"};

bool usd[2*gridSiz + 1][2*gridSiz + 1][4];
pii pos = {gridSiz, gridSiz};

bool move(const int d) {
    if(usd[pos.r][pos.c][d])
        return false;
    printf("%s\n", dirs[d]);
    fflush(stdout);
    char tmp[10];
    scanf("%s", tmp);
    usd[pos.r][pos.c][d] = true;
    if(tmp[0] == 's') {
        exit(0);
    }
    else if(tmp[0] == 'o') {
        pos.r += dr[d];
        pos.c += dc[d];
        return true;
    }
    usd[pos.r + dr[d]][pos.c + dc[d]][(d + 2) % 4] = true;
    return false;
}

void dfs(const int d) {
    for(int i=-1, w=(d + 3) % 4; i<=1; i++, w = (w + 1) % 4) {
        if(move(w))
            dfs(w);
    }
    move((d + 2) % 4);
}

int main() {
    for(int i=0; i<4; i++)
        if(move(i))
            dfs(i);
    printf("no way out\n");
    fflush(stdout);
}
