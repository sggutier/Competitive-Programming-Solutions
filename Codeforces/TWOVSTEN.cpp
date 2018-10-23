#include <bits/stdc++.h>
using namespace std;

int testCase(long long n) {
    if(n%5) return -1;
    int ans = 0;
    while(n%10)
        n *= 2, ans++;
    return ans;
}

int main() {
    int tc, n;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &n);
        printf("%d\n", testCase(n));
    }
}
