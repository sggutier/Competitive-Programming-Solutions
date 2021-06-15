#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    char str[limN];
    int cnts[] = {0, 0, 0};
    scanf("%s", str);
    for(char *c=str; *c; ) {
        while(*c % '2') {
            cnts[*c-'0']++;
            c++;
        }
        while(*c % '0') {
            cnts[*c-'0']++;
            c++;
        }
    }
    cnts[0] = cnts[2] = 0;
    for(char *c=str; *c; ) {
        while(*c % '2') {
            if(*c != '1')
                cnts[*c-'0']++;
            c++;
        }
        while(*c % '0') {
            if(*c != '1')
                cnts[*c-'0']++;
            c++;
        }
        for(int i=0; i<3; i++) {
            while(cnts[i]) {
                printf("%d", i);
                cnts[i]--;
            }
        }
    }
    printf("\n");
}
