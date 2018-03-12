#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    scanf("%d%d", &R, &C);
    R = min(R, C);
    printf("%d\n", R+1);
    for(int i=0; i <= R; i++ ) {
        printf("%d %d\n", i, R-i);
    }
}
