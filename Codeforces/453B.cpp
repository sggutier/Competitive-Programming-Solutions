#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bn {
    ll nums[3];
    bn() {
        nums[0] = nums[1] = nums[2] = 0LL;
    }
    bn(ll *arr) {
        for(int i=0; i<3; i++)
            nums[i] = arr[i];
    }
    bn sho(int k) {
        ll ans[] = {nums[0], nums[1], nums[2]} ;
        ans[2] <<= k;
        for(int i=1; i>=0; i--) {
            ans[i] <<= k;
            ll d = ans[i] >> 55;
            ans[i+1] += d;
            ans[i] -= d << 55;
        }
        return bn(ans);
    }
    bn operator+(const bn &otr) {
        ll ans[3];
        for(int i=0; i<3; i++)
            ans[i] = nums[i] ^ otr.nums[i];
        return bn(ans);
    }
    void printa() {
        int n = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<55; j++) {
                if((1LL<<j) & nums[i])
                    n = 55*i + j;
            }
        }
        printf("%d\n", n);
        for(int i=0; i<3; i++) {
            for(int j=0; j<55; j++) {
                if(55*i + j > n) {
                    printf("\n");
                    return;
                }
                printf("%d ", (1LL<<j) & nums[i]? 1 : 0);
            }
        }
        printf("\n");
    }
};

int main() {
    bn x, y;
    x.nums[0] = 1;
    y.nums[0] = 2;
    int n ;
    cin >> n ;
    for(int i=1; i<n; i++) {
        bn z = y.sho(1) + x;
        x = y;
        y = z;
    }
    y.printa();
    x.printa();
}
