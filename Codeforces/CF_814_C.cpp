#include <bits/stdc++.h>
using namespace std;
const int limN = 2000;

int minCst[26][limN];

int main() {
    int N, Q;
    char str[limN];

    scanf("%d", &N);
    for(int i=0; i<26; i++) {
        for(int j=0; j<=N; j++)
            minCst[i][j] = j;
    }    
    scanf("%s", str);
    for(int i=0; i<N; i++) {
        for(int t=str[i]-'a', c=0, j=i; j<N; j++) {
            if(str[j]-'a'!=t)
                c++;
            minCst[t][j-i+1] = min(minCst[t][j-i+1], c);
        }
    }
    for(int i=0; i<26; i++)
        for(int j=1; j<=N; j++)
            minCst[i][j] = min(minCst[i][j], minCst[i][j-1] + 1);

    scanf("%d", &Q);
    while(Q--) {
        int a ;
        scanf("%d%s" ,&a, str);
        int t = str[0]-'a';
        printf("%d\n", (int) (upper_bound(minCst[t], minCst[t]+N+1, a) - minCst[t]) - 1);
    }
}
