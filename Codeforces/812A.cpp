#include <bits/stdc++.h>
using namespace std;

int mdo[4];
int p[4];

int main() {
    for(int i=0; i<4; i++) {
        for(int j=3; j>0; j--) {
            int a ;
            scanf("%d", &a);
            mdo[i] |= a;
            mdo[(i+j)%4] |= a;
        }
        scanf("%d", &p[i]);
    }
    for(int i=0; i<4; i++) {
        if(mdo[i] && p[i]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
