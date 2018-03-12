#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
const int inf = 1e9 ;

vector <int> prims;
bool comp[limN];

void criba(int N = limN) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++)
        if(!comp[i])
            prims.push_back(i);
}

int main() {
    criba();
    int N, M ;
    int p ;

    scanf("%d%d", &N, &M);
    p = *lower_bound(prims.begin(), prims.end(), N-1);
    printf("%d %d\n", p, p);
    printf("1 2 %d\n", p-(N-2));
    for(int i=2; i<N; i++)
        printf("%d %d 1\n", i, i+1);
    M -= (N-1);
    for(int i=1; i<N && M; i++) {
        for(int j=i+2; j<=N && M; j++) {
            printf("%d %d %d\n", i, j, inf);
            M--;
        }
    }
}
