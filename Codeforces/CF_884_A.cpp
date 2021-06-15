#include <bits/stdc++.h>
using namespace std;
const int dt = 86400;

int main() {
    int N, t;
    
    scanf("%d%d", &N, &t);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        t -= dt-a;
        if(t <= 0) {
            printf("%d\n", i+1);
            return 0;
        }
    }
}
