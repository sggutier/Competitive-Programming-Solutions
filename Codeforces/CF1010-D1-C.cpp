#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N, W ;
bool usd[limN];
bool wa[limN];
set <int> gs2;
vector<int> divs;

int main() {
    scanf("%d%d", &W, &N);
    usd[0] = true;
    for(int i=0, a; i<W; i++) {
        scanf("%d", &a);
        a %= N;
        a = __gcd(a, N);
        if(a==1) {
            printf("%d\n", N);
            for(int i=0; i<N; i++)
                printf("%d ", i);
            printf("\n");
            return 0;
        }
        // printf("[%d %d] ", a, __gcd(a, N));
        gs2.insert(a);
    }
    int wowo = 0;
    // for(const int g : gs2) {
    //     wa[g] = true;
    //     for(const int g2 : gs2) {
    //         wa[__gcd(g, g2)] = true;
    //     }
    // }
    for(const int g : gs2)
        wowo = __gcd(wowo, g);
    divs.push_back(wowo);
    for(int i=0, g; i<N; i++) {
        if(!wa[i]) continue;
        g = i;
        bool fca = true;
        for(const int d : divs) {
            if(g % d == 0) {
                fca = false;
                break;
            }
        }
        if(fca) {
            divs.push_back(g);
            // printf("%d ", g);
        }
    }
    // printf("\n");

    int ans = 1;
    for(int i=1; i<N; i++) {
        for(const int d : divs) {
            if(d <= i && usd[i-d]) {
                usd[i] = true;
                break;
            }
        }
        if(usd[i])
            ans ++;
    }

    printf("%d\n", ans);
    for(int i=0; i<N; i++)
        if(usd[i])
            printf("%d ", i);
    printf("\n");
}
