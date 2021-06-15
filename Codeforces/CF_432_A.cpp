#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, k;
    int cnt = 0;

    scanf("%d%d", &N, &k);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        a = 5-a;
        if(a >= k)
            cnt ++;
    }

    printf("%d\n", cnt/3);
}
