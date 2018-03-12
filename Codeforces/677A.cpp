#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, h;
    int a ;
    int ans = 0;

    scanf("%d%d", &N, &h);
    ans = N;
    while(N--) {
        scanf("%d", &a);
        if(a > h)
            ans ++;
    }

    printf("%d\n", ans);
}
