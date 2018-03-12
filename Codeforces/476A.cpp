#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    int s, p;

    cin >> n >> d ;
    s = n/2 + n%2;
    p = n/2 ;

    while(true) {
        if(s%d==0) {
            printf("%d\n", s) ;
            return 0;
        }
        if(p) {
            s++;
            p--;
        }
        else
            break;
    }

    printf("-1\n");
}
