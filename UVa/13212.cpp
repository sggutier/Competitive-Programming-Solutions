#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int limN = 1e6+5;

struct BIT {
    int arr[limN];
    void mete(int pos) {
        for(; pos<limN; pos+=(pos&-pos))
            arr[pos]++;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
    void reset() {
        memset(arr, 0, sizeof(arr));
    }
};

int nums[limN];
int ordo[limN];
BIT cnt;

bool comp(const int &a, const int &b) {
    return nums[a] < nums[b];
}

void testCase(int n) {
    cnt.reset();
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        ordo[i] = i;
    }
    sort(ordo, ordo+n, comp);
    long long ans = 0LL;
    for(int i=n-1, tmp; i>=0; i--) {
        tmp = ordo[i]+1;
        ans += cnt.saca(tmp);
        cnt.mete(tmp);
    }
    printf("%lld\n", ans);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);

    return 0;
}
