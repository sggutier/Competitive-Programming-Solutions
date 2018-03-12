#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define x first
#define y second
const int limBeep = 16;

int beepNum;
par beepers[limBeep+1];
bool usd[1<<limBeep][limBeep];
int minP[1<<limBeep][limBeep];

int dist(par A, par B) {
    return abs(A.x - B.x) + abs(A.y - B.y);
}

int calcMinP(int mask, int pos) {
    if(usd[mask][pos])
        return minP[mask][pos];
    int ans = (1<<30);
    usd[mask][pos] = true;
    for(int b=0; b<beepNum; b++) {
        if((1<<b) & mask) {
            ans = min(ans, dist(beepers[b], beepers[pos]) + calcMinP(mask ^ (1<<b), b));
        }
    }
    return minP[mask][pos] = ans;
}

void testCase() {
    par kar;
    int ans = (1<<30);
    scanf("%d%d", &kar.x, &kar.y);
    scanf("%d%d", &kar.x, &kar.y);
    scanf("%d", &beepNum);
    for(int i=0; i<beepNum; i++)
        scanf("%d%d", &beepers[i].x, &beepers[i].y);

    memset(usd, 0, sizeof(usd));
    for(int i=0; i<beepNum; i++) {
        usd[0][i] = true;
        minP[0][i] = dist(kar, beepers[i]);
    }

    for(int i=0; i<beepNum; i++) {
        ans = min(ans, calcMinP(((1<<beepNum) -1) ^ (1<<i), i) + dist(kar, beepers[i]));
    }
    printf("The shortest path has length %d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(; tc; tc--)
        testCase();
    return 0;
}
