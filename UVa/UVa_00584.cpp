#include <bits/stdc++.h>
using namespace std;

int vals[300];

void testCase(char *s) {
    int ans = 0;

    for(int i=0; i<10; i++) {
        //printf("%c [%d => ", *s, ans);
        if(*s=='X') {
            int sg = (int) *(s+4);
            ans += 10 + (sg!='/'? vals[(int) *(s+2)] + vals[sg] : 10);
            //ans += 10 + vals[(int) *(s+2)] + vals[sg] ;
        }
        else {
            if(*(s+2)=='/') {
                s += 2;
                ans += 10 + vals[(int) *(s+2)];
            }
            else {
                //printf("hirino\n");
                ans += *s-'0' + *(s+2) - '0' ;
                s += 2;
            }
        }
        //printf("%d]\n", ans);
        s += 2;
    }

    printf("%d\n", ans);
}

    
char lin[500];

int main() {
    for(int i='0'; i<='9'; i++)
        vals[i] = i-'0';
    vals['X'] = vals['/'] = 10;

    while(fgets(lin, 500, stdin) && lin[0]!='G')
        testCase(lin);
}
