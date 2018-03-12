#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;

void kmpPreprocess(char *S, int n, int *retro) {
    int i=0, j=-1;
    retro[0] = -1;
    // cout << n << endl;
    while(i<n) {
        // printf("%c %d %d -> ", S[i], i, j);
        while(j!=-1 && S[i]!=S[j])
            j = retro[j];
        // printf("%d\n", j);
        i++; j++;
        retro[i] = j;
    }
    /* printf(" %s\n", S);
    for(int i=0; i<n; i++)
        printf("%d", retro[i]%10);
        printf("\n");*/ 
        
}

void testCase(char *S) {
    int n = strlen(S);
    char rev[n+5];
    int retro[n+5];
    int i, j;

    strcpy(rev, S);
    reverse(rev, rev+n);
    // cout << n << endl;
    kmpPreprocess(rev, n, retro);

    /*printf("--> %s\n", rev);
    for(int i=0; i<n; i++)
        printf("%d", retro[i]%10);
        printf("\n");*/

    i=0; j=0;
    while(i<n) {
        //printf("%d %d -> %c %c\n", i, j, S[i], rev[j]);
        while(j!=-1 && S[i]!=rev[j])
            j = retro[j];
        i++; j++;        
    }

    printf("%s%s\n", S, rev+j);
    // cout << j << endl;
}

int main() {
    char S[maxN];

    while(scanf("%s", S)!=EOF)
        testCase(S);
    
    return 0;
}
