#include <bits/stdc++.h>
using namespace std;


bool testCase(char *S) {
    int a=0, b=0, c=0;
    if(*S!='?')
        return false;
    while(*S && *S=='?') {S++, a++;}
    if(*S!='M')
        return false;
    S++;
    if(*S!='?')
        return false;
    while(*S && *S=='?') {S++, b++;}
    if(*S!='E')
        return false;
    S++;
    if(*S!='?')
        return false;
    while(*S && *S=='?') {S++, c++;};
    if( *S!=0 )
        return false;
    return c-b==a;
}

int main() {
    char str[5000];
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s", str);
        printf("%s\n", testCase(str)? "theorem" : "no-theorem");
    }
}
