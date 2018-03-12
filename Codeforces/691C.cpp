#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char str[limN];

int main() {
    int up=-1, pp=-1, lp=-1;
    fgets(str, limN, stdin);
    for(int i=0; str[i]; i++) {
        if(isdigit(str[i]) && str[i]!='0') {
            if(up==-1)
                up = i;
            lp = i;
        }
    }
    for(int i=0; str[i]; i++) {
        if(!isdigit(str[i])) {
            pp = i;
            break;
        }
    }
    if(up==-1) {
        printf("0\n");
        return 0;
    }
    printf("%c", str[up]);
    if(lp != up)
        printf(".");
    for(int i=up+1; i<=lp; i++) {
        if(isdigit(str[i]))
            printf("%c", str[i]);
    }
    if(up+1!=pp)
        printf("E%d", pp-up + (pp>up? -1 : 0));
    printf("\n");
}
