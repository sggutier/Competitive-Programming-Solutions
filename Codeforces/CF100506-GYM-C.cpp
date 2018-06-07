#include <bits/stdc++.h>
using namespace std;
const int limN = 5e4 + 5;

bool testCase() {
    int k, k2 ;
    int n ;
    set<int> nums;

    scanf("%d.%d", &k, &k2);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        //printf("%d => %d, ", i, a);
        a = a*100;
        while(a % 2 == 0) {
            a /= 2;
        }
        a /= 25;
        // printf("%d\n", a);
        nums.insert(a);
    }

    if(k2 % 25)
        return 0;

    for(const int a : nums) {
        for(const int b : nums) {
            if(__gcd(a, b) == 1)
                return 1;
        }
    }
    
    bitset <limN> posb;
    k = k*100 + k2;
    k /= 25;
    // printf("k = %d\n", k);

    posb[0] = true;
    for(int i=0; i<k; i++) {
        if(!posb[i]) continue;
        // printf("Trying with %d\n", i);
        for(const int w : nums) {
            if(i + w <= k) {
                posb[i + w] = true;
                // printf("\t%d enabled (thx to %d)\n", i+ w, w);
            }
            else
                break;
        }
    }

    return posb[k];
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        printf("%s\n", testCase()? "yes" : "no");
    }
}
