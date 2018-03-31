#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool usd[35][8];
ll waysMemo[35][8];

ll ways(int n, int msk=0) {
    if(n==0)
        return msk==0;
    if(usd[n][msk])
        return waysMemo[n][msk];
    usd[n][msk] = true;
    if(msk==0)
        return waysMemo[n][msk] =
            ways(n-1, 7) +
            ways(n-1, 1) +
            ways(n-1, 4) ;
    else if(msk==1)
        return waysMemo[n][msk] =
            ways(n-1, 0) +
            ways(n-1, 6) ;
    else if(msk==4)
        return waysMemo[n][msk] =
            ways(n-1, 0) +
            ways(n-1, 3) ;
    else if(msk==3)
        return waysMemo[n][msk] =
            ways(n-1, 4) ;
    else if(msk==6)
        return waysMemo[n][msk] =
            ways(n-1, 1) ;
    else if(msk==7)
        return waysMemo[n][msk] = ways(n-1, 0);
    return -1e9;
}

int main() {
    int n ;
    while(scanf("%d", &n)!=EOF && n!=-1)
        printf("%lld\n", ways(n));
}
