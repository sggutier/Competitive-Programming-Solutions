#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4;

char S[MAX_N];
char *s;

double evExpr() {
    if(*s=='(') {
        double p, x, y;
        sscanf((++s), "%lf", &p);
        while(*s!=' ') s++;
        do {
            s++;
        }while(*s==' ');
        x = evExpr();
        do {
            s++;
        }while(*s==' ');
        y = evExpr();
        s++;
        return p*(x+y) + (1-p)*(x-y);
    }
    else {
        int ans = 0;
        int sgn = 1;
        if(*s=='-') {
            s++;
            sgn *= -1;
        }
        while(isdigit(*s)) {
            ans = ans*10 + *s-'0';
            s++;
        }
        return ans*sgn;
    }
}

int main() {
    while(gets(S) && S[1]!=')') {
        s = S;
        printf("%.2lf\n", evExpr());
    }
}
