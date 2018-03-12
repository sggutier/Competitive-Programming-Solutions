#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    int sum=0, maxSum = 0;
    for(int tmp; n; n-- ){
        scanf("%d", &tmp);
        sum += tmp;
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);
    }
    if(maxSum>0)
        printf("The maximum winning streak is %d.\n", maxSum);
    else
        printf("Losing streak.\n");
}

int main() {
    int n;

    while(scanf("%d",&n)!=EOF && n)
        testCase(n);
    
    return 0;
}
