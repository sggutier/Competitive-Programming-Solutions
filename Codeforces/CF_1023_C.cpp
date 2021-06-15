#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 2e5 + 5 ;

char str[limN];
int up[limN] ;

void getK(int l, int r, int k) {
    if(k == 0)
        return ;
    if(k == 2) {
        printf("()");
        return ;
    }
    int w = up[r] - 1, q = min(w-l+1, k-2);
    if(w < l) {
        printf("(");
        getK(l+1, r-1, k-2);
        printf(")");
        return ;
    }
    getK(l, w, q);
    getK(w+1, r, k - q);
}

int main() {
    int N, K ;
    scanf("%d%d", &N, &K);
    scanf("%s", str);
    N = strlen(str);

    stack <int> Q ;
    for(int i=0; i<N; i++) {
        if(str[i] == '(') {
            Q.push(i);
        }
        else {
            up[i] = Q.top();
            Q.pop();
        }
    }

    getK(0, N-1, K);
    
    printf("\n");
}
