#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 3e6 + 5 ;

int N ;
int nums[LIM_N];

int main() {
    int ini = 1 ;

    scanf("%d", &N);
    for(int i=1; i <= N; i++)
        nums[i] = i ;

    for(int k=2; k <= N; k++, ini++) {
        int lst = nums[ini];
        for(int i=k; i < N; i+=k) {
            swap(lst, nums[i + ini]);
        }
        nums[ini + N] = lst ;
    }

    for(int i=0; i < N; i++)
        printf("%d ", nums[ini + i]);
    printf("\n");
}
