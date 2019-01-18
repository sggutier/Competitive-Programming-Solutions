#include <bits/stdc++.h>
using namespace std;

int main() {
    int x ;
    cin >> x ;
    for(int b=1; b<=x; b++) {
        for(int a=b; a <= x; a += b) {
            if(a*b > x && a < x*b) {
                printf("%d %d\n", a, b);
                return 0 ;
            }
        }
    }
    printf("-1\n");
}
