#include <bits/stdc++.h>
using namespace std;

int main() {
    double ro2 = sqrt(2.0);
    int tc;
    int n;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d", &n);
        if(i)
            printf("\n");
        if(n==1)
            printf("0.000\n");
        else if(n==2)
            printf("4.000\n");
        else
            printf("%.3lf\n", 4*(n-1) + (n*n - 4*(n-1))*ro2);
    }
}
