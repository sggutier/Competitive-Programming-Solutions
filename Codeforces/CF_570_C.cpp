#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;

int main() {
    int N, Q;
    set <int> lets;
    char str[limN];
    int crg = 0;

    scanf("%d%d", &N, &Q);
    scanf("%s", str);
    lets.insert(-1);
    for(int i=0, u=-1; i<=N; i++) {
        if(str[i]=='.')
            continue;
        crg += max(i-u-2, 0);
        u = i;
        lets.insert(i);
    }
    while(Q--) {
        int a;
        char tmp[5];
        scanf("%d%s", &a, tmp);
        a--;
        if(str[a]=='.' && tmp[0]!='.') {
            auto it = lets.lower_bound(a);
            int x, y = *it;
            it--;
            x = *it;
            //printf("%d %d %d\n", x, a, y);
            crg -= max(0, y-x-2);
            crg += max(0, a-x-2) + max(0, y-a-2);
            lets.insert(a);
        }
        else if(str[a]!='.' && tmp[0]=='.') {
            lets.erase(a);
            auto it = lets.lower_bound(a);
            int x, y = *it;
            it--;
            x = *it;
            //printf("%d %d %d\n", x, a, y);
            crg -= max(0, a-x-2) + max(0, y-a-2);
            crg += max(0, y-x-2);
        }
        str[a] = tmp[0];
        printf("%d\n", crg);
    }
}
