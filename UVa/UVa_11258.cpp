#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 205;
const ll MAX_S = (1LL<<31);

void testCase() {
    char str[limN];
    ll maxS[limN];
    int n ;

    gets(str);
    n = strlen(str);
    maxS[n] = 0;

    for(int i=n-1; i>=0; i--) {
        ll sum = 0LL, ans = 0;
        for(int j=i; j<n; j++) {
            sum = sum*10 + str[j]-'0';
            if(sum>=MAX_S)
                break;
            ans = max(ans, sum + maxS[j+1]);
        }
        maxS[i] = ans;
    }

    printf("%lld\n", maxS[0]);
}

int main() {
    int tc;
    char tmp[10];
    gets(tmp);
    tc = atoi(tmp);
    while(tc--)
        testCase();
}
