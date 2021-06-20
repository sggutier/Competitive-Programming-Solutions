#include <bits/stdc++.h>
using namespace std;

bool testCase() {
    char S[1005];
    int cnt[3] = {0, 0, 0};
    int sum = 0;
    scanf("%s", S);
    for(char *s=S; *s; s++) {
        cnt[(*s-'0')%3]++;
        sum = (sum+(*s-'0'))%3;
    }
    if(!cnt[sum])
        return false;
    cnt[sum] --;
    return (cnt[0]+1)%2;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %c\n", i, testCase()? 'S' : 'T');
    }
}
