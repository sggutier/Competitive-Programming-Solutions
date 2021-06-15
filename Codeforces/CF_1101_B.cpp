#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int limN = 5e5 + 5;

char str[limN];
int dp[5] = {-inf, -inf, -inf, -inf, -inf};

int main() {


    fgets(str, limN, stdin);
    for(char *c = str; *c != '\n'; c++) {
        if(*c == '[')
            dp[0] = 1;
        else if(*c == ':') {
            dp[3] = max(dp[3], dp[1] + 1);
            dp[3] = max(dp[3], dp[2] + 1);
            dp[1] = max(dp[1], dp[0] + 1);
        }
        else if(*c == '|') {
            dp[2] = max(dp[2], dp[2] + 1);
            dp[2] = max(dp[2], dp[1] + 1);
        }
        else if(*c == ']')
            dp[4] = max(dp[4], dp[3] + 1);
    }

    printf("%d\n", max(-1, dp[4]));
}
