#include <bits/stdc++.h>
using namespace std;

int tc(int n) {
    int ans = (1<<30);
    for(int i=1; i*i<=n; i++) {
        if(n%i)
            continue;
        for(int j=i; i*j<=n; j++) {
            if((n/i)%j)
                continue;
            int k = n/(i*j);
            ans = min(ans, 2*(i*j + i*k + j*k));
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", tc(tmp));
    }
    return 0;
}
