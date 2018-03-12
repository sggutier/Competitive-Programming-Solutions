#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int *x=NULL, int *y=NULL) {
    if(b==0) {
        if(x)
            *x = 1, *y=0;
        return a;
    }
    int d = gcd(b,a%b,x,y);
    if(x) {
        int x2 = *y, y2 = *x - *y*(a/b);
        *x = x2, *y = y2;
    }
    return d;
}

void testCase(int N) {
    pair <int,int> A, B;
    scanf("%d%d", &A.first, &A.second);
    scanf("%d%d", &B.first, &B.second);
    long long a, b;
    long long x, y;
    int d = gcd(A.second,B.second,(int*) &a, (int*) &b);
    x = (int) a, y = (int) b;
    if(N%d) {
        printf("failed\n");
        return;
    }
    long long ans = (1LL<<62);
    long long ansX=0, ansY=0;
    bool revo = false;
    x *= N/d;
    y *= N/d;
    //printf("%lld %lld\n", x, y);
    if(x>y) {
        swap(x, y);
        swap(A, B);
        revo = true;
    }
    a = B.second/d;
    b = A.second/d;
    //printf("%lld %lld\n", a, b);
    long long sum;
    sum = y/b;
    if(x + a*sum>=0) {
        long long tot = (x + a*sum)*A.first + (y - b*sum)*B.first;
        if(ans>tot) {
            ans = tot;
            ansX = (x + a*sum);
            ansY = (y - b*sum);
        }
    }
    if(x>=0) {
        sum = x/a;
        if(y + b*sum>=0) {
            long long tot = (x - a*sum)*A.first + (y + b*sum)*B.first;
            if(ans>tot) {
                ans = tot;
                ansX = (x - a*sum);
                ansY = (y + b*sum);
            }
        }
    }
    else {        
        sum = -x/a + (-x%a? 1 : 0);
        if(y - b*sum>=0) {            
            long long tot = (x + a*sum)*A.first + (y - b*sum)*B.first;
            if(ans>tot) {
                ans = tot;
                ansX = (x + a*sum);
                ansY = (y - b*sum);
            }
        }
    }
    if(revo)
        swap(ansX, ansY);
    if(ans==(1LL<<62))
        printf("failed\n");
    else
        printf("%lld %lld\n", ansX, ansY);
}

int main() {
    int N;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
}
