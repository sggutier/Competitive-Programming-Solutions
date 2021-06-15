// - I am not sure how to prove it, but I strongly believe that only amounts that are multiple
//   of 0.25 can be made with the bills.
// - If that is viewed in the way described above, all the amounts can be multiplied by 100
//   (to avoid cents and work with integer amounts) and divided by 25.
// - Since 0.25 was the lowest precision that could be had and the bills can be divided by 2,
//   it makes sense to divide them all the way to have the smallest amounts possible of bills.
//   Anything below would be something of the form a_i/2^k, and by themselves would not be able
//   to form an integer.
// - An integer can be formed if two or more of the fractions above can be added together so it
//   makes an integer.  If two numbers can be added to get a power of 2, it means that 1 (0.25) can
//   be made.  In other words, we want two numbers a and b such that ax + by = 2^k.  For this
//   it is neccessary that gcd(a, b) divides 2^k, and this last thing is only possible if
//   gcd(a, b) = 1. Since nor a nor b are multiple of 2, gcd(a, b) is not a multiple of 2 so if
//   it divides a power of 2 it must be 1.
// - More numbers in the sum actually do not help at all, so only pairwise gcds have to be
//   checked.
// - If it is not possible to get a 1, the amount of change might still be made, but the standard dp
//   for giving change has to be done.  This one has a complexity of O(nm), and makes about
//   n*m/25 operations.  The pairwise checking part has a complexity of O(m^2), and since m <= 1000,
//   it is enough to pass the test cases.
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
