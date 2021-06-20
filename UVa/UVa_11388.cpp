#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    int a, b;

    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d%d", &a, &b);
        if(b%a==0) {
            printf("%d %d\n", a, b);
        }
        else
            printf("-1\n");
    }
}
