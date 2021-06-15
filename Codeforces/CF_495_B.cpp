#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b ;
    cin >> a >> b ;

    if(a < b) {
        printf("0\n");
        return 0 ;
    }
    if(a == b) {
        printf("infinity\n");
        return 0 ;
    }

    a -= b;
    int ans = 0 ;

    for(int i=1; i*i <= a; i++) {
        if(a % i)
            continue;
        if(b < i)
            ans ++;
        if(i*i != a && a/i > b)
            ans ++;
    }

    printf("%d\n", ans);
}
