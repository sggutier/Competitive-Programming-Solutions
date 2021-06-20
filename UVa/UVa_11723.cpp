#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    int tc = 0;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Case %d: ", ++tc);
        if(27*b>=a)
            printf("%d\n", (int) ceil(a/(1.0*b))-1);
        else
            printf("impossible\n");
    }
}
