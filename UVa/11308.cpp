#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

void testCase() {
    char lin[limN], rn[limN], gte[limN];
    int N, R, B;
    map <string, int> ings;
    set < pair<int, string> > recs;
    
    gets(lin);
    for(char *c=lin; *c; c++)
        printf("%c", toupper(*c));
    printf("\n");
    gets(lin);
    sscanf(lin, "%d %d %d", &N, &R, &B);
    for(int i=0; i<N; i++) {
        int a ;
        gets(lin);
        sscanf(lin, "%s %d", gte, &a);
        ings[gte] = a;
    }
    for(int i=0; i<R; i++) {
        gets(rn);
        int W, cto = 0 ;
        gets(lin);
        sscanf(lin, "%d", &W);
        // printf("=> %s %d\n", rn, W);
        for(int j=0, a=0; j<W; j++) {
            gets(lin);
            sscanf(lin, "%s %d", gte, &a);
            // printf("=> %s %d\n", gte, a);
            cto += a*ings[gte];
        }
        if(cto <= B)
            recs.insert({cto, rn});
    }

    if(recs.empty())
        printf("Too expensive!\n");
    for(auto &p:recs)
        printf("%s\n", p.second.c_str());
}

int main() {
    char tmp[limN];
    int N;
    gets(tmp);
    N = atoi(tmp);
    for(int tc=0; tc<N; tc++) {
        N = atoi(tmp);
        testCase();
        printf("\n");
    }
}
