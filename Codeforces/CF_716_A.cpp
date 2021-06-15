#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int cnt = 1, lst ;

    scanf("%d%d", &N, &K) ;
    scanf("%d", &lst);
    for(int i=1; i<N; i++) {
        int tmp;
        scanf("%d", &tmp) ;
        if( tmp-lst <= K )
            cnt ++ ;
        else 
            cnt = 1;
        lst = tmp;
    }

    printf("%d\n", cnt ) ;
    
    return 0;
}
