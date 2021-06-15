#include <bits/stdc++.h>
using namespace std;
const int mbit = 29;
// const int mbit = 4;

int query(const int c, const int d, char tp = '?') {
    printf("%c %d %d\n", tp, c, d);
    fflush(stdout);
    if(tp == '!') {
        exit(0);
    }
    int ans ;
    scanf("%d", &ans);
    if(ans == -2) {
        exit(0);
    }
    return ans;
}

int main() {
    int a=0, b=0;
    int forb = 0;
    int lst = query(0, 0);
    for(int i=mbit; i>=0; i--) {
        int q = query(b ^ (1<<i), a ^ (1<<i));
        fprintf(stderr, "lst = %d, q = %d\n", lst, q);
        if(q == lst) {
            fprintf(stderr, "slta\n");
            fprintf(stderr, "En prev %d %d\n", a, b);
            lst = q;
            continue ;
        }
        forb |= 1<<i;
        if(lst == -1)
            b ^= 1<<i;
        else
            a ^= 1<<i;
        lst = query(b, a);
        fprintf(stderr, "En prev %d %d\n", a, b); 
    }
    for(int i=mbit; i>=0; i--) {
        if( (1<<i) & forb)
            continue;
        int q = query(a ^ (1<<i), b);
        if(q == -1) {
            a ^= 1<<i;
            b ^= 1<<i;
        }
        fprintf(stderr, "Al post %d %d\n", a, b); 
    }
    query(a, b, '!');
}
