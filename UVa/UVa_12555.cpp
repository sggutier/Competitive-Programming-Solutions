#include <bits/stdc++.h>
using namespace std;

int procesa(char *s) {
    int x = 0, y = 0;
    while(isdigit(*s)) {
        x = x*10 + (*s)-'0';
        s ++;
    }
    while(!isdigit(*s))
        s++;
    while(isdigit(*s)) {
        y = y*10 + (*s)-'0';
        s ++;
    }
    return x*50 + y*5;
}

int main() {
    char lin[500];
    fgets(lin, 500, stdin);
    int n ;
    n = atoi(lin);
    for(int tc=1; tc<=n; tc++) {
        fgets(lin, 500, stdin);
        int ans = procesa(lin);
        if (ans % 10 != 0)
            printf("Case %d: %d.%d%d\n", tc, ans/100, (ans/10)%10, ans%10);
        else if ( (ans/10) % 10 != 0)
            printf("Case %d: %d.%d\n", tc, ans/100, (ans/10)%10);
        else
            printf("Case %d: %d\n", tc, ans/100);
    }
}
