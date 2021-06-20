#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int limD = 6;
const int limN = 14;

int picCnt;
par pics[limN];
char posb[1<<limN][limD+1][limD+1];

char calcAns(int msk, int rem, int l, int r) {
    if(posb[msk][l][r])
        return posb[msk][l][r];
    if(rem==1) {
        for(int i=0; i<picCnt; i++) {
            if((1<<i) & msk)
                continue;
            if((pics[i].f == l && pics[i].s == r) || (pics[i].s == l && pics[i].f == r))
                return posb[msk][l][r] = 'Y';
        }
        return posb[msk][l][r] = 'N';
    }
    for(int i=0; i<picCnt; i++) {
        if((1<<i) & msk)
            continue;
        if(pics[i].f==l) {
            if(calcAns(msk | (1<<i), rem-1, pics[i].s, r)=='Y')
                return posb[msk][l][r] = 'Y';
        }
        if(pics[i].s==l) {
            if(calcAns(msk | (1<<i), rem-1, pics[i].f, r)=='Y')
                return posb[msk][l][r] = 'Y';
        }
        if(pics[i].s==r) {
            if(calcAns(msk | (1<<i), rem-1, l, pics[i].f)=='Y')
                return posb[msk][l][r] = 'Y';
        }
        if(pics[i].f==r) {
            if(calcAns(msk | (1<<i), rem-1, l, pics[i].s)=='Y')
                return posb[msk][l][r] = 'Y';
        }
    }
    return posb[msk][l][r] = 'N';
}

void testCase(int n) {
    memset(posb, 0, sizeof(posb));
    int a, b, x, y;

    scanf("%d", &picCnt);
    scanf("%d%d%d%d", &a, &b, &x, &y);
    for(int i=0; i<picCnt; i++) scanf("%d%d", &pics[i].f, &pics[i].s);
    printf("%s\n", calcAns(0, n, b, x)=='Y'? "YES" : "NO");
}

int main() {
    int n;
    
    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
}
