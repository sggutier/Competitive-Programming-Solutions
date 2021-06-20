#include <bits/stdc++.h>
using namespace std;
const int limN = 26;

int reqT[limN];
int minT[limN];
list <int> adj[limN];
int deg[limN];

void testCase() {
    for(int i=0; i<limN; i++) {
        reqT[i] = 0;
        minT[i] = 0;
        adj[i].clear();
        deg[i] = 0;
    }
    
    char str[50];
    while(gets(str) && str[0]) {
        char A[30], B[30];
        B[0] = 0;
        int T;
        sscanf(str, "%s%d%s", A, &T, B);
        reqT[A[0]-'A'] = T;
        for(int i=0; B[i]; i++) {
            deg[A[0]-'A']++;
            adj[B[i]-'A'].push_back(A[0]-'A');
        }
    }

    int ans = 0;
    queue <int> Q;
    for(int i=0; i<limN; i++)  {
        if(!deg[i]) {
            Q.push(i);
        }
    }
    
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        minT[pos] += reqT[pos];
        ans = max(ans, minT[pos]);
        //printf("%c => %d\n", pos+'A', minT[pos]);
        for(const int &sig:adj[pos]) {
            minT[sig] = max(minT[sig], minT[pos]);
            deg[sig] --;
            if(!deg[sig])
                Q.push(sig);
        }
    }

    printf("%d\n", ans);
}

int main() {
    int tc;
    char str[50];
    gets(str);
    sscanf(str, "%d", &tc);
    gets(str);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
