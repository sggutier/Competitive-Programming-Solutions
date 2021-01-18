#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll,ll> pll;

void testCase(int R) {
    pll coords[R];
    // set <pll> cnts;
    int K = 0 ;
    // printf("\n\n");
    for(int i=0, a, b, c; i < R; i++) {
        scanf("%d%d%d", &a, &b, &c);
        coords[K].x = b - a ;
        coords[K].y = c - b ;
        // ll g = __gcd(abs(coords[K].x), abs(coords[K].y));
        // coords[K].x /= g;
        // coords[K].y /= g;
        // printf("(%lld, %lld),\n", coords[K].x, coords[K].y);
        // if(cnts.count(coords[K]) == 0) {
        //     cnts.insert(coords[K]);
        //     K ++ ;
        // }
        K ++ ;
    }
    if(K < 2) {
        printf("No\n");
        return ;
    }
    sort(coords, coords+K,
         [](const pll &A, const pll &B) {
             int sgnA = A.y > 0 ;
             int sgnB = B.y > 0 ;
             if(sgnA != sgnB)
                 return sgnA > sgnB;
             __int128 lenA = A.x * A.x ;
             lenA *= (B.x * B.x + B.y * B.y) * (A.x < 0? -1 : 1);
             __int128 lenB = B.x * B.x ;
             lenB *= (A.x * A.x + A.y * A.y) * (B.x < 0? -1 : 1);
             if(sgnA)
                 return lenA > lenB ;
             else
                 return lenA < lenB ;
         });
    // printf("----------\n");
    // for(int i=0; i < K; i++) {
    //     printf("(%lld, %lld),\n", coords[i].x, coords[i].y);
    // }
    for(int i=0; i < K; i++) {
        if(coords[i].x * coords[(i+1) % K].y - coords[(i+1) % K].x * coords[i].y < 0) {
            printf("No\n");
            return ;
        }
    }
    printf("Yes\n");
}

int main() {
    int R ;
    while(scanf("%d", &R) != EOF && R)
        testCase(R);
}
