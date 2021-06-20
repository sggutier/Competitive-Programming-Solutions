#include <bits/stdc++.h>
using namespace std;

int main() {
    char S[1005];
    int tc = 1;

    while(scanf("%s", S)!=EOF && S[0]!='*') {
        printf("Case %d: Hajj-e-%s\n", tc++, S[0]=='H'? "Akbar" : "Asghar");
    }

    return 0;
}
