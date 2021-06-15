#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;

int N ;
int nums[2*limN];
int ans = 1e9;

void calcS(const int p = 1, int sm = 0) {
    if(p==N+1) {
        ans = min(ans, sm);
        if(sm) return ;
        for(int i=0; i<2*N; i++)
            printf("%d ", nums[i]);
        printf(" ==>> %d\n", sm);
        return;
    }
    for(int i=0; i<2*N; i++) {
        if(nums[i]) continue;
        nums[i] = p;
        for(int j=(p!=N? i+N-p : i+1); j<2*N; j++) {
            if(nums[j]) continue;
            nums[j] = p;
            calcS(p+1, sm + (N-p) * abs(j-i+p - N));
            nums[j] = 0;
            if(p != N)
                break;
        }
        nums[i] = 0;
    }
}

int main() {
    scanf("%d", &N);

    for(int i=1, p=1; i < N; i+=2, p++) {
        nums[p] = i;
        nums[p + N-i] = i;
    }
    for(int i=2, p=N+1; i < N; i+=2, p++) {
        nums[p] = i;
        nums[p + N-i] = i;
    }
    for(int i=1; i<=2*N; i++)
        if(!nums[i])
            nums[i] = N;

    for(int i=1; i<=2*N; i++)
        printf("%d ", nums[i]);
    printf("\n");
    return 0 ;
    
    calcS();
    printf("ans = %d\n", ans);
}
