#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef pair<int, char> par;
#define f first
#define s second

char str[limN];
par maxN[limN];
par req[limN];
int wos[limN];

int main() {
    int N ;
    int ans = 0;
    
    scanf("%s", str);
    N = strlen(str);

    for(int i=N-1, cer=0; i>=0; i--) {
        maxN[i] = maxN[i+1];
        wos[i] = wos[i+1];
        if(str[i]=='0') {
            cer ++;
            continue;
        }
        wos[i] ++;
        printf("%d %c\n", cer, str[i]);
        req[i] = {cer, str[i]};
        maxN[i] = max(maxN[i], req[i]);
        cer = 0;
    }

    // for(int i=0; i<N; i++) {
    //     printf("%d => %d %d %c\n", i, wos[i], maxN[i].f, maxN[i].s);
    // }

    for(int i=0; i<N; i++) {
        if(str[i+1]!='0' && par(i, str[0]) >= maxN[i+1] ) {
            ans = wos[i+1] + 1;
            break;
        }
    }
    
    printf("%d\n", ans);
}
