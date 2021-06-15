#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    scanf("%d%d", &N, &x);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        if(i) x--;
        x -= a;
    }
    printf("%s\n", x==0? "YES" : "NO");
}
