#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxB = 0, maxH = 0;
    int N;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        char tmp[5];
        int a, b ;
        scanf("%s%d%d", tmp, &a, &b);
        if(a > b)
            swap(a, b);
        if(tmp[0] == '+') {
            maxB = max(maxB, b);
            maxH = max(maxH, a);
        }
        else
            printf("%s\n", (a >= maxH && b >= maxB) ? "YES" : "NO");
    }
}
