#include <bits/stdc++.h>
using namespace std;

char str[100];
int nums[100];

void testCase() {
    int N = 0;
    int maxH = 0, minH = 1;
    nums[0] = 1;
    for(; str[N]; N++) {
        nums[N+1] = nums[N] + (str[N]=='C'? 0 : (str[N]=='R'? 1 : -1));
        if(str[N]=='F')
            nums[N]--;
        maxH = max(maxH, nums[N]);
        minH = min(minH, nums[N]);
    }
    nums[0] = max(1, 2-minH);
    N = 0;
    maxH = 0;
    for(; str[N]; N++) {
        nums[N+1] = nums[N] + (str[N]=='C'? 0 : (str[N]=='R'? 1 : -1));
        if(str[N]=='F')
            nums[N]--;
        maxH = max(maxH, nums[N]);
    }
    for(int i=maxH; i>0; i--) {
        printf("|");
        int ultH = -1;
        for(int j=0; j<N; j++) {
            if( nums[j]==i )
                ultH = j;
        }
        if(ultH!=-1)
            printf(" ");
        for(int j=0; j<=ultH; j++) {
            if(nums[j]!=i)
                printf(" ");
            else
                printf("%c", str[j]=='C'? '_' : (str[j]=='R'? '/' : '\\'));
        }
        printf("\n");
    }
    printf("+-");
    for(int i=0; i<=N; i++)
        printf("-");
    printf("\n");
}

int main() {
    int tc;

    gets(str);
    sscanf(str, "%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case #%d:\n", i);
        gets(str);
        testCase();
        printf("\n");
    }
    
    return 0;
}
