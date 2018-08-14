#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
typedef long long ll;

char str[limN];
bool posb[limN][limN];
bool usd[limN][limN];
int sigP[limN];
ll ansMin[limN][limN], ansMax[limN][limN];

void recalc(int l, int r, int p) {
    if(!posb[l+1][p-1] || !posb[p][r])
        return;
    if(str[l] == '+') {
        ansMin[l][r] = min(ansMin[l][r], ansMin[l+1][p-1] + ansMin[p][r]);
        ansMax[l][r] = max(ansMax[l][r], ansMax[l+1][p-1] + ansMax[p][r]);
    }
    else {
        ansMin[l][r] = min(ansMin[l][r], ansMin[l+1][p-1] - ansMax[p][r]);
        ansMax[l][r] = max(ansMax[l][r], ansMax[l+1][p-1] - ansMin[p][r]);
    }
    posb[l][r] = true;
}

void memo(int l, int r) {
    if(usd[l][r])
        return;
    ansMin[l][r] = 1e18;
    ansMax[l][r] = -ansMin[l][r];
    usd[l][r] = true;
    posb[l][r] = false;
    if(l > r)
        return;
    if(isdigit(str[l])) {
        if( (str[l] == '0' && l != r) || r-l > 8)
            return;
        ll ans = 0;
        for(int i=l; i<=r; i++) {
            ans = ans*10 + str[i]-'0';
            if(!isdigit(str[i]))
                return;
        }
        ansMin[l][r] = ansMax[l][r] = ans;
        posb[l][r] = true;
        return;
    }
    if(str[l]=='-' && l != r) {
        memo(l+1, r);
        if(posb[l+1][r]) {
            posb[l][r] = true;
            ansMin[l][r] = min(-ansMin[l+1][r], -ansMax[l+1][r]);
            ansMax[l][r] = max(-ansMin[l+1][r], -ansMax[l+1][r]);
        }
    }
    for(int i=r; l+1 < i && r-i <= 8; i--) {
        if(!isdigit(str[i]))
            break;
        if(str[i]=='0' && i!=r)
            continue;
        memo(l+1,i-1);
        memo(i,r);
        recalc(l,r,i);
    }
    for(int k=sigP[l+1]; k<=r; k=sigP[k]) {
        memo(l+1, k-1);
        memo(k,r);
        recalc(l,r,k);
    }
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    int N = strlen(str);
    for(int w = N, i=N-1; i>=0; i--) {
        sigP[i] = w;
        if(!isdigit(str[i]))
            w = i;
    }
    memo(0,N-1);
    printf("%lld %lld\n", ansMin[0][N-1], ansMax[0][N-1]);
}

int main() {
    while(scanf("%s", str) != EOF)
        testCase();
}
