#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2005 ;
const ll mod = 1e9 + 7 ;

struct Mod {
	ll x;
    Mod() {}
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }	
};


bool usd[limN][limN] ;
Mod dp[limN][limN];


Mod memo(int n, int k) {
    if(n == 0)
        return 1 ;
    if(usd[n][k])
        return dp[n][k];
    usd[n][k] = true;
    if(k == 0) {
        // return dp[n][k] = memo(n-1, 0) * n ;
        dp[n][k] = memo(n-1, 0) * n ;
        // printf("%d %d => %lld\n", n, k, dp[n][k].x);
        return dp[n][k] ;
    }
    // if(k < n)
    //     dp[n][k] = Mod(n-k) * (memo(n-1, k-1)  + memo(n-1, k));
    // else
    // dp[n][k] = Mod(k) * memo(n-1, k-2);
    if(k >= 2)
        dp[n][k] = Mod(k-1) * memo(n-1, k-2);
    if(n != k)
        dp[n][k] = dp[n][k] + Mod(n-k) * memo(n-1, k-1);
    // printf("%d %d => %lld\n", n, k, dp[n][k].x);
    return dp[n][k];
}

int N ;
bool asdf[limN] ;
int arr[limN] ;

int main() {
    int x = 0, y = 0;
    
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        if(a != -1)
            asdf[a-1] = true;
        else
            x ++;
        arr[i] = a;
    }

    for(int i=0; i<N; i++)
        if(arr[i] == -1 && !asdf[i])
            y++;

    printf("%lld\n", memo(x, y).x);
}
