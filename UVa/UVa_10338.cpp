#include <bits/stdc++.h>
using namespace std;
const int limN = 21;
typedef long long ll;

ll facts[21];

void precarga() {
    facts[0] = 1;
    for(int i=1; i<limN; i++)
        facts[i] = facts[i-1]*i;
}

ll testCase() {
    ll ans = 0LL;
    map <char, int> cnt;
    char str[50];
    int len = 0;
    scanf("%s", str);
    for(char *c=str; *c; c++, len++)
        cnt[*c]++;
    ans = facts[len];
    for(const auto &p:cnt)
        ans /= facts[p.second];
    return ans;
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        printf("Data set %d: %lld\n", i, testCase());
}
