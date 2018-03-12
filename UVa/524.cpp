#include <bits/stdc++.h>
using namespace std;
const int limP = 17*2;

bool isPrime[limP];

void testCase(int *arr, bool *usd, int pos, const int &n) {
    if(pos==n) {
        if(!isPrime[arr[n-1]+arr[0]])
            return ;
        for(int i=0; i<n; i++) {
            if(i)
                printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
        return ;
    }    
    for(int i=2; i<=n; i++) {
        if(usd[i] || !isPrime[i+arr[pos-1]])
            continue ;
        usd[i] = true ;
        arr[pos] = i;
        testCase(arr, usd, pos+1, n);
        usd[i] = false;
    }
}

int main() {
    isPrime[2] = isPrime[3] = isPrime[5] = true ;
    for(int i=7; i<limP; i++) {
        isPrime[i] = (i%2!=0) && (i%3!=0) && (i%5!=0);
    }

    int tc = 1, n;
    bool usd[limP];
    int arr[limP];
    arr[0] = 1;
    usd[1] = true ;
    memset(usd, 0, sizeof(usd));
    while(scanf("%d", &n)!=EOF) {
        if(tc>1)
            printf("\n");
        printf("Case %d:\n", tc++);
        testCase(arr, usd, 1, n);
    }
    
    return 0;
}
