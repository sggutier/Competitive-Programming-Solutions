#include <bits/stdc++.h>
using namespace std;

int toN(char *s) {
    int ans = 0;
    while(*s) {
        ans = ans*4 + (*s=='V'? 0 : *s=='U'? 1 : *s=='C'? 2 : 3);
        s++;
    }
    return ans;
}

void testCase() {
    char str[500];
    int a, b;

    gets(str);
    a = toN(str);
    gets(str);
    b = toN(str);

    for(int i=0; i<3; i++) {
        gets(str);
        if(str[0]=='A')
            b += a;
        else if(str[0]=='L')
            b *= 4;
        else if(str[0]=='R')
            b /= 4;
    }

    gets(str);
    a = toN(str);

    printf("%s\n", a==b? "YES" : "NO");
}

int main() {
    int tc;
    char str[50];

    gets(str);
    sscanf(str, "%d", &tc);
    printf("COWCULATIONS OUTPUT\n");
    while(tc--) {
        testCase();
    }
    printf("END OF OUTPUT\n");
}
