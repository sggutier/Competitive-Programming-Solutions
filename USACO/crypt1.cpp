/*
ID: me60
LANG: C++11
TASK: crypt1
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

bool usaDigitos(const set<int> &digs, int digsEsp, int num)  {
    bool funca = true;
    int d = 0;
    while(num) {
        if(digs.count(num%10)==0) {
            funca = false;
            break ;
        }
        num /= 10;
        d ++;
    }
    return funca && d==digsEsp;
}

int busca(const int &n, const set<int> &digs, int num, int cnt) {
    if(cnt==5) {
        int a = num%100, b = num/100;
        int funca = usaDigitos(digs, 4, a*b) && usaDigitos(digs, 3, (a/10)*b) && usaDigitos(digs, 3, (a%10)*b);
        return funca;
    }
    int ans = 0;
    for(int d: digs) {
        ans += busca(n, digs, num*10 + d, cnt+1);
    }
    return ans ;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int n;
    set <int> digs;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int k ;
        scanf("%d", &k);
        digs.insert(k);
    }

    printf("%d\n", busca(n, digs, 0, 0));

    return 0;
}
