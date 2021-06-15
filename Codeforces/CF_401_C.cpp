#include <bits/stdc++.h>
using namespace std;
const int limN = 2e6 + 5;

char str[limN];

bool funcaA(int a, int b) {
    if(a < b || a > 2*(b+1))
        return false;
    char *s = str;
    while(a) {
        *(s++) = '1'; a--;
        if(a > b) {
            *(s++) = '1'; a--;
        }
        if(b) {
            *(s++) = '0'; b--;
        }
    }
    return true;
}

bool funcaB(int a, int b) {
    if(a+1 < b || a > 2*(b-1))
        return false;
    char *s = str;
    while(b) {
        *(s++) = '0'; b--;
        if(a) {
            *(s++) = '1'; a--;
            if(a >= b) {
                *(s++) = '1'; a--;
            }
        }
    }
    return true;
}

int main() {
    int a, b ;
    scanf("%d%d", &b, &a);
    if(!funcaA(a, b) && !funcaB(a, b))
        printf("-1\n");
    else
        printf("%s\n", str);
}
