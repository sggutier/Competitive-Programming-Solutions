#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int usd[limN][limN];

bool inside(int x, int y, const int &S) {
    if((x < 0 && y>0) || (x>0 && y<0))
        x += S;
    x = abs(x)%(2*S), y = abs(y)%(2*S);
    return (0 <= x && x <= S && 0 <= y && y <= S) || (S <= x && S <= y) || x==0 || y==0;
}

int testCase(int id, int S, int x, int y, int dx, int dy) {
    if(!inside(x,y,S))
        return 0;
    int ans = 0;
    // x = abs(x)%S;
    // y = abs(y)%S;
    // while(usd[x][y]!=id) {
    for(int k=1e6; k; k--) {
        // usd[x][y] = id;
        ans ++;
        if(!inside(x + dx, y + dy, S)) {
            return ans;
        }
        // x = abs(x+dx)%S;
        // y = abs(y+dy)%S;
        x += dx;
        y += dy;
    }
    return -1;
}

int main() {
    int S,  x,  y,  dx,  dy;
    int tc = 1;

    while(scanf("%d%d%d%d%d", & S, & x, & y, & dx, &dy) != EOF && (S || x || y || dx || dy)) {
        int k = testCase(tc++,  S,  x,  y,  dx,  dy);
        if(k==-1) {
            printf("The flea cannot escape from black squares.\n");
        }
        else {
            printf("After %d jumps the flea lands at (%d, %d).\n", k, x + k*dx, y + k*dy);
        }
    }
    
    return 0;
}
