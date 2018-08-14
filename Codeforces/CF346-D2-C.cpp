#include <bits/stdc++.h>
using namespace std ;
const int limN = 1e6 + 5;
#define f first
#define s second

int N;
int mods[limN];
int divs[limN];
int ans[limN], ua[limN];
set <int> w ;

int main() {
    int a, b ;
    scanf("%d", &N);
    for(int i=0, k; i<N; i++) {
        scanf("%d", &k);
        if(k > 1)
            w.insert(k);        
    }
    scanf("%d%d", &a, &b);

    N = 0;
    for(int x : w) {
        mods[++N] = x;
        for(int k=b + (x - b%x)%x; k<=a; k+=x)
            divs[k-b] = N;
    }

    set < pair<int,int> > Q ;
    if(divs[0]) {
        Q.insert({b, divs[0]});
        ua[divs[0]] = b;
    }
    for(int k=b+1; k<=a; k++) {
        ans[k-b] = ans[k-b-1] + 1;
        if(divs[k-b])
            Q.erase({ua[divs[k-b]], divs[k-b]});
        while(!Q.empty() && Q.begin()->f <= k - mods[Q.begin()->s])
            Q.erase(Q.begin());
        if(!Q.empty()) {
            ans[k-b] = ans[Q.begin()->f - b] + 1;
            // printf("\tvd %d %d || %d\n", Q.begin()->f, mods[Q.begin()->s], ans[Q.begin()->f - b] + 1);
        }
        if(divs[k-b]) {
            ua[divs[k-b]] = k;
            Q.insert({k, divs[k-b]});
        }
        // printf("%d => %d\n", k, ans[k-b]);
    }

    printf("%d\n", ans[a-b]);
}
