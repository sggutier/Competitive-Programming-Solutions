#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int x, y;
    scanf("%d%d", &y, &x);
    x--, y--;
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int sn = 1;

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n");
    printf("\n");

    do {
        if(nums[x]!=y)
            continue;
        bool works = true;
        for(int i=1; i<8; i++) {
            for(int j=0; j<i; j++) {
                if(abs(nums[j]-nums[i])==i-j) {
                    i = 8;
                    works = false;
                    break;
                }
            }
        }
        if(works) {
            printf("%2d     ", sn++);
            for(int i=0; i<8; i++)
                printf(" %d", nums[i]+1);
            printf("\n");
        }
    } while(next_permutation(nums, nums+8));
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
