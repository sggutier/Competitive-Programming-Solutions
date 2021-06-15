#include <bits/stdc++.h>
using namespace std;

int main() {
    char S[1005];
    int lets[] = {'V', 'K'};
    int n ;
    int ans = 0 ;

    scanf("%s", S);
    n = strlen(S);
    for(int i=0; i<n; i++) {
        int org = S[i];
        for(int j=0; j<2; j++) {
            S[i] = lets[j];
            int cnt = 0 ;
            for(int k=0; k+1<n; k++) {
                if(S[k]=='V' && S[k+1]=='K')
                    cnt ++ ;
            }
            ans = max(ans, cnt);
        }
        S[i] = org;
    }

    printf("%d\n", ans) ;
    
    return 0 ;
}
