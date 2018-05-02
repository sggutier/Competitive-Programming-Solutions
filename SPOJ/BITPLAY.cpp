#include <bits/stdc++.h>
using namespace std;

int query(int N, int K) {
    if(K==0) return -1;
    N -- ;
    if(N%2 == 0) N --;
    K --;
    int ans = 1;
    for(int i=30; i>0 && K; i--)
        if((1<<i) & N) {
            ans += (1<<i);
            K --;
        }
    return ans;
}

int main() {
    int T;

    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
}
