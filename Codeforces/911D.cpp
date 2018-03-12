#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;

int main() {
    int N, Q ;
    int nums[limN];
    int sgn = 0;
    char strs[2][10] = {"even", "odd"};

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        for(int j=0; j<i; j++)
            if(nums[j] > nums[i])
                sgn ^= 1;
    }
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        sgn = (sgn + (b-a+1)/2)%2;
        printf("%s\n", strs[sgn]);
    }

}
