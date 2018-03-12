#include <bits/stdc++.h>
using namespace std;

bool nextStro(char *s) {
    char tmp ;
    while(scanf("%c", &tmp)!=EOF && !isalpha(tmp)) ;
    *(s++) = tmp;
    while(scanf("%c", &tmp)!=EOF && tmp!=' ' && tmp!='\n') {
        *(s++) = tmp;
    }
    
    *(s++) = 0;
    return tmp==' ';
}

int nodCnt = 0;
int dict[300];
char revDict[300];
list <int> adj[300];
int parentCnt[300];
char ans[300];

bool bruta(int pos) {
    if(pos==nodCnt) {
        printf("%s\n", ans);
        return true;
    }
    bool ansB = false;
    for(int i=0; i<nodCnt; i++) {
        if(parentCnt[i])
            continue;
        parentCnt[i] --;
        ans[2*pos] = revDict[i];
        for(const int &sig:adj[i])
            parentCnt[sig] --;
        if(!bruta(pos+1))
            break;
        ansB = true;
        parentCnt[i] ++;
        for(const int &sig:adj[i])
            parentCnt[sig] ++;
    }
    return ansB;
}

void testCase() {
    char S[300];
    set <char> lets;

    nodCnt = 0;
    while(true) {
        bool nxt = nextStro(S);
        lets.insert(S[0]);
        if(!nxt)
            break;
    }
    for(const char &let:lets) {        
        dict[(int) let] = nodCnt;
        revDict[nodCnt] = let;
        adj[nodCnt].clear();
        parentCnt[nodCnt] = 0;
        nodCnt++;
    }
    while(true) {
        bool nxt = nextStro(S);
        int a = dict[(int) S[0]], b = dict[(int) S[2]];
        adj[a].push_back(b);
        parentCnt[b] ++;
        if(!nxt)
            break;
    }
    for(int i=2*nodCnt-1; i>=0; i--)
        ans[i] = ' ';
    ans[2*nodCnt-1] = 0;

    if(!bruta(0))
        printf("NO\n");
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
