#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

bool usdA[limN], usdB[limN];
int memoA[limN], memoB[limN];

int mea(int n) {
    if(usdA[n])
        return memoA[n];
    usdA[n] = true;
    memoA[n] = 1e9 ;
    int k = n ;
    while(k) {
        if(k % 10) {
            memoA[n] = min(memoA[n], 1 + mea(n-k%10));
        }
        k /= 10;
    }
    return memoA[n];
}

int meb(int n) {
    if(usdB[n])
        return memoB[n];
    usdB[n] = true;
    memoB[n] = 1e9 ;
    // if(n%10)
    //     return memoB[n] = 1 + meb(n-n%10);
    int maxK = 0, k = n;
    while(k) {
        maxK = max(k%10, maxK);
        k /= 10;
    }
    return memoB[n] = 1 + meb(n-maxK);
}

int getMaxK(long long n) {
    int maxK = 0;
    long long k = n, d;
    while(k) {
        d = k/10;
        maxK = max((int) (k-d*10), maxK);
        if(maxK==9)
            return 9;
        k = d;
    }
    return maxK;
}

int mec(long long n) {
    int ans = 0;
    while(n) {
        n -= getMaxK(n);
        ans ++;
    }
    return ans;
}

int mec2(long long n) {
    int ans = 0;    
    while(n) {
        int maxK = 0;
        long long k = n, d;
        long long pot=1;
        long long ninpos = -1;
        while(k) {
            d = k/10;
            maxK = max((int) (k-d*10), maxK);
            if(k-d*10 == 9)
                ninpos = pot;
            pot *= 10;
            k = d;
        }
        if(ninpos == -1) {
            n -= maxK;
            ans ++;
        }
        else {            
            d = (n%ninpos)/9 + 1;
            //printf("%lld %lld %lld\n", n, d, ninpos);
            ans += d;
            n -= 9*d;
        }
    }
    return ans;
}

int main() {
    int n ;
    usdA[0] = usdB[0] = true;
    cin >> n ;
    // cout << mec2(n) << endl;
    // return 0;
    for(int i=1, u=0, ud=0, c=0; i<=n; i++) {
        // if(mec(i) != meb(i)) {
        //     printf("%d => %d %d %s\n", i, mea(i), meb(i), mea(i)!=meb(i)? "Squeee" : "");
        // }
        if(mec(i) != mec(i-1)) {
            if(i-u != ud) {
                printf("Cnt de %d (%d)\n", c, ud);
                c = 0;
            }
            ud = i-u;
            c ++ ;
            //printf("%d %d %d || %d (%d) => %d (%d)\n", i-u, ud, c, i-1, mec(i-1), i, mec(i));
            u = i;
        }
        // if(mec(i) != mec2(i))
        //     printf("%d (%d) => %d (%d)\n", i, mec(i), i, mec2(i));
    }
    // long long n;
    // int ans = 0;
    // scanf("%lld", &n);
    // while(n) {
    //     n -= getMaxK(n);
    //     ans ++;
    // }
    // printf("%d\n", ans);
}
