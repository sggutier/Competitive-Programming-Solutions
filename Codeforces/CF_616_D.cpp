#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N, K ;
int arr[limN];
int reps[limN];

pair<int,int> funca(int L) {
    memset(reps, 0, sizeof(reps));
    for(int i=1, tips=0; i<=N; i++) {
        if( (reps[arr[i]]++) == 0)
            tips ++;
        if( i > L && (--reps[arr[i-L]]) == 0)
            tips --;
        if(i >= L && tips <= K)
            return {i-L+1, i};
    }
    return {-1, -1};
}

int main() {
    int ini, fin;

    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    ini = 1, fin = N;
    while(ini < fin) {
        int piv = (ini+fin)/2 + 1;
        if(funca(piv) == make_pair(-1, -1))
            fin = piv-1;
        else
            ini = piv;
    }

    pair<int,int> ans = funca(ini);
    printf("%d %d\n", ans.first, ans.second);
}
