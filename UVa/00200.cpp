#include <bits/stdc++.h>
using namespace std;
const int limC = 30;

bool usd[limC];
int cnt[limC];
int adj[limC][limC];

void testCase(char *prev, char *cur) {
    memset(usd, 0, sizeof(usd));
    memset(cnt, 0, sizeof(cnt));
    memset(adj, 0, sizeof(adj));
    priority_queue <int> Q;
    for(char *c=prev; *c; c++)
        usd[*c-'A'] = true;
    while(gets(cur) && cur[0]!='#') {
        char *a=prev, *b=cur;

        while(*a==*b)
            a++, b++;

        if(*a && *b) {
            adj[*a - 'A'][*b - 'A'] ++;
            cnt[*b - 'A']++;
            //printf("%c antes de %c\n", *a, *b);
        }

        for(b=cur; *b; b++)
            usd[*b-'A'] = true;
        
        swap(cur, prev);
    }

    for(int i=0; i<limC; i++)
        if(usd[i] && cnt[i]==0)
            Q.push(-i);

    while(!Q.empty()) {
        int pos = -Q.top(); Q.pop();
        putchar(pos + 'A');
        //printf("%c => ", pos+'A');
        for(int i=0; i<limC; i++) {
            if(adj[pos][i]) {
                //printf("%c (%d %d)", i + 'A', cnt[i], adj[pos][i]);
                if(cnt[i]==adj[pos][i]) {
                    Q.push(-i);
                }
                cnt[i] -= adj[pos][i];
                adj[pos][i]-=adj[pos][i];
            }
        }
        //printf("\n");
    }
    putchar('\n');
}

int main() {
    char tmp[limC], cur[limC];
    while(    gets(tmp))
        testCase(tmp, cur);
}
