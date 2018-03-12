#include <bits/stdc++.h>
using namespace std;

void testCase(char *str) {
    vector <int> ss ;
    int n = strlen(str);
    int rem[300];
    memset(rem, 0, sizeof(rem));
    int ans = 0;

    for(int i=0; i<n; i++)
        rem[(int) str[i]] ++;

    for(int i=0; i<300; i++)
        if(rem[i])
            ans ++;

    for(int i=0; i<n; i++) {
        int c = str[i];
        int mino = 300, pMino;
        rem[c] --;
        for(int j=ss.size()-1; j>=0; j--) {
            if((ss[j]==c || (ss[j]>c) ) && ss[j]<mino) {
                mino = ss[j];
                pMino = j;
            }
        }
        if(mino==300)
            ss.push_back(c);
        else
            ss[pMino] = c;
        // for(int j=ss.size()-1; j>=0; j--)
        //     printf("%d ", ss[j]);
        // printf("\n");
    }

    printf("%d\n", min(ans, (int) ss.size()));
}

int main() {
    char S[1005];
    int tc = 0;

    while(scanf("%s", S)!=EOF && isupper(S[0])) {
        printf("Case %d: ", ++tc);
        testCase(S);
    }
    
    return 0;
}
