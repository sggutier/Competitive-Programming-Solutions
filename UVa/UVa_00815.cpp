#include <bits/stdc++.h>
using namespace std;

void testCase(int N, int M) {
    N *= M;
    double W ;
    int arr[1000];
    int c = 1;

    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    scanf("%lf", &W);

    sort(arr, arr+N);
    W /= 100.0;
    for(c=1; c<N; c++) {
        if((arr[c]-arr[c-1])*c <= W)
            W -= (arr[c]-arr[c-1])*c;
        else
            break;
    }

    printf("Water level is %.2lf meters.\n", arr[c-1]+W/c);
    printf("%.2lf percent of the region is under water.\n", (100.0*c)/N);
}

int main() {
    int a, b;
    int tc = 0;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Region %d\n", ++tc);
        testCase(a, b);
        printf("\n");
    }
}

