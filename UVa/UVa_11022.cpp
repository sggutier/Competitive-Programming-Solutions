#include <bits/stdc++.h>
using namespace std;
const int limN = 80;

string str;
bool usd[limN][limN];
int minWMemo[limN][limN];

int minW(int ini, int fin) {
    if(usd[ini][fin])
        return minWMemo[ini][fin];
    usd[ini][fin] = true;
    if(ini==fin) {
        return minWMemo[ini][fin] = 1;
    }
    int n = fin-ini+1;
    int ans = (1<<30);
    for(int i=1; i<n; i++) {
        ans = min(ans, minW(ini, ini+i-1) + minW(ini+i, fin));
        if(n%i)
            continue;
        string tmp = str.substr(ini, i);
        bool works = true;
        for(int j=i; j<n; j+=i) {
            if(str.substr(ini+j, i) != tmp) {
                works = false;
                break;
            }
        }
        if(works)
            ans = min(ans, minW(ini, ini+i-1));
    }
    return minWMemo[ini][fin] = ans;
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    printf("%d\n", minW(0, str.size()-1));
}

int main() {
    char tmp[limN+20];
    while(scanf("%s", tmp)!=EOF && tmp[0]!='*') {
        str = tmp;
        testCase();
    }
}
