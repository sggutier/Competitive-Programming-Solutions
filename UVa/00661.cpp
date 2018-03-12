#include <bits/stdc++.h>
using namespace std;

void testCase(int N, int M,  int C) {
    int sum = 0;
    int arr[N];
    bool usd[N];
    int maxSum = 0;

    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        usd[i] = 0;
    }
    for(int i=0; i<M; i++) {
        int t;
        scanf("%d", &t);
        t--;
        sum += arr[t] * (usd[t]? -1 : 1);
        usd[t] = !usd[t];
        maxSum = max(maxSum, sum);
    }

    if(maxSum > C)
        printf("Fuse was blown.\n");
    else {
        printf("Fuse was not blown.\n");
        printf("Maximal power consumption was %d amperes.\n", maxSum);
    }
}

int main() {
    int tc = 0;
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c)) {
        printf("Sequence %d\n", ++tc);
        testCase(a, b, c);
        printf("\n");
    }
}
