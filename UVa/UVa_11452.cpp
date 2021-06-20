#include <bits/stdc++.h>
using namespace std;
const int limS = 2e3 + 5;

char str[limS];

void testCase() {
    gets(str);
    int N = strlen(str);
    int N3 = ceil(N/3.0);
    int ans = N3;

    for(int n2=N/2; n2>N3; n2--) {
        bool works = true;
        for(int i=n2; i<N; i++) {
            if(str[i]!=str[i%n2]) {
                works = false;
                break;
            }
        }
        if(works) {            
            ans = n2;
            break;
        }
    }

    for(int i=0; i<8; i++)
        putchar(str[(i+N)%ans]);
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('\n');
}

int main() {
    gets(str);
    int tc = atoi(str);

    while(tc--)
        testCase();
    
    return 0;
}
