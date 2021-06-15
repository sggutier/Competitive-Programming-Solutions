#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;
const int mch = 1e6 - 1e5 - 1;

int N ;
int nums[limN];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", N+1);
    printf("1 %d %d\n", N, mch);
    for(int i=0; i<N; i++)
        nums[i] += mch;
    for(int i=0; i<N; i++) {
        printf("2 %d %d\n", i+1, nums[i] -i);
        for(int j=i; j<=i; j++)
            nums[j] %= nums[i]-i;
    }
    return 0;

    for(int i=0; i<N; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
