#include <bits/stdc++.h>
using namespace std;

void testCase(int P, int Q) {
    map <string, int> dict;
    for(int i=0; i<P; i++) {
        char str[30];
        int a, b;
        scanf("%s %d.%d", str, &a, &b);
        dict[str] = a*10+b;
        //printf("=> %s %d\n", str, a*10+b);
    }
    for(int q=1; q<=Q; q++) {
        char str[30];
        int sumo = 0, cp;
        function <bool(int, int)> f ;
        while(true) {
            scanf("%s", str);
            if(str[0]=='<' && str[1]=='=' && str[2]==0) {
                f = [] (int a, int b) { return a<=b; };
                break;
            }
            else if(str[0]=='>' && str[1]=='=' && str[2]==0) {
                f = [] (int a, int b) { return a>=b; };
                break;
            }
            else if(str[0]=='='  && str[1]==0) {
                f = [] (int a, int b) { return a==b; };
                break;
            }
            else if(str[0]=='<' && str[1]==0) {
                f = [] (int a, int b) { return a<b; };
                break;
            }
            else if(str[0]=='>' && str[1]==0) {
                f = [] (int a, int b) { return a>b; };
                break;
            }
            else if(str[0]=='+' && str[1]==0) {}
            else
                sumo += dict[str];
        }
        scanf("%d", &cp);
        //printf("%d %d\n", sumo, cp*10);
        printf("Guess #%d was %scorrect.\n", q, f(sumo, cp*10)? "" : "in");
    }
}

int main() {
    int a, b ;
    scanf("%d%d", &a, &b);
    testCase(a,b);
}
