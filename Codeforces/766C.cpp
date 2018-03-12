#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
const int limC = 26;
const int mod = 1e9 + 7;

int N ;
char str[limN];
int cnt[26];
int ways[limN];
int maxStr[limN], minStr[limN];

int main() {
    scanf("%d", &N);
    scanf("%s", str);
    for(int i=0; i<limC; i++)
        scanf("%d", &cnt[i]);

    ways[N] = 1;
    maxStr[N] = 0;
    minStr[N] = 0;
    for(int i=N-1; i>=0; i--) {
        int tots[26];
        int j = i;
        bool funca = true;
        maxStr[i] = 0;
        minStr[i] = 1e9;
        memset(tots, 0, sizeof(tots));
        for(char *c=str+i; j<N; c++, j++) {
            tots[*c-'a'] = true;
            for(int t=0; t<limC; t++) {
                if(tots[t] && j-i+1 > cnt[t]) {
                    funca = false;
                    break;
                }
            }
            if(!funca)
                break;
            ways[i] = (ways[i] + ways[j+1]) % mod;
            minStr[i] = min(minStr[i], minStr[j+1] + 1);
            maxStr[i] = max(maxStr[i], max(maxStr[j+1], j-i+1));
            // printf("%d %d\n", i, j);
        }
        // printf("%d => %d %d %d\n", i, ways[i], minStr[i], maxStr[i]);
    }

    printf("%d\n", ways[0]);
    printf("%d\n", maxStr[0]);
    printf("%d\n", minStr[0]);
}
