#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const int bs = 1000;
const int limN = 250000 ;
// const int H = (1<<16);
const int H = 50000;

inline int scan(){
	int x = 0;
	char c = getchar_unlocked();
	while(c < '0' || c > '9'){
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar_unlocked();
	}
	return x;
}

struct BIT {
    int arr[H+5];
    BIT() {
        memset(arr, 0, sizeof(arr));
    }
    void mete(int pos, int nov) {
        for(; pos<=H; pos+=(pos & -pos))
            arr[pos] += nov;
    }
    int cnt(int pos) {
        int ans = 0;
        for(; pos>0; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

BIT bts[250 + 5];
int arr[limN + 5];
int mods[limN + 5];

void mete(int x, int y) {
    x--;
    bts[x/bs].mete(y, 1);
}

void saca(int x, int y) {
    x--;
    bts[x/bs].mete(y, -1);
}

int cuenta(int xl, int xr, int y) {
    int ans = 0;
    for(; xl<=xr && mods[xl] != 1; xl++)
        if(arr[xl] <= y)
            ans ++;
    for(; xl<=xr && mods[xr]; xr--)
        if(arr[xr] <= y)
            ans ++;
    if(xl <= xr) {        
        for(int pl=(xl-1)/bs, pr=(xr-1)/bs; pl<=pr; pl++)
            ans += bts[pl].cnt(y);
    }
    return ans;
}

int main() {
    int N ;
    int Q ;
    ll ans = 0;
    BIT bt;

    N = scan();
    for(int i=1; i<=N; i++) {
        mods[i] = i % bs;
        arr[i] = scan();
        mete(i, arr[i]);
        // ans += i-1 - cuenta(1, i-1, arr[i]);
        // printf("\t%d => %d\n", arr[i], i-1 - cuenta(1, i-1, arr[i]));
    }
    // printf("%lld\n", ans);

    for(int i=N; i; i--) {
        ans += bt.cnt(arr[i]-1);
        bt.mete(arr[i], 1);
    }

    for(Q=scan(); Q; Q--) {
        int x, y, z;
        x = scan();
        y = scan();
        z = y;        
        y = arr[x];

        if(z==y) {
            printf("%lld\n", ans);
            continue;
        }

        ans -= x-1 - cuenta(1, x-1, y);
        ans -= cuenta(x+1, N, y-1);
        saca(x, y);
        arr[x] = z;
        mete(x, z);
        y = z;
        ans += x-1 - cuenta(1, x-1, y);
        ans += cuenta(x+1, N, y-1);
        
        printf("%lld\n", ans);
    }
}
