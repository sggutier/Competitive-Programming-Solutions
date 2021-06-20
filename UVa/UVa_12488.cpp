#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    map <int, int> revr;
    int org[n], nov[n];
    
    for(int i=0; i<n; i++) {
        scanf("%d", &org[i]);
        revr[org[i]] = i;
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &nov[i]);
        nov[i] = revr[nov[i]];
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++)
            if(nov[j] > nov[i])
                ans ++;
    }

    printf("%d\n", ans);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
