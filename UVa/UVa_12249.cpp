#include <bits/stdc++.h>
using namespace std;

int opl(int N, char *A, int M, char *B) {
    // printf("%s %s => ", B, A);
    for(int i=max(0, M-N); i<M; i++) {
        int dst = M-i;
        bool works = true;
        for(int j=0; j<dst; j++) {
            if(A[j]!=B[i+j]) {
                works = false;
                break;
            }
        }
        // if(works)
        //     printf("%d\n", dst);
        if(works)
            return dst;
    }
    // printf("0\n");
    return 0;
}

void testCase(int tc) {
    int linCnt;
    scanf("%d", &linCnt);
    int nums[linCnt];
    char lens[linCnt][20];
    int tams[linCnt];
    int ans = 0;

    if(tc==75)
        printf("%d\n", linCnt);

    for(int i=0; i<linCnt; i++) {
        scanf("%s", lens[i]);
        nums[i] = i;
        tams[i] = strlen(lens[i]);
        ans += tams[i];
        if(tc==75)
            printf("%s\n", lens[i]);
    }

    do {
        int sum = tams[nums[0]];
        char anso[(linCnt+1)*10];
        for(int j=0; j<sum; j++)
            anso[j] = lens[nums[0]][j];
        for(int i=1; i<linCnt; i++) {
            char *k = lens[nums[i]];
            int d = tams[nums[i]], t = opl(d, k, sum, anso);
            for(int j=t; j<d; j++)
                anso[sum++] = k[j];
        }
        anso[sum] = 0;
        // for(int i=0; i<linCnt; i++) {
        //     printf("%s\n", lens[nums[i]]);
        // }
        // printf("===> (%d) %s\n", sum, anso);
        ans = min(ans, sum);
    } while(next_permutation(nums, nums+linCnt));

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase(i);
    }
    
    return 0;
}
