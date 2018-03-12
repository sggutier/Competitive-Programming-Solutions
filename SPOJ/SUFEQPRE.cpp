#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char S[limN];
int prevo[limN];

int testCase() {
    int i=-1, j=0;
    prevo[0] = -1;
    while(S[j]) {
        while(i!=-1 && S[i]!=S[j])
            i = prevo[i];
        i++, j++;
        prevo[j] = i;
        // printf("%d ", i);
    }
    // printf("\n");
    int ans = 0, u=j-1;
    // printf("%c %c ", S[j-1], S[u]);
    while(j!=0 && S[j-1]==S[u]) {
        // printf("%d ", j);
        j = prevo[j];
        ans ++;
    }
    // printf("\n");
    return ans-1;
}

int main() {
    int tc;
    // fgets(S, limN, stdin);
    scanf("%s", S);
    sscanf(S, "%d", &tc);
    for(int i=1; i<=tc; i++) {
        //fgets(S, limN, stdin);
        scanf("%s", S);
        printf("Case %d: %d\n", i, testCase());
    }
}
