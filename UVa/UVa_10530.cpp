#include <bits/stdc++.h>
using namespace std;

bool testCase(int n) {
    char str[10];
    int ini = 1, fin = 10;
    bool funca = true;
    while(true) {
        scanf("%s", str);
        if(str[0]=='r') {
            scanf("%s", str);
            return funca && ini <= n && n <=fin;
        }
        scanf("%s", str);
        if(str[0]=='l') {
            ini = max(ini, n+1);
            if(ini > fin) funca = false;
        }
        else {
            fin = min(fin, n-1);
            if(ini > fin) funca = false;
        }
        scanf("%d", &n);
    }
    return true;
}

int main() {
    int n ;
    while(scanf("%d", &n)!=EOF && n)
        printf("%s\n", testCase(n)? "Stan may be honest" : "Stan is dishonest");
}
