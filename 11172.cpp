#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    int a, b;
    for(scanf("%d",&tc); tc; tc--) {
        scanf("%d%d", &a, &b);
        printf("%c\n", a==b? '=' : (a<b? '<' : '>'));
    }

    return 0;
}
