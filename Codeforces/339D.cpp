#include <bits/stdc++.h>
using namespace std;
const int limN = (1<<17);
const int limB = 17;

int nums[limB+1][limN];

int main() {
    int N, Q;
    int B;
    scanf("%d%d", &N, &Q);
    B = 1<<N;
    for(int i=0; i<B; i++)
        scanf("%d", &nums[N][i]);
    for(int i=N-1, pr=0; i>=0; i--, pr^=1) {
        // printf("%d => %d\n", i, (1<<i)-1);
        for(int j=(1<<i)-1; j>=0; j--) {
            if(pr)
                nums[i][j] = nums[i+1][j<<1] ^ nums[i+1][(j<<1)|1];
            else
                nums[i][j] = nums[i+1][j<<1] | nums[i+1][(j<<1)|1];
        }
    }
    while(Q--) {
        int j, v;
        scanf("%d%d", &j, &v);
        j--;
        nums[N][j] = v;
        for(int i=N-1, pr=0; i>=0; i--, pr^=1) {
            j >>= 1;            
            if(pr)
                nums[i][j] = nums[i+1][j<<1] ^ nums[i+1][(j<<1)|1];
            else
                nums[i][j] = nums[i+1][j<<1] | nums[i+1][(j<<1)|1];
        }
        printf("%d\n", nums[0][0]);
    }
}
