#include <bits/stdc++.h>
using namespace std;
const int limN = 15;
const int limB = (1<<limN);
const int inf = 1e9;

int arr[limB];
int sums[limB];

void testCase(int N) {
    int sum = 0, K = (1<<N);
    for(int i=0; i<K; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<K; i++) {
        for(int b=0; b<N; b++) {
            sum += arr[ i ^ (1<<b) ];
        }
        sums[i] = sum;
        sum = 0;
    }
    sum = -inf;
    for(int i=0; i<K; i++) {
        int tmp = sums[i ^ 1] ;
        for(int b=1; b<N; b++) {
            tmp = max(tmp, sums[ i ^ (1<<b) ]);
        }
        sum = max(sum, tmp + sums[i]);
    }
    printf("%d\n", sum);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
