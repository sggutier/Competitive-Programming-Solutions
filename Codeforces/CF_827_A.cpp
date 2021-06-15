#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef pair<int,int> par;
#define f first
#define s second

string strs[limN];
par crgs[2*limN];
char tmp[limN];

int main() {
    int N;
    int fp = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int Q, a, L;
        scanf("%s", tmp);
        strs[i] = tmp;
        L = strs[i].size();
        scanf("%d", &Q);
        for(int j=0; j<Q; j++) {
            scanf("%d", &a); a--;
            crgs[a] = max(crgs[a], par(L, i));
            fp = max(fp, a+L);
        }
    }
    par C ;
    for(int i=0; i<fp; i++) {
        C = max(C, crgs[i]);
        printf("%c", C.f > 0? strs[C.s][strs[C.s].size()-C.f] : 'a');
        C.f--;
    }
    printf("\n");
}
