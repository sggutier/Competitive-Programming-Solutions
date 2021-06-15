#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int nums[limN];
int ord[limN];
int A[limN], B[limN];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        ord[i] = i;
    }
    sort(ord, ord+N,
         [] (const int a, const int b) {
             return nums[a] < nums[b];  });

    int N3 = N/3 + N%3;
    for(int i=0, p; i<N; i++) {
        p = ord[i];
        int &s = nums[p], &a = A[p], &b = B[p];
        if(i < N3)
            a = i, b = s-i;
        else if(N3 <= i && i < 2*N3)
            b = i, a = s-i;
        else {
            b = (N-1) - i;
            a = s-b;
        }
    }

    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
    for(int i=0; i<N; i++)
        printf("%d ", B[i]);
    printf("\n");
}
