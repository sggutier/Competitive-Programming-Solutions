#include <bits/stdc++.h>
using namespace std;

void testCase(const int &n) {
    bool leap = n%400==0 || (n%100!=0 && n%4==0);
    bool hulu = n%15==0;
    bool bulu = leap && n%55==0;

    if(leap)
        printf("This is leap year.\n");
    if(hulu)
        printf("This is huluculu festival year.\n");
    if(bulu)
        printf("This is bulukulu festival year.\n");
    if(!leap && !hulu && !bulu)
        printf("This is an ordinary year.\n");
}

int main() {
    int n;
    int tc = 0 ;
    while(scanf("%d", &n)!=EOF) {
        if(tc++)
            printf("\n");
        
        testCase(n);
    }
}
