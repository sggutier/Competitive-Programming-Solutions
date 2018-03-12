#include <bits/stdc++.h>
using namespace std;

int testCase(int n) {
    if(n <= 11) {
        if(n >= 4 && n%2==0)
            return n/4;
        else if(n==9)
            return 1;
        else
            return -1;
    }
    switch(n%4) {
    case 0:
        return n/4;
    case 1:
        return (n-9)/4 + 1;
    case 2:
        return (n-6)/4 + 1;
    default:
        return (n-15)/4 + 2;
    }
}

int main() {
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        printf("%d\n", testCase(n));
    }
}
