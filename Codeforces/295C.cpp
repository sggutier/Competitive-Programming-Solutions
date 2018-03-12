#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 55;

ll pasc[limN][limN];
ll ways[limN][limN][2];
int minP[limN][limN][2];

void precalca() {
    for(int i=0; i<limN; i++) {
        for(int j=1; j<i; j++)
            pasc[i][j] = (pasc[i-1][j] + pasc[i-1][j-1]) % mod;
        pasc[i][0] = pasc[i][i] = 1;
    }
}

int main() {
    precalca();
    
    int N, K, A=0, B=0;
    queue <tuple<int, int, int>> Q ;

    scanf("%d%d", &N, &K);
    K /= 50;
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        if(a==50)
            A++;
        else
            B++;
    }

    if(K < 1) {
        printf("-1\n0\n");
        return 0;
    }

    minP[A][B][0] = 1;
    ways[A][B][0] = 1;
    Q.push({A, B, 0});
    while(!Q.empty()) {
        int p, a, b, c, d, t ;
        tie(a, b, p) = Q.front(); Q.pop();
        t = minP[a][b][p] + 1;
        ll w = ways[a][b][p];
        c = A-a, d = B-b;
        // printf("%c [%d %lld] %d %d | %d %d\n", p? 'R' : 'L', t-1, w, a, b, c, d);
        if(p==0) {
            for(int i=0; i<=a; i++) {
                for(int j=0; j<=b; j++) {
                    if(i+j > 0 && i+2*j <= K && (!minP[a-i][b-j][1] || minP[a-i][b-j][1]==t) ) {
                        if(!minP[a-i][b-j][1])
                            Q.push({a-i, b-j, 1});
                        minP[a-i][b-j][1] = t;
                        ways[a-i][b-j][1] = (ways[a-i][b-j][1] + w * ((pasc[a][i]*pasc[b][j])%mod) ) % mod;
                    }
                }
            }
        }
        else {
            // if(c) {
            //     if(!minP[a+1][b][0] || minP[a+1][b][0]==t) {
            //         if(!minP[a+1][b][0])
            //             Q.push({a+1, b, 0});
            //         minP[a+1][b][0] = t;
            //         ways[a+1][b][0] = (ways[a+1][b][0] + w * c) % mod;
            //         printf("\t%lld a %d %d %d\n", w, a+1, b, 0);
            //     }
            // }
            // if(d && K>=2) {
            //     if(!minP[a][b+1][0] || minP[a][b+1][0]==t) {
            //         if(!minP[a][b+1][0])
            //             Q.push({a, b+1, 0});
            //         minP[a][b+1][0] = t;
            //         ways[a][b+1][0] = (ways[a][b+1][0] + w * d) % mod;
            //         printf("\t%lld a %d %d %d\n", w, a, b+1, 0);
            //     }
            // }
            for(int i=0; i<=c; i++) {
                for(int j=0; j<=d; j++) {
                    if(i+j > 0 && i+2*j <= K && (!minP[a+i][b+j][0] || minP[a+i][b+j][0]==t) ) {
                        if(!minP[a+i][b+j][0])
                            Q.push({a+i, b+j, 0});
                        minP[a+i][b+j][0] = t;
                        ways[a+i][b+j][0] = (ways[a+i][b+j][0] + w * ((pasc[c][i]*pasc[d][j])%mod) ) % mod;
                    }
                }
            }
        }
    }

    printf("%d\n", minP[0][0][1]-1);
    printf("%lld\n", ways[0][0][1]);
}
