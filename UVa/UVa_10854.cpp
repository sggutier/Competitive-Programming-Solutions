#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;

char tmp[20];

ll ifWays() ;
ll proWays() ;

ll ifWays() {
    return proWays()+proWays();
}

ll proWays() {
    ll ans = 1;
    while(true) {
        gets(tmp);
        if(*tmp=='E')
            break;
        else if(*tmp=='I')
            ans *= ifWays();
    }
    return ans;
}

void testCase() {
    printf("%u\n", proWays());
}

int main() {
    int tc;
    gets(tmp);
    tc = atoi(tmp);
    while(tc--)
        testCase();
}
