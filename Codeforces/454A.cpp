#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    scanf("%d", &N);
    int k = N/2;
    for(int i=0; i<N; i++) {
        int d = k-abs(i-k);
        for(int j=0; j<N; j++) {
            printf("%c", (abs(j-k) <= d)? 'D' : '*');
        }
        printf("\n");
    }
}
