#include <bits/stdc++.h>
using namespace std;

char revo[300];

void testCase(char *S) {
    int cnt = 0;
    stack <char> abr;
    while(*S) {
        int c ;
        cnt ++;
        if(*S=='(' && *(S+1)=='*') {
            c = '*';
            S += 2;
        }
        else if(*S=='*' && *(S+1)==')') {
            c = '#';
            S += 2;
        }
        else {
            c = *S;
            if(c=='*' || c=='#')
                c = 0;
            S ++;
        }
        // printf("%c", c);
        if(!revo[c])
            continue;
        if(revo[c]!='+')
            abr.push(revo[c]);
        else {
            //printf("Closing %c\n", c);
            if(abr.empty() || abr.top()!=c) {
                printf("NO %d\n", cnt);
                return;
            }
            abr.pop();
        }
    }
    if(!abr.empty())
        printf("NO %d\n", cnt+1);
    else
        printf("YES\n");
}

int main() {
    revo['['] = ']';
    revo['('] = ')';
    revo['{'] = '}';
    revo['<'] = '>';
    revo['*'] = '#';
    revo[']'] = '+';
    revo[')'] = '+';
    revo['}'] = '+';
    revo['>'] = '+';
    revo['#'] = '+';
    char S[5000];
    while(gets(S))
        testCase(S);
}
