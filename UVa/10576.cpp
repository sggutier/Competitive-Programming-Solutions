#include <bits/stdc++.h>
using namespace std;

int nums[14];
int A, B;
int ans ;

void bruta(int pos=1, int sum=0, int tot=0) {
    // printf("%d %d %d (%d) => ", pos, sum, tot, (sum>=0 && pos>5));
    // for(int i=1; i<pos; i++)
    //     printf("%d ", nums[i]);
    // printf("\n");
    if(sum>=0 && pos>5)
        return;
    if(pos==13) {
        ans = max(ans, tot);
        return;
    }
    nums[pos] = A;
    bruta(pos+1, sum + A + (pos>=5? -nums[pos-5] : 0), tot + A);
    nums[pos] = -B;
    bruta(pos+1, sum - B + (pos>=5? -nums[pos-5] : 0), tot - B);
}

void testCase() {
    ans = -(1<<30);
    bruta();
    if(ans>=0)
        printf("%d\n", ans);
    else
        printf("Deficit\n");
}

int main() {
    while(scanf("%d%d", &A, &B)!=EOF)
        testCase();
    
    return 0;
}
